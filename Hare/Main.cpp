#include <iostream>
#include "Application.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 480

int main()
{
    Application* app = new Application("Hare", WINDOW_WIDTH, WINDOW_HEIGHT, 0, 60, false);
    app->Init();

    //Setup variables to calculate Delta Time for game logic
    Uint64 lastPC;
    Uint64 presentPC = SDL_GetPerformanceCounter();

    //Setup variables to calculate Delta Time for framerate
    Uint32 lastTicks = SDL_GetTicks();
    int frameTime = 0;

    double deltaTime = 0;

    while (app->state != GameState::Closing)
    {
        //Calculate Delta Time for game logic
        lastPC = presentPC;
        presentPC = SDL_GetPerformanceCounter();
        deltaTime = (double)((double)(presentPC - lastPC) / SDL_GetPerformanceFrequency());
        std::cout << deltaTime << std::endl;

        //Get ticks right now to calculate Delta Time for framerate
        lastTicks = SDL_GetTicks();

        //Update the game
        app->Update(deltaTime);

        //Calculate Delta Time for framerate
        frameTime = SDL_GetTicks() - lastTicks;
        if ((1000 / app->fps) > frameTime)
            SDL_Delay((1000 / app->fps) - frameTime);
    }

    app->~Application();

    return 0;
}