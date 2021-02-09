#include "TileMap.h"
#include "JsonManager.h"

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
	std::vector<std::vector<Sprite*>> tiles;	//Declare a 2d sprites vector
	//Create a tileSetJson with the test tile set.
	Json::Value tileSetJson = JsonManager::OpenJson("Assets/Tilemaps/Level-Test-Tileset.json");
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
