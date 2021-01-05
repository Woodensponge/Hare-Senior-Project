#include "PlayState.h"
#include "Application.h"
#include "Timer.h"
#include "Level.h"
#include "EventHandler.h"
#include "KeyboardEvent.h"

using namespace States;

PlayState::PlayState(SDL_Window* window)
	: window(window)
{
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    stateID = StateID::PlayState;
}

PlayState::~PlayState()
{
    for (Sprite* i : sprites)
		delete i;

    sprites.~vector();
}

void PlayState::Init()
{
    sprites.push_back(new Sprite("Assets/Player-Simple.png"));
    sprites.back()->SetSize(50, 50);

    //Level testing
    Level level = Level(window);
    level.~Level();

    Events::EventHandler::AddEventToQueue(new Events::EventTypes::KeyboardEvent);
}

void PlayState::Update()
{
    /*
    while (SDL_PollEvent(&Application::event))
    {
        switch (Application::event.type)
        {
        case SDL_KEYDOWN:
            std::cout << "KEYDOWN" << std::endl;
            switch (Application::event.key.keysym.sym)
            {
            case SDLK_LEFT:
                sprites[0]->x = sprites[0]->x - (10 * Timer::GetDeltaTime(true));
                break;
            case SDLK_RIGHT:
                sprites[0]->x = sprites[0]->x + (10 * Timer::GetDeltaTime(true));
                break;
            case SDLK_UP:
                sprites[0]->y = sprites[0]->y - (10 * Timer::GetDeltaTime(true));
                break;
            case SDLK_DOWN:
                sprites[0]->y = sprites[0]->y + (10 * Timer::GetDeltaTime(true));
                break;
            }
            break;
        }
    }
    */

    for (Sprite* i : sprites)
    {
        i->Update();
        SDL_RenderCopy(Application::renderer, i->texture, 0, i->size);
    }
}
