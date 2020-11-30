#include "Application.h"
#include <SDL_image.h>

//Constructor for Application. Sets members from parameters.
Application::Application(const char *title, int windowWidth, int windowHeight, Uint32 flags, int fps)
{
    this->window = 0;
    this->renderer = 0;

    this->windowTitle = title;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->flags = flags;
    this->fps = fps;
}

//Deconstructor. Completely handles destruction for this object.
Application::~Application()
{
    for (int i = 0; i < (textures.size()); i++)
        SDL_DestroyTexture(textures[i]);

    IMG_Quit();
    SDL_Quit();
}

//Initialization method. Handles SDL2 initialization.
int Application::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

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

    SDL_Surface* image = IMG_Load
    (
        "C:\\Users\\Woodensponge\\Documents\\GitHub\\Hare\\bin\\Win32\\Debug\\civvie.png"
    );

    textures.push_back(SDL_CreateTextureFromSurface(renderer, image));

    SDL_FreeSurface(image);

    return 0;
}

//Update method. Handles rendering, UI, and other things involving the window.
void Application::Update(double deltaTime)
{
    SDL_RenderClear(renderer);

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

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            //TODO: Add player input functionality
            break;
        case SDL_QUIT:
            state = GameState::Closing;
            return;                     //Stop the update method and begin closing.
        }
    }

    for (int i = 0; i < (textures.size()); i++)
        SDL_RenderCopy(renderer, textures[i], 0 ,0);

    SDL_RenderPresent(renderer);

    std::cout << deltaTime << std::endl;

    SDL_Delay(1000 / fps);
}