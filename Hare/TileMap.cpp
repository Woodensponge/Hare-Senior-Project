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
	std::vector<Sprite*> sprites;
}

void TileMap::RenderMap()
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
