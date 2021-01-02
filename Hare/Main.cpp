#include <iostream>
#include "Application.h"
#include "Timer.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 480

int main()
{
    Application* app = new Application("Hare", WINDOW_WIDTH, WINDOW_HEIGHT, 0, 60, true);
    app->Init();

    //TODO: Work on the Timer class and make framerate calculation dependant on that class.

    //Setup variables to calculate Delta Time for framerate
    Uint32 lastTicks = SDL_GetTicks();
    int frameTime = 0;

    double deltaTime = 0;

    while (app->state != GameState::Closing)
    {
        Timer::UpdateDeltaTime();

        //Get ticks right now to calculate Delta Time for framerate
        lastTicks = SDL_GetTicks();

        app->Update();

        //Calculate Delta Time for framerate
        frameTime = SDL_GetTicks() - lastTicks;
        if (app->isCapped)
            if ((1000 / app->fps) > frameTime)
            {
                SDL_Delay((1000 / app->fps) - frameTime);
            }
    }

    app->~Application();

    return 0;
}