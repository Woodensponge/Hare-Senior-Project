#include "Level.h"
#include "Application.h"
#include "BasicEnemy.h"
#include "Debug.h"
#include "JsonManager.h"
#include "Line.h"
#include "Player.h"
#include "RectStuff.h"
#include "TextureManager.h"

#include <algorithm>

Level::Level(const char* levelFile)
{
	//Create the level.
	levelFileJson = JsonManager::OpenJson(levelFile);
	tileMap = new TileMap(levelFileJson["tilemap"].asCString(), levelFileJson["devname"].asCString(), this);
	width = tileMap->GetGeneralWidth();
	height = tileMap->GetGeneralHeight();

	tileMap->LoadEntities();
	
	entities.push_back(new Hare::Entities::BasicEnemy(60, 50));
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
	/*
	TODO: REWORK THE ENTIRE COLLISION SYSTEM. MAKE THE COLLISION NOT FIXED. ADD INTERPOLATION.
	MAKE COLLISION THAT'S NOT BIASED.

	(I might not even get to this. I love deadlines.)
	*/
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
					Core::Vector2 nearestCorner = Core::RectStuff::FindNearestCornerInOrigin(entityRect, tileRect);

					if (entity->speed < 0)
						entity->pos.x += abs(nearestCorner.x - (tileMap->tiles[safeY][safeX]->pos * 20).x - entity->hitbox.w);
					else if (entity->speed > 0)
						entity->pos.x -= abs(nearestCorner.x - (tileMap->tiles[safeY][safeX]->pos * 20).x);

					entity->UpdateHitbox();

					if (entity->hitbox.x == tileRect.x)
					{
						//Entity is stuck! 
						if (entity->speed < 0)
							entity->pos.x += entity->hitbox.w;
						else if (entity->speed >= 0)
							entity->pos.x -= entity->hitbox.w;

						entity->UpdateHitbox();
					}

					entity->speed = 0;

#ifdef _DEBUG
					SDL_SetTextureColorMod
					(
						tileMap->tiles[safeY][safeX]->sprite->texture,
						255,
						0,
						0
					);
#endif
				}

				entityRect.y = entity->hitbox.y;
				entityRect.x = oldHitbox.x;

				//If still intersecting...
				if (SDL_HasIntersection(&entityRect, &tileRect)
					&& tileMap->tiles[safeY][safeX]->imageName != "None")
				{
					float currentGravity = entity->gravity;

					Core::Vector2 nearestCorner = Core::RectStuff::FindNearestCornerInOrigin(entityRect, tileRect);
#ifdef _DEBUG
					Line line = Line
					(
						tileMap->tiles[safeY][safeX]->pos * 20,
						nearestCorner
					);
					TextureManager::RenderLine(line);
#endif

					//DEBUG_LOG << (tileMap->tiles[safeY][safeX]->pos * 20).y - nearestCorner.y;
					if (entity->gravity < 0)
					{
						entity->pos.y += abs((nearestCorner.y - (tileMap->tiles[safeY][safeX]->pos * 20).y) - entity->hitbox.h);
						entity->UpdateHitbox();
						if (entity->gravity <= 0)
						{
							entity->gravity -= entity->gravity / 4;
						}
					}
					else if (entity->gravity >= 0)
					{
						entity->pos.y -= abs(nearestCorner.y - (tileMap->tiles[safeY][safeX]->pos * 20).y);
						entity->UpdateHitbox();
						entity->gravity = 0;
					}

					if (oldGravity == 0)
						entity->isGrounded = true;

					if (entity->hitbox.y == tileRect.y)
					{
						//Entity is stuck! 
						if (oldGravity < 0)
							entity->pos.y += entity->hitbox.h;
						else if (oldGravity >= 0)
							entity->pos.y -= entity->hitbox.h;

						entity->UpdateHitbox();
					}
#ifdef _DEBUG
					SDL_SetTextureColorMod
					(
						tileMap->tiles[safeY][safeX]->sprite->texture,
						255,
						0,
						0
					);
#endif
				}
				else
				{
#ifdef _DEBUG
					SDL_SetTextureColorMod
					(
						tileMap->tiles[safeY][safeX]->sprite->texture,
						255,
						255,
						255
					);
#endif
				}
			}
		}
	}
}
