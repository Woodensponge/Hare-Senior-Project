#include "Level.h"
#include "Debug.h"
#include "JsonManager.h"

Level::Level(const char* levelFile)
{
	//Create the level.
	levelFileJson = JsonManager::OpenJson(levelFile);
	tileMap = new TileMap(levelFileJson["tilemap"].asCString(), levelFileJson["devname"].asCString());
	width = tileMap->GetGeneralWidth();
	height = tileMap->GetGeneralHeight();
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
}
