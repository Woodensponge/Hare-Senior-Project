#include "PlayState.h"
#include "Application.h"
#include "Timer.h"
#include "Level.h"
#include "EventHandler.h"
#include "KeyboardEvent.h"
#include "TextureManager.h"

using namespace States;
using namespace Events;

PlayState::PlayState(SDL_Window* window)
	: window(window), level(window)
{
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    stateID = StateID::PlayState;
}

PlayState::~PlayState()
{
    for (Sprite* i : sprites)
		delete i;

    level.~Level();
    sprites.~vector();
}

void PlayState::Init()
{
    sprites.push_back(new Sprite("Assets/Player-Simple.png"));
    sprites.back()->SetSize(50, 50);


    this->AddEvent(new EventTypes::KeyboardEvent);
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

    for (Sprite* sprite : sprites)
    {
        TextureManager::RenderSprite(sprite);
    }
}
