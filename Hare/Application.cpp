#include "Application.h"
#include "Level.h"
#include "Mouse.h"
#include "PlayState.h"
#include "EventHandler.h"
#include "Event.h"
#include "Debug.h"
#include "Timer.h"

#include <SDL_image.h>

//Static member definitions...
SDL_Event Application::event;
SDL_Renderer* Application::renderer = nullptr;
SDL_Window* Application::window = nullptr;
GameState Application::gameState = GameState::None;

//Constructor for Application. Sets members from parameters.
Application::Application
(
    const char* title, 
    int windowWidth, 
    int windowHeight, 
    Uint32 flags, 
    int fps, 
    bool isCapped
)
    :windowTitle(title), windowWidth(windowWidth), windowHeight(windowHeight), flags(flags),
    isCapped(isCapped), state(nullptr)
{
    Timer::fps = fps;
}

//Deconstructor. Completely handles destruction for this object.
Application::~Application()
{
    Events::EventHandler::DestroyQueue();

    state->~State();
    delete state;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}

//Initialization method. Handles SDL2 initialization.
int Application::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        Debug::Error::ShowSDLMessageBox("SDL_Init has failed!");
        return -1;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        Debug::Error::ShowSDLMessageBox("IMG_Init has failed!");
        return -2;
    }

    window = SDL_CreateWindow
    (
        windowTitle,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowWidth,
        windowHeight,
        flags
    );

    renderer = SDL_CreateRenderer(window, -1, 0);

    gameState = GameState::Running;
    state = new States::PlayState("Assets/Levels/Level-TestComplex.json");
    state->Init();

    return 0;
}

//Update method. Handles rendering, UI, and other things involving the window.
void Application::Update()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    Mouse::UpdateMouse();
    //DEBUG_LOG_DEBUGONLY << MOUSE_X() << " : " << MOUSE_Y();

    //Game state handling.
    switch (gameState)
    {
    case GameState::Minimized:
        //TODO: Add minimize functionality.
        break;
    case GameState::Closing:
        return;
    case GameState::None:
        //TODO: Throw an exception here when state == GameState::None.
        break;
    }
    
    while (SDL_PollEvent(&event))
    {
        Events::EventHandler::UpdateEvents(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            gameState = GameState::Closing;
            return;                     //Stop the update method and begin closing.
        }
    }

    state->Update();
    
    for (Events::Event* event : Events::EventHandler::GetQueue())
    {
        event->ResetOnUpdate();
    }

    //State switching
    if (state->switchToState != States::StateID::NotSpecified
        && state->switchToState != state->stateID)
    {
        //Keep the desired state to switch in this scope and deconstruct the state pointer
        States::StateID switchToState = state->switchToState;
        delete state;

        Events::EventHandler::DestroyQueue();           //Destroy all events in event queue

        switch (switchToState)                          //Switch to desired state
        {
        case States::StateID::PlayState:                //If the states ID is "PlayState"...
            //Create a new PlayState
            state = new States::PlayState("Assets/Levels/Level-Test.json");
        }
        state->Init();
    }

    SDL_RenderPresent(renderer);
}