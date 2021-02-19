#include "PlayState.h"
#include "Application.h"
#include "Timer.h"
#include "Level.h"
#include "EventHandler.h"
#include "KeyboardEvent.h"
#include "TextureManager.h"
#include "Debug.h"

using namespace States;
using namespace Events;

PlayState::PlayState(const char* levelJson)
	: level(levelJson)
{
    window = Application::GetWindow();
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

    sprites.push_back(new Sprite("Assets/Player-Simple.png"));
    sprites.back()->SetSize(50, 50);
    sprites.back()->SetPosition(50, 50);

    this->AddEvent(new EventTypes::KeyboardEvent);
    this->AddEvent(new EventTypes::KeyboardEvent);
    DEBUG_LOG << "LEVEL WIDTH: " << level.width << " LEVEL HEIGHT: " << level.height;
    level.tileMap->RenderMap(level.levelFileJson["tileset"].asCString());
}

void PlayState::Update()
{
    /*
    for (Sprite* sprite : sprites)
    {
        TextureManager::RenderSprite(sprite);
    }
    */

    level.Update();
}
