#ifndef TILESET_H_
#define TILESET_H_

#include "Sprite.h"
#include "Json/json.h"

#include <SDL.h>
#include <vector>

struct TileMap
{
	TileMap();
	TileMap(const char* file);
	~TileMap();

	void LoadMap(const char* file);
	void RenderMap();
	int GetGeneralHeight();
	int GetGeneralWidth();
private:
	Json::Value tileMapJson;
	Json::Value tileSetJson;
	SDL_Texture* tileMapTexture;
};

#endif