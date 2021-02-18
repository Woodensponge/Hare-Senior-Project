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
	Level(const char* levelJson);
	~Level();

	void Update();

	//Width of the level
	Uint32 width;
	//Height of the level
	Uint32 height;

	Json::Value levelFileJson;

	TileMap* tileMap;
};


#endif
