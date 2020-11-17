#include <iostream>
#include "Application.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 480

int main()
{
    Application* app = new Application("Hare", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    app->Init();
    app->GetDeltaTime();                    //Calling GetDeltaTime before loop in order to calculate time
                                            //taken before the first frame is called.
    while (app->state != GameState::Closing)
    {
        app->Update();
    }

    app->~Application();

    return 0;
}