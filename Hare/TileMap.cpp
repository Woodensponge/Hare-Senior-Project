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
	std::vector<std::vector<Tile>> tiles;	//Declare a 2d sprites vector
	//Create a tileSetJson with the test tile set.
	Json::Value tileSetJson = JsonManager::OpenJson("Assets/Tilemaps/Level-Test-Tileset.json");

	//tileMapJson["layers"][0]["data"]

	//TODO: Keep working on rendering tilesets.
	for (int i = 0; i < tileMapJson["layers"][0]["data"].size(); i++)
	{
		Tile tile;
		tile.width, tile.height = 20;
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
