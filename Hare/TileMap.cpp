#include "TileMap.h"
#include "JsonManager.h"
#include "Debug.h"

//Constuctors and destructors
TileMap::TileMap()
{
	tileMapJson = Json::Value();
}

TileMap::TileMap(const char* file)
{
	LoadMap(file);
}

TileMap::~TileMap()
{
	tileMapJson.~Value();
}

void TileMap::LoadMap(const char* file)
{
	DEBUG_LOG << "LOADING TILEMAP";

	tileMapJson = JsonManager::OpenJson(file);	//Open the Json file containing the tilemap data

	//Create a tileSetJson with the test tile set.
	Json::Value tileSetJson = JsonManager::OpenJson("Assets/Tilemaps/Level-Test-Tileset.json");

	//TODO: Keep working on rendering tilesets.

	int iterator = 0;

	//Parse JSON data to the 2D vector
	for (int y = 0; y < GetGeneralHeight(); y++)
	{
		tiles.push_back(std::vector<Tile>());

		for (int x = 0; x < GetGeneralWidth(); x++)
		{
			iterator++;

			Tile tile;
			tile.width, tile.height = 20;

			tile.tileID = tileMapJson["layers"][0]["data"][iterator - 1].asInt();

			if (tile.tileID != 0)
				tile.tileID -= 1;

			tile.x = x;
			tile.y = y;

			tiles[y].push_back(tile);
		}
	}

	DEBUG_LOG << "FINISHED LOADING";
}

void TileMap::RenderMap(const char* tileSetFile)
{
	DEBUG_LOG << "RENDERING TILEMAP";

	Json::Value tileSetJson = JsonManager::OpenJson(tileSetFile);

	DEBUG_LOG << tileSetJson["tiles"].size() << " tiles in the tileset";

	for (std::vector<Tile> vector : tiles)		//For each loop for the 2D array "tiles"
	{
		for (Tile tile : vector)				//Continuation of 2D for each loop
		{
			for (int i = 0; i < tileSetJson["tiles"].size(); i++)
			{
				if (tile.tileID == tileSetJson["tiles"][i]["id"].asInt())
				{
					tile.imageName = "Assets\/Tilemaps\/" + tileSetJson["tiles"][i]["image"].asString();
				}
				else
				{
					tile.imageName = "None";
				}
			}
		}
	}

	DEBUG_LOG << "FINISHED RENDERING";
}

int TileMap::GetGeneralHeight()
{
	return tileMapJson["height"].asInt();
}

int TileMap::GetGeneralWidth()
{
	return tileMapJson["width"].asInt();
}
