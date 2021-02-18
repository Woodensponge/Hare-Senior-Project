#include "Level.h"
#include "Debug.h"
#include "JsonManager.h"

Level::Level(const char* levelFile)
{
	levelFileJson = JsonManager::OpenJson(levelFile);
	tileMap = new TileMap(levelFileJson["tilemap"].asCString(), levelFileJson["devname"].asCString());
	width = tileMap->GetGeneralWidth();
	height = tileMap->GetGeneralHeight();
}

Level::~Level()
{
	tileMap->~TileMap();
}

void Level::Update()
{
	tileMap->Update();
}
