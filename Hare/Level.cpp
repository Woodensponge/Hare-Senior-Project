#include "Level.h"
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
		entity->Update();

		int entityTilePosX = (int)TileMap::GetEntityTilePos(entity).x;
		int entityTilePosY = (int)TileMap::GetEntityTilePos(entity).y;

		for (int x = entityTilePosX - 1; x <= entityTilePosX + 1; x++)		//Horizontal check of 5 tiles
		{			
			for (int y = entityTilePosY - 1; y <= entityTilePosY + 1; y++)	//Vertical check of 5 tiles
			{
				int safeY = std::clamp(y, 0, (int)tileMap->tiles.size() - 1);
				int safeX = std::clamp(x, 0, (int)tileMap->tiles[0].size() - 1);

				SDL_Rect tileRect = tileMap->tiles[safeY][safeX]->ToRect();

				if (SDL_HasIntersection(&entity->hitbox, &tileRect)
					&& tileMap->tiles[safeY][safeX]->imageName != "None")
				{
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
			
		/*
		for (TileMap::Tile* tile : tileMap->GetTiles())
		{
			SDL_Rect tileRect = tile->ToRect();
			if (SDL_HasIntersection(&entity->hitbox, &tileRect)
				&& tile->imageName != "None")
			{
				float entityRight = entity->pos.x + entity->hitbox.w;
				float entityLeft = entity->pos.x;
				float entityBottom = entity->pos.y + entity->hitbox.h;
				float entityTop = entity->pos.y;

				float tileRectRight = tileRect.x + tileRect.w;
				float tileRectLeft = tileRect.x;
				float tileRectBottom = tileRect.y + tileRect.h;
				float tileRectTop = tileRect.y;

				if (entityLeft < tileRectRight)
				{
					entity->pos.x = tileRectRight;
					DEBUG_LOG << "X1";
				}

				if (entityRight > tileRectLeft)
				{
					entity->pos.x = tileRectLeft - tileRect.w;
					DEBUG_LOG << "X2";
				}

				if (entityTop < tileRectBottom)
				{
					entity->pos.y = tileRectBottom;
					DEBUG_LOG << "Y1";
				}

				if (entityBottom > tileRectTop)
				{
					entity->pos.y = tileRectTop - tileRect.h;
					DEBUG_LOG << "Y2";
				}

				entity->UpdateHitbox();
			}
		}*/
	}
}
