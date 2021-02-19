#ifndef TILESET_H_
#define TILESET_H_

#include "Sprite.h"
#include "Json/json.h"
#include "Debug.h"

#include <SDL.h>
#include <vector>

struct TileMap
{
	struct Tile
	{
		~Tile()
		{
			delete sprite;
		}

		int width = 0;
		int height = 0;
		int x = 0;
		int y = 0;
		unsigned int tileID = 0;
		std::string imageName = "None";
		Sprite* sprite = new Sprite();
	};

	TileMap();
	TileMap(const char* file, const char* levelDevName);
	~TileMap();

	void LoadMap(const char* file);
	void RenderMap(const char* tileSetFile);
	void Update();
	int GetGeneralHeight();
	int GetGeneralWidth();
	inline Tile* GetTile(int x, int y) { return tiles[y][x]; };

private:
	Json::Value tileMapJson;
	Json::Value tileSetJson;

	std::string levelDevName;

	std::vector<std::vector<Tile*>> tiles;
};

#endif