#include "Level.h"
#include "Debug.h"
#include "JsonManager.h"

Level::Level(int width, int height)
	:width(width), height(height)
{
	tileMap = TileMap();
}

Level::Level(int width, int height, const char* tileMapJsonFile)
	:width(width), height(height)
{
	tileMap = TileMap(tileMapJsonFile);
}

Level::Level(SDL_Window* window)
{
	SDL_GetWindowSize(window, (int*)&width, (int*)&height);
}

Level::Level(SDL_Window* window, const char* tileMapJsonFile)
{
	SDL_GetWindowSize(window, (int*)&width, (int*)&height);
	tileMap = TileMap(tileMapJsonFile);
}

Level::Level(const char* levelFile)
{
	Json::Value levelFileJson = JsonManager::OpenJson(levelFile);
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

}
