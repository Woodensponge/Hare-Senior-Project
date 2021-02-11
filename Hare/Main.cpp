#include "Application.h"
#include "Timer.h"
#include "Debug.h"
#include "JsonManager.h"

#include <json/json.h>

#include <fstream>
#include <iostream>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main()
{
    DEBUG_LOG << "Program starting up.";
    DEBUG_LOG_DEBUGONLY << "(DEBUG BUILD)";
    DEBUG_LOG_RELEASEONLY << "(RELEASE BUILD)";

    Application* app = new Application("Hare", WINDOW_WIDTH, WINDOW_HEIGHT, 0, 60, true);

    int initReturnCode = app->Init();

    if (initReturnCode != 0)
    {
        delete app;
        return initReturnCode;
    }

    //Setup variables to calculate Delta Time for framerate
    Uint32 lastTicks = SDL_GetTicks();
    int frameTime = 0;

    double deltaTime = 0;

    while (app->gameState != GameState::Closing)
    {
        Timer::UpdateDeltaTime();

        //Get ticks right now to calculate Delta Time for framerate
        lastTicks = SDL_GetTicks();

        app->Update();

        //Calculate Delta Time for framerate
        frameTime = SDL_GetTicks() - lastTicks;
        if (app->isCapped)
            if ((1000 / Timer::fps) > frameTime)
            {
                SDL_Delay((1000 / Timer::fps) - frameTime);
            }
    }

    app->~Application();
    delete app;

#ifdef _CONSOLE

    std::cout << "Press enter to exit" << std::endl;
    std::cin.get();

#endif

    return 0;
}