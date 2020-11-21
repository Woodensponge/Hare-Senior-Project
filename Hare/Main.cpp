#include <iostream>
#include "Application.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 480

int main()
{
    Application* app = new Application("Hare", WINDOW_WIDTH, WINDOW_HEIGHT, 0, 60);
    app->Init();

    Uint64 presentPC = SDL_GetPerformanceCounter();
    Uint64 lastPC = 0;
    double deltaTime = 0;

    while (app->state != GameState::Closing)
    {
        lastPC = SDL_GetPerformanceCounter();

        app->Update(deltaTime);

        presentPC = SDL_GetPerformanceCounter();
        deltaTime = ((presentPC - lastPC) * 1000 / (double)SDL_GetPerformanceFrequency());
    }

    app->~Application();

    return 0;
}