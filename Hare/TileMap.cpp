#include "TileMap.h"
#include "JsonManager.h"
#include "Debug.h"
#include "TextureManager.h"
#include "Application.h"

int TileMap::tileWidth = 0;
int TileMap::tileHeight = 0;

//Constuctors and destructors
TileMap::TileMap()
{
	tileMapJson = Json::Value();
}

TileMap::TileMap(const char* file, const char* levelDevName)
	:levelDevName(levelDevName)
{
	LoadMap(file);
}

TileMap::~TileMap()
{
	tileMapJson.~Value();

	for (std::vector<Tile*> vector : tiles)		//For each loop for the 2D array "tiles"
		for (Tile* tile : vector)				//Continuation of 2D for each loop
			delete tile;

	tiles.~vector();
}

void TileMap::LoadMap(const char* file)
{
	DEBUG_LOG << "LOADING TILEMAP";

	tileMapJson = JsonManager::OpenJson(file);	//Open the Json file containing the tilemap data

	//TODO: Keep working on rendering tilesets.

	int iterator = 0;

	//Parse JSON data to the 2D vector
	for (int y = 0; y < GetGeneralHeight(); y++)
	{
		tiles.push_back(std::vector<Tile*>());

		for (int x = 0; x < GetGeneralWidth(); x++)
		{
			iterator++;

			Tile* tile = new Tile;
			delete tile->sprite;

			tile->width = 20;
			tile->height = 20;

			tile->tileID = tileMapJson["layers"][0]["data"][iterator - 1].asInt();

			if (tile->tileID != 0)
				tile->tileID -= 1;

			tile->pos.x = (float)x;
			tile->pos.y = (float)y;

			tiles[y].push_back(tile);
		}
	}

	//FIRST TILE WILL DEFINE THE STANDARD FOR ALL TILES!
	TileMap::tileWidth = tiles[0][0]->width;
	TileMap::tileHeight = tiles[0][0]->height;

	DEBUG_LOG << "FINISHED LOADING";
}

void TileMap::RenderMap(const char* tileSetFile)
{
	DEBUG_LOG << "RENDERING TILEMAP";

	//std::vector<Sprite*> sprites;

	Json::Value tileSetJson = JsonManager::OpenJson(tileSetFile);

	DEBUG_LOG << tileSetJson["tiles"].size() << " tiles in the tileset";

	for (std::vector<Tile*> vector : tiles)		//For each loop for the 2D array "tiles"
	{
		for (Tile* tile : vector)				//Continuation of 2D for each loop
		{
			//Get the image for the sprite
			for (unsigned int i = 0; i < tileSetJson["tiles"].size(); i++)
			{
				if (tile->tileID == tileSetJson["tiles"][i]["id"].asInt())
				{
					tile->imageName = 
						"Assets/Tilemaps/" 
						+ levelDevName 
						+ "/" 
						+ tileSetJson["tiles"][i]["image"].asString();
				}
			}

			if (tile->imageName == "None")
			{
				tile->sprite = new Sprite();
				tile->sprite->layer = tile->layer;
				tile->sprite->Update();

				continue;
			}

			tile->sprite = new Sprite
			(
				tile->imageName.c_str(),
				(double)((double)tile->pos.x * (double)tile->width),
				(double)((double)tile->pos.y * (double)tile->height),
				tile->width, tile->height
			);
			tile->sprite->layer = tile->layer;

			tile->sprite->Update();
		}
	}

	DEBUG_LOG << "FINISHED RENDERING";
}

void TileMap::Update()
{
	for (std::vector<Tile*> vector : tiles)		//For each loop for the 2D array "tiles"
	{
		for (Tile* tile : vector)				//Continuation of 2D for each loop
		{
			TextureManager::RenderSprite(tile->sprite);
		}
	}
}

std::vector<TileMap::Tile*> TileMap::GetTiles()
{
	std::vector<Tile*> tiles;
	for (std::vector<Tile*> vector : this->tiles)	//For each loop for the 2D array "tiles" (object)
	{
		for (Tile* tile : vector)					//Continuation of 2D for each loop
		{
			tiles.push_back(tile);
		}
	}

	return tiles;
}

int TileMap::GetGeneralHeight()
{
	return tileMapJson["height"].asInt();
}

Core::Vector2 TileMap::GetEntityTilePos(Hare::Entity* entity)
{
	return Core::Vector2((float)((int)entity->pos.x / tileWidth), (float)((int)entity->pos.y / tileHeight));
}

Core::Vector2 TileMap::GetEntityTileSize(Hare::Entity* entity)
{
	return Core::Vector2((float)((int)entity->hitbox.w / tileWidth), (float)((int)entity->hitbox.h / tileHeight));
}

int TileMap::GetGeneralWidth()
{
	return tileMapJson["width"].asInt();
}

//TILE STRUCT

SDL_Rect TileMap::Tile::ToRect()
{
	SDL_Rect rect = SDL_Rect();
	rect.x = (int)(this->pos.x * 20);
	rect.y = (int)(this->pos.y * 20);
	rect.w = this->width;
	rect.h = this->height;

	return rect;
}
