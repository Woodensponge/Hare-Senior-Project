#ifndef LEVEL_H_
#define LEVEL_H_

#include "Entity.h"
#include "Sprite.h"
#include "TileMap.h"

#include <SDL.h>
#include <vector>

struct Level
{
	Level(const char* levelJson);
	~Level();

	inline std::vector<Hare::Entity*> GetEntities() { return entities; };
	void Update();

	//Width of the level
	Uint32 width;
	//Height of the level
	Uint32 height;

	Json::Value levelFileJson;

	TileMap* tileMap;

	std::vector<Hare::Entity*> entities;
};


#endif