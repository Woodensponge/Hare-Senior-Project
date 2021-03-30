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

#include <algorithm>

using namespace States;
using namespace Events;

bool isFirstUpdate = true;

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

    level.Update();

    for (Hare::Entity* entity : level.GetEntities())
    {
        entity->sprite->SetPosAndSize(entity->hitbox);
        entity->sprite->Update();

        TextureManager::RenderSprite(entity->sprite);

        if (entity->entityType == Hare::EntityType::Player)
        {
            //Clamp code
            /*
            int x = std::clamp
            (
                (entity->hitbox.x - camera->size.w / 2) + (MOUSE_X() - (windowWidth / 2)),
                0,
                camera->size.w
            );

            int y = std::clamp
            (
                (entity->hitbox.y - camera->size.h / 2) + (MOUSE_Y() - (windowHeight / 2)),
                0,
                (int)(level.height * 20) - windowHeight
            );
            */

            Core::Vector2 spritePos = Core::Vector2(entity->sprite->x, entity->sprite->y);

            int x = entity->hitbox.x - camera->size.w / 2;
            int y = entity->hitbox.y - camera->size.h / 2;
            if (!(entity->entityFlags & Hare::ENTITYSTATE_DEAD))
            {
                y += (MOUSE_Y() - (windowHeight / 2));
                x += (MOUSE_X() - (windowWidth / 2));
            }

            y += entity->gravity * 0.5;

            camera->SetViewPosition(x, y);
        }
    }
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
