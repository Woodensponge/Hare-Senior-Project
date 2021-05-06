#include "PlayState.h"
#include "Application.h"
#include "Camera.h"
#include "Player.h"
#include "Timer.h"
#include "Level.h"
#include "EventHandler.h"
#include "KeyboardEvent.h"
#include "TextureManager.h"
#include "RectStuff.h"
#include "Mouse.h"
#include "Debug.h"

#include <algorithm>

using namespace States;
using namespace Events;

bool isFirstUpdate = true;

PlayState::PlayState(const char* levelJson)
	: level(levelJson), camera(nullptr)
{
    window = Application::GetWindow();
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    this->stateID = StateID::PlayState;
    this->hasPhysics = true;
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
    DEBUG_LOG << "LEVEL WIDTH: " << level.width << " LEVEL HEIGHT: " << level.height;
    level.tileMap->RenderMap(level.levelFileJson["tileset"].asCString());

    //Crosshair
    spriteCrosshair = new Sprite("Assets/Crosshairs/Crosshair-Simple.png", 0, 0, 20, 20);
    spriteCrosshair->layer = 2147483647; //Crosshair is always on top, no matter what.
    spriteCrosshair->ignoreCamera = true;

    camera = new Camera(windowWidth, windowHeight, 320, 240);
    camera->SetViewPosition(0, 0);
    TextureManager::SetMainCamera(camera);

    SDL_ShowCursor(0);
}

void PlayState::UpdateFixed()
{
    if (isFirstUpdate)
    {
        isFirstUpdate = false;
        return;
    }

    for (Sprite* sprite : sprites)
    {
        TextureManager::RenderSprite(sprite);
    }

    for (Hare::Entity* entity : level.GetEntities())
    {
        if (entity->entityType == Hare::EntityType::Player)
        {
            Core::Vector2 spritePos = Core::Vector2(static_cast<float>(entity->sprite->x), static_cast<float>(entity->sprite->y));

            int x = entity->hitbox.x - camera->drect.w / 2;
            int y = entity->hitbox.y - camera->drect.h / 2;

            if (!(entity->entityFlags & Hare::ENTITYSTATE_DEAD))
            {
                x += (MOUSE_X() - (windowWidth / 2));
                y += (MOUSE_Y() - (windowHeight / 2));
            }

            y += static_cast<int>(entity->gravity * 0.5);
            x += static_cast<int>(entity->speed * 0.5);

            camera->SetViewPosition(x, y);
        }

        entity->sprite->SetPosAndSize(entity->hitbox);
        entity->sprite->Update();

        TextureManager::RenderSprite(entity->sprite);
    }

    level.Update();

    if (level.entities.size() == 0)
    {
        camera->SetViewPosition(0, 0);
    }
}

void PlayState::UpdatePhysics()
{

}

void PlayState::Update()
{
    spriteCrosshair->SetPosition
    (
        MOUSE_X() - (spriteCrosshair->w / static_cast<double>(2)),
        MOUSE_Y() - (spriteCrosshair->h / static_cast<double>(2))
    );

    TextureManager::RenderSprite(spriteCrosshair);
}