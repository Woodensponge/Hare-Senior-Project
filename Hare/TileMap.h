#ifndef TILESET_H_
#define TILESET_H_

#include "Sprite.h"
#include "Json/json.h"
#include "Debug.h"
#include "Vector2.h"
#include "Entity.h"

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

		SDL_Rect ToRect();

		int width = 0;
		int height = 0;
		Core::Vector2 pos;
		int layer = 0;
		unsigned int tileID = 0;
		std::string imageName = "None";
		Sprite* sprite = new Sprite();
	};

	TileMap();
	TileMap(const char* file, const char* levelDevName);
	~TileMap();

	static Core::Vector2 GetEntityTilePos(Hare::Entity* entity);
	/* X = Width, Y = Height*/
	static Core::Vector2 GetEntityTileSize(Hare::Entity* entity);

	std::vector<Tile*> GetTiles();
	void LoadMap(const char* file);
	void RenderMap(const char* tileSetFile);
	void Update();
	int GetGeneralHeight();
	int GetGeneralWidth();
	inline Tile* GetTile(int x, int y) { return tiles[y][x]; };

	std::vector<std::vector<Tile*>> tiles;
private:
	static int tileWidth;
	static int tileHeight;

	Json::Value tileMapJson;
	Json::Value tileSetJson;

	std::string levelDevName;
};

#endif