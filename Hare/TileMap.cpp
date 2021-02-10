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
	tileMapJson = JsonManager::OpenJson(file);	//Open the Json file containing the tilemap data
}

void TileMap::RenderMap()
{
	DEBUG_LOG << "RENDERING TILEMAP";
	std::vector<std::vector<Tile>> tiles;		//Declare a 2d sprites vector
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
			tile.x = x;
			tile.y = y;

			tiles[y].push_back(tile);
		}
	}

	DEBUG_LOG << "FINISHED RENDERING";
}

void TileMap::RenderMap(const char* tileSetFile)
{

}

int TileMap::GetGeneralHeight()
{
	return tileMapJson["height"].asInt();
}

int TileMap::GetGeneralWidth()
{
	return tileMapJson["width"].asInt();
}
