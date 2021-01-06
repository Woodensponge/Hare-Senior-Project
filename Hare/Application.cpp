#include "Application.h"
#include "Level.h"
#include "Mouse.h"
#include "PlayState.h"
#include "EventHandler.h"

#include <SDL_image.h>

//Static member definitions...
SDL_Event Application::event;
SDL_Renderer* Application::renderer = nullptr;
int Application::fps = 60;
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
{
    this->window = 0;
    this->renderer = 0;

    this->windowTitle = title;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->flags = flags;
    this->fps = fps;
    this->isCapped = isCapped;

    this->state = new States::State();
}

//Deconstructor. Completely handles destruction for this object.
Application::~Application()
{
    delete state;

    Events::EventHandler::DestroyQueue();

    IMG_Quit();
    SDL_Quit();
}

//Initialization method. Handles SDL2 initialization.
int Application::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        std::string errorMessage = "SDL_Init has failed! SDL_ERROR: ";
        errorMessage += SDL_GetError();
        std::cout << errorMessage << std::endl;
        SDL_ShowSimpleMessageBox(0, "Error", errorMessage.c_str(), window);

        return -1;
    }
    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::string errorMessage = "IMG_Init has failed! ERROR: ";
        errorMessage += SDL_GetError();
        std::cout << errorMessage << std::endl;
        SDL_ShowSimpleMessageBox(0, "Error", errorMessage.c_str(), window);

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
    state = new States::PlayState(window);
    state->Init();

    return 0;
}

//Update method. Handles rendering, UI, and other things involving the window.
void Application::Update()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 170, 170, 170, 255);

    Mouse::UpdateMousePosition();
    std::cout << MOUSE_X << " : " << MOUSE_Y << std::endl;

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

    if (state->switchToState != States::StateID::NotSpecified
        && state->switchToState != state->stateID)
    {
        States::StateID switchToState = state->switchToState;
        state->~State();

        Events::EventHandler::DestroyQueue();

        switch (switchToState)
        {
        case States::StateID::PlayState:
            state = new States::PlayState(window);
        }
    }

    SDL_RenderPresent(renderer);
}