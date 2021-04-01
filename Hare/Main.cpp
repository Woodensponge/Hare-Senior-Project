#include "Application.h"
#include "Timer.h"
#include "Debug.h"
#include "JsonManager.h"
#include "Mouse.h"

#include <json/json.h>

#include <fstream>
#include <iostream>

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 480

#ifdef _CONSOLE
int main()
#endif
#ifdef _WINDOWS
int WinMain()
#endif
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
    float timeTillNextRender = 0;

    Uint32 ticksPerFrame = 20;

    app.Render();

    Uint64 startTicks = SDL_GetTicks();
    Uint64 endTicks = 0;

    Timer::UpdateDeltaTime();
    Timer::UpdateFixedDeltaTime();

    while (app.gameState != GameState::Closing)
    {
        Mouse::UpdateMouse();

        Timer::UpdateFixedDeltaTime();

        //Get ticks right now to calculate Delta Time for framerate
        Uint64 currentTicks = SDL_GetTicks();

        //SDL_SetWindowTitle(app.GetWindow(), (std::to_string((currentTicks > startTicks + ticksPerFrame))).c_str());

        app.UpdatePhysics();

        if (currentTicks > startTicks + ticksPerFrame)
        {
            app.ticks++;
            app.UpdateFixed();
            
            startTicks = currentTicks;
        }

#ifdef _DEBUG
        SDL_SetWindowTitle
        (
            app.GetWindow(), 
            (
                std::to_string(Timer::deltaTime) 
                + " : " 
                + std::to_string(Timer::fixedDt) 
                + " : " 
                + std::to_string(app.ticks)
            ).c_str()
        );
#endif 
        timeTillNextRender += Timer::fixedDt;
        
        if (!app.isCapped || Timer::fps == 0)
        {
            Timer::UpdateDeltaTime();
            timeTillNextRender = 0;
            app.Update();
            app.Render();
        }

        else if (app.isCapped && Timer::fps != 0)
        {
            if (timeTillNextRender >= (double)((double)(1000 / Timer::fps) / 1000))
            {
                Timer::UpdateDeltaTime();
                timeTillNextRender = 0;
                app.Update();
                app.Render();
            }
        }
    }

    return 0;
}