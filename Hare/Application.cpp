#include "Application.h"
#include "Level.h"
#include "Mouse.h"
#include "PlayState.h"
#include "EventHandler.h"
#include "Event.h"
#include "Debug.h"
#include "Timer.h"
#include "TextureManager.h"
#include "Keyboard.h"

#include <SDL_image.h>

//Static member definitions...
SDL_Event Application::event;
SDL_Renderer* Application::renderer = nullptr;
SDL_Window* Application::window = nullptr;
GameState Application::gameState = GameState::None;
Uint64 Application::ticks = 0;

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
    DEBUG_LOG << "DECONSTRUCT APPLICATION";

    state->~State();
    delete state;

    Events::EventHandler::DestroyQueue();
    TextureManager::DestroyQueue();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

#ifdef _CONSOLE
#ifdef _DEBUG
    std::cout << "Press \"Enter\" to exit..." << std::endl;
    std::cin.get();
#endif
#endif
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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    gameState = GameState::Running;
    state = new States::PlayState("Assets/Levels/Level-TestLong.json");
    state->Init();

    return 0;
}

void Application::Render()
{
    //Don't run SDL_RenderClear when minimized.
    if (SDL_GetWindowFlags(Application::GetWindow()) & SDL_WINDOW_MINIMIZED ? false : true)
        SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    if (SDL_GetWindowFlags(Application::GetWindow()) & SDL_WINDOW_MINIMIZED)
    {
        TextureManager::ClearQueue();
    }
    else
    {
        TextureManager::RenderQueue();
    }

    SDL_RenderPresent(renderer);
}

//Update method. Handles rendering, UI, and other things involving the window.
void Application::UpdateFixed()
{
    TextureManager::ClearQueue();

    //Game state handling.
    switch (gameState)
    {
    case GameState::Closing:
        return;
    case GameState::None:
        //TODO: Throw an exception here when state == GameState::None.
        break;
    }

    Events::EventHandler::UpdateEvents(&event);

    while (SDL_PollEvent(&event))
    {
        Keyboard::UpdateKeyboard(&event);
        Events::EventHandler::UpdatePollableEvents(&event);
        //Events relevant to how the application works go here.
        switch (event.type)
        {
        case SDL_QUIT:
            gameState = GameState::Closing;
            return;                     //Stop the update method and begin closing.
        }
    }

    state->UpdateFixed();
    
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
}

void Application::UpdatePhysics()
{
    if (state->hasPhysics)
    {
        state->UpdatePhysics();
    }
}

void Application::Update()
{
    //Game state handling.
    switch (gameState)
    {
    case GameState::Closing:
        return;
    case GameState::None:
        //TODO: Throw an exception here when state == GameState::None.
        break;
    }

    state->Update();
}
