#include "Level.h"
#include "Application.h"
#include "RectStuff.h"
#include "Debug.h"
#include "JsonManager.h"
#include "Player.h"

#include <algorithm>

Level::Level(const char* levelFile)
{
	//Create the level.
	levelFileJson = JsonManager::OpenJson(levelFile);
	tileMap = new TileMap(levelFileJson["tilemap"].asCString(), levelFileJson["devname"].asCString());
	width = tileMap->GetGeneralWidth();
	height = tileMap->GetGeneralHeight();

	//Create entities.
	entities.push_back(new Hare::Entities::Player(50, 50));
	DEBUG_LOG << TileMap::GetEntityTileSize(entities[0]).x;
	DEBUG_LOG << TileMap::GetEntityTileSize(entities[0]).y;
}

Level::~Level()
{
	delete tileMap;
	levelFileJson.~Value();

	for (Hare::Entity* entity : entities)
	{
		delete entity;
	}

	entities.clear();
	entities.~vector();
}

void Level::Update()
{
	tileMap->Update();
	for (Hare::Entity* entity : entities)
	{
		float oldSpeed = entity->speed;
		float oldGravity = entity->gravity;
		
		Core::Vector2 oldPosition = entity->pos;
		SDL_Rect oldHitbox = entity->hitbox;

		entity->Update();
		entity->isGrounded = false;

		int entityTilePosX = (int)TileMap::GetEntityTilePos(entity).x;
		int entityTilePosY = (int)TileMap::GetEntityTilePos(entity).y;

		for (int x = entityTilePosX - 3; x <= entityTilePosX + 3; x++)		//Horizontal check of 5 tiles
		{			
			for (int y = entityTilePosY - 3; y <= entityTilePosY + 3; y++)	//Vertical check of 5 tiles
			{
				int safeY = std::clamp(y, 0, (int)tileMap->tiles.size() - 1);
				int safeX = std::clamp(x, 0, (int)tileMap->tiles[0].size() - 1);

				SDL_Rect tileRect = tileMap->tiles[safeY][safeX]->ToRect();
				SDL_Rect entityRect = entity->hitbox;

				entityRect.y = oldHitbox.y;

				//If intersecting...
				if (SDL_HasIntersection(&entityRect, &tileRect)
					&& tileMap->tiles[safeY][safeX]->imageName != "None")
				{
					entity->pos.x = oldPosition.x;
					entity->speed = 0;
					entity->UpdateHitbox();

					SDL_SetTextureColorMod
					(
						tileMap->tiles[safeY][safeX]->sprite->texture,
						255,
						0,
						0
					);
				}

				entityRect.y = entity->hitbox.y;
				entityRect.x = oldHitbox.x;

				//If still intersecting...
				if (SDL_HasIntersection(&entityRect, &tileRect)
					&& tileMap->tiles[safeY][safeX]->imageName != "None")
				{
					SDL_SetRenderDrawColor(Application::renderer, 255, 0, 0, 255);
					SDL_RenderDrawLine
					(
						Application::renderer,
						entity->pos.x,
						entity->pos.y,
						tileMap->tiles[safeY][safeX]->pos.x * 20,
						tileMap->tiles[safeY][safeX]->pos.y * 20
					);

					SDL_RenderPresent(Application::renderer);

					DEBUG_LOG << Core::RectStuff::RectPenetration(entityRect, tileRect);

					float oldGravity = entity->gravity;

					entity->pos.y -= entity->gravity;
					entity->UpdateHitbox();
					entity->gravity = 0;
					
					if (oldGravity > 0)
						entity->isGrounded = true;

					SDL_SetTextureColorMod
					(
						tileMap->tiles[safeY][safeX]->sprite->texture,
						255,
						0,
						0
					);
				}
				else
				{
					SDL_SetTextureColorMod
					(
						tileMap->tiles[safeY][safeX]->sprite->texture,
						255,
						255,
						255
					);
				}
			}
		}
	}
}
