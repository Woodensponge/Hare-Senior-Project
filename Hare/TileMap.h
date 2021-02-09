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
	void RenderMap(const char* tileSetFile);
	int GetGeneralHeight();
	int GetGeneralWidth();

	struct Tile
	{
		int width = 0;
		int height = 0;
		int x = 0;
		int y = 0;
		int tileID = 0;
	};

private:
	Json::Value tileMapJson;
	Json::Value tileSetJson;
	SDL_Texture* tileMapTexture;
};

#endif