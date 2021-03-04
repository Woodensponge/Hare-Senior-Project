#include "PlayState.h"
#include "Application.h"
#include "Camera.h"
#include "Player.h"
#include "Timer.h"
#include "Level.h"
#include "EventHandler.h"
#include "KeyboardEvent.h"
#include "TextureManager.h"
#include "Mouse.h"
#include "Debug.h"

using namespace States;
using namespace Events;

PlayState::PlayState(const char* levelJson)
	: level(levelJson), camera(nullptr)
{
    window = Application::GetWindow();
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    stateID = StateID::PlayState;
}

PlayState::~PlayState()
{
    SDL_ShowCursor(1);

    for (Sprite* i : sprites)
		delete i;

    sprites.~vector();

    delete camera;
    delete spriteCrosshair;
}

void PlayState::Init()
{
    /*
    sprites.push_back(new Sprite("Assets/Player-Simple.png"));
    sprites.back()->SetSize(50, 50);

    sprites.push_back(new Sprite("Assets/Player-Simple.png"));
    sprites.back()->SetSize(50, 50);
    sprites.back()->SetPosition(50, 50);
    */

    this->AddEvent(new EventTypes::KeyboardEvent);
    DEBUG_LOG << "LEVEL WIDTH: " << level.width << " LEVEL HEIGHT: " << level.height;
    level.tileMap->RenderMap(level.levelFileJson["tileset"].asCString());

    //Crosshair
    spriteCrosshair = new Sprite("Assets/Crosshairs/Crosshair-Simple.png", 0, 0, 20, 20);
    spriteCrosshair->layer = 2147483647; //Crosshair is always on top, no matter what.
    spriteCrosshair->ignoreCamera = true;

    camera = new Camera(level.width * 20, level.height * 20, 640, 480);
    camera->SetViewPosition(0, 0);
    TextureManager::SetMainCamera(camera);

    SDL_ShowCursor(0);
}

void PlayState::Update()
{
    for (Sprite* sprite : sprites)
    {
        TextureManager::RenderSprite(sprite);
    }

    level.Update();

    spriteCrosshair->SetPosition
    (
        MOUSE_X() - (spriteCrosshair->w / static_cast<double>(2)),
        MOUSE_Y() - (spriteCrosshair->h / static_cast<double>(2))
    );
    TextureManager::RenderSprite(spriteCrosshair);

    for (Hare::Entity* entity : level.GetEntities())
    {
        entity->sprite->x = entity->hitbox.x;
        entity->sprite->y = entity->hitbox.y;
        entity->sprite->w = entity->hitbox.w;
        entity->sprite->h = entity->hitbox.h;
        entity->sprite->Update();

        TextureManager::RenderSprite(entity->sprite);
    }

    /*
    DEBUG_LOG << camera->rect.w << " <-w : h-> " << camera->rect.h;
    DEBUG_LOG << camera->rect.x << " <-x : y-> " << camera->rect.y;
    */
}
