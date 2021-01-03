#include "Application.h"
#include "Timer.h"

#include <SDL_image.h>
#include "Level.h"

SDL_Event Application::event;
SDL_Renderer* Application::renderer = nullptr;
int Application::fps = 60;

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
}

//Deconstructor. Completely handles destruction for this object.
Application::~Application()
{
    for (size_t i = 0; i < (sprites.size()); i++)
        sprites[i]->~Sprite();

    IMG_Quit();
    SDL_Quit();
}

//Initialization method. Handles SDL2 initialization.
int Application::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO))
        std::cout << "SDL_Init has failed! SDL_ERROR:" << SDL_GetError() << std::endl;
    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "IMG_Init has failed! ERROR: " << SDL_GetError() << std::endl;

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

    state = GameState::Running;

    sprites.push_back(new Sprite("Assets/Player-Simple.png"));
    sprites.back()->SetSize(50, 50);

    //Level testing
    Level level = Level(window);
    level.~Level();

    return 0;
}

//Update method. Handles rendering, UI, and other things involving the window.
void Application::Update()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //Game state handling.
    switch (state)
    {
    case GameState::Paused:
        //TODO: Add pause functionality.
        break;
    case GameState::Minimized:
        //TODO: Add minimize functionality.
        break;
    case GameState::Closing:
        return;
    case GameState::None:
        //TODO: Throw an exception here when state == GameState::None.
        break;
    }

    //TODO: Make seperate event classes
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                sprites[0]->x = sprites[0]->x - (10 * Timer::GetDeltaTime(true));
                break;
            case SDLK_RIGHT:
                sprites[0]->x = sprites[0]->x + (10 * Timer::GetDeltaTime(true));
                break;
            case SDLK_UP:
                sprites[0]->y = sprites[0]->y - (10 * Timer::GetDeltaTime(true));
                break;
            case SDLK_DOWN:
                sprites[0]->y = sprites[0]->y + (10 * Timer::GetDeltaTime(true));
                break;
            }
            break;
        case SDL_QUIT:
            state = GameState::Closing;
            return;                     //Stop the update method and begin closing.
        }
    }

    for (size_t i = 0; i < (sprites.size()); i++)
    {
        sprites[i]->Update();
        SDL_RenderCopy(renderer, sprites[i]->texture, 0, sprites[i]->size);
    }

    SDL_RenderPresent(renderer);
}