#include "Application.h"
#include "Timer.h"
#include "Debug.h"
#include "JsonManager.h"

#include <json/json.h>

#include <fstream>
#include <iostream>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
/*
int main()
{
    DEBUG_LOG << "Program starting up.";
    DEBUG_LOG_DEBUGONLY << "(DEBUG BUILD)";
    DEBUG_LOG_RELEASEONLY << "(RELEASE BUILD)";

    std::ofstream outputLog("outputLog.txt");
    if (outputLog.good())
    {
        outputLog.clear();
    }
    outputLog.close();

    Application app = Application("Hare", WINDOW_WIDTH, WINDOW_HEIGHT, 0, 60, true);

    int initReturnCode = app.Init();

    if (initReturnCode != 0)
    {
        app.~Application();
        return initReturnCode;
    }

    //Setup variables to calculate Delta Time for framerate
    float elapsedMS = 0;

    while (app.gameState != GameState::Closing)
    {
        Timer::UpdateDeltaTime();

#ifdef _DEBUG
        SDL_SetWindowTitle(app.GetWindow(), std::to_string(Timer::GetDeltaTime()).c_str());
#endif 

        //Get ticks right now to calculate Delta Time for framerate
        Uint64 start = SDL_GetPerformanceCounter();

        app.Update();

        Uint64 end = SDL_GetPerformanceCounter();
        
        //Calculate Delta Time for framerate
        elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

        if (app.isCapped)
            if ((1000 / Timer::fps) > elapsedMS)
            {
                SDL_Delay((1000 / Timer::fps) - elapsedMS);
            }
    }

    return 0;
}
*/
int main()
{
    DEBUG_LOG << "Program starting up.";
    DEBUG_LOG_DEBUGONLY << "(DEBUG BUILD)";
    DEBUG_LOG_RELEASEONLY << "(RELEASE BUILD)";

    std::ofstream outputLog("outputLog.txt");
    if (outputLog.good())
    {
        outputLog.clear();
    }
    outputLog.close();

    Application app = Application("Hare", WINDOW_WIDTH, WINDOW_HEIGHT, 0, 60, true);

    int initReturnCode = app.Init();

    if (initReturnCode != 0)
    {
        app.~Application();
        return initReturnCode;
    }

    //Setup variables to calculate Delta Time for framerate
    float elapsedMS = 0;

    Uint32 ticksPerFrame = 20;

    app.Render();

    Uint64 startTicks = SDL_GetTicks();
    Uint64 endTicks = 0;

    Timer::UpdateDeltaTime();
    Timer::UpdateFixedDeltaTime();

    while (app.gameState != GameState::Closing)
    {
        Timer::UpdateFixedDeltaTime();
        Timer::UpdateDeltaTime();

#ifdef _DEBUG
        SDL_SetWindowTitle(app.GetWindow(), (std::to_string(Timer::deltaTime) + " : " + std::to_string(Timer::fixedDt)).c_str());
#endif 

        DEBUG_LOG << (std::to_string(Timer::deltaTime) + " : " + std::to_string(Timer::fixedDt)).c_str();

        //Get ticks right now to calculate Delta Time for framerate
        Uint64 currentTicks = SDL_GetTicks();
        Uint64 start = SDL_GetPerformanceCounter();

        if ((currentTicks - startTicks) >= ticksPerFrame)
        {
            app.ticks++;
            app.Update();
            
            startTicks = currentTicks;
        }

        Uint64 end = SDL_GetPerformanceCounter();
        elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

        app.Render();
    }

    return 0;
}