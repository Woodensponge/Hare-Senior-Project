//TODO: Considering the removal of KeyboardEvent

#include "KeyboardEvent.h"
#include "Debug.h"

#include <iostream>

using namespace Events;
using namespace Events::EventTypes;

KeyboardEvent::KeyboardEvent()
{
    this->eventID = EventID::KeyboardEvent;
    this->isSingleOnly = true;
}

KeyboardEvent::~KeyboardEvent()
{
    DEBUG_LOG_DEBUGONLY << "KEYBOARD EVENT DESTRUCTOR CALLED";
}

void KeyboardEvent::Update(SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_KEYDOWN:
        switch (event->key.keysym.sym)
        {
        case SDLK_LEFT:
            DEBUG_LOG_DEBUGONLY << "KEYLEFT";
            break;
        case SDLK_RIGHT:
            DEBUG_LOG_DEBUGONLY << "KEYRIGHT";
            break;
        case SDLK_UP:
            DEBUG_LOG_DEBUGONLY << "KEYUP";
            break;
        case SDLK_DOWN:
            DEBUG_LOG_DEBUGONLY << "KEYDOWN";
            break;
        }
        break;
    }
}