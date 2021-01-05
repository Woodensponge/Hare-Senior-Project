#include "KeyboardEvent.h"

#include <iostream>

using namespace Events::EventTypes;

KeyboardEvent::KeyboardEvent()
{
}

KeyboardEvent::~KeyboardEvent()
{
}

void KeyboardEvent::Update(SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_KEYDOWN:
        switch (event->key.keysym.sym)
        {
        case SDLK_LEFT:
            std::cout << "KEYLEFT" << std::endl;
            break;
        case SDLK_RIGHT:
            std::cout << "KEYRIGHT" << std::endl;
            break;
        case SDLK_UP:
            std::cout << "KEYUP" << std::endl;
            break;
        case SDLK_DOWN:
            std::cout << "KEYDOWN" << std::endl;
            break;
        }
        break;
    }
}
