#include "Level.h"
#include "Debug.h"
#include "JsonManager.h"
#include "Player.h"

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

		std::vector<TileMap::Tile*> tiles;

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
