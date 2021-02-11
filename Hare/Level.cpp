#include "Level.h"
#include "Debug.h"
#include "JsonManager.h"

Level::Level(const char* levelFile)
{
	levelFileJson = JsonManager::OpenJson(levelFile);
	tileMap = TileMap(levelFileJson["tilemap"].asCString());
	width = tileMap.GetGeneralWidth();
	height = tileMap.GetGeneralHeight();
}

Level::~Level()
{
	tileMap.~TileMap();
}

void Level::Update()
{
	tileMap.Update();
}
