#ifndef TILESET_H_
#define TILESET_H_

#include "Sprite.h"

#include <vector>

struct TileSet
{
	TileSet();
	~TileSet();

	void LoadMap(const char* rawMap[]);
	void RenderMap();

	std::vector<std::vector<Sprite*>> tiles;	//Tiles will be a vector made of sprites for now.

private:
	
};

#endif