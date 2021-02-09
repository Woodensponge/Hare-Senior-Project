#ifndef LEVEL_H_
#define LEVEL_H_

#include "Cell.h"
#include "Simulation.h"
#include "Sprite.h"
#include "TileMap.h"

#include <SDL.h>
#include <vector>

struct Level
{
	Level(int width, int height);
	Level(int width, int height, const char* tileMapJsonFile);
	Level(SDL_Window* window);
	Level(SDL_Window* window, const char* tileMapJsonFile);
	Level(const char* tileMapJsonFile);
	~Level();

	void Update();

	//Width of the level
	Uint32 width;
	//Height of the level
	Uint32 height;

	TileMap tileMap;
};


#endif
