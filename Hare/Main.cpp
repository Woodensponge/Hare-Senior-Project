#include <iostream>
#include "Application.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 480

int main()
{
    Application* app = new Application("Hare", WINDOW_WIDTH, WINDOW_HEIGHT, 0, 60, true);
    app->Init();

    //Setup variables to calculate Delta Time for framerate
    Uint32 lastTicks = SDL_GetTicks();
    int frameTime = 0;

    double deltaTime = 0;

    while (app->state != GameState::Closing)
    {
        //Get ticks right now to calculate Delta Time for framerate
        lastTicks = SDL_GetTicks();

        /*
        * The game gets updated based on the cap of the framerate (the SDL_Delay system going on).
        * HOWEVER, deltatime is always based on 30 frames to provide consistancy for physics calculation
        * whether or not the frame cap is actually 30 frames.
        * 
        * There's probably a much better way to handle this but I'll figure that out once I get to work on
        * the Timer class I'm working on. In the meantime, this is more than enough for now.
        * 
        * There's also probably another term for what I'm doing right now, since delta time is the time
        * between frames. This is obviously not the time between frames going on right now so its probably
        * something else.
        */
        //Update the game
        app->Update(((1000 / 30) - frameTime) / 1000.0f);

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