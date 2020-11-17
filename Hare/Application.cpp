#include "Application.h"

//Constructor for Application. Sets members from parameters (2 Overloads)
//Overload 1 (Contains title, window width, window height, and SDL2 flags)
Application::Application(const char *title, int windowWidth, int windowHeight, Uint32 flags)
{
    this->window = 0;
    this->renderer = 0;

    this->windowTitle = title;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->flags = flags;
}

//Overload 2 (Contains title, window width, window height, SDL2 flags, and fps).
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
    SDL_Quit();
}

//Calculate DeltaTime in milliseconds.
inline double Application::GetDeltaTime()
{
    if (pastTicks == 0)
    {
        pastTicks = SDL_GetTicks();
        return 0;
    }

    const double frameTime = 1 / fps;
    Uint32 presentTicks = SDL_GetTicks();

    double deltaTime = (presentTicks - pastTicks);

    pastTicks = presentTicks;

    return deltaTime;
}

//Initialization method. Handles SDL2 initialization.
int Application::Init()
{
    SDL_Init(SDL_INIT_VIDEO);

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

    return 0;
}

//Update method. Handles rendering, UI, and other things involving the window.
void Application::Update()
{
    double deltaTime = GetDeltaTime();  //Get the deltatime
    
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

    std::cout << deltaTime << std::endl;
    
    SDL_Delay(1000 / 10);
}