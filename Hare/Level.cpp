#include "Level.h"
#include <iostream>

//TODO: Create a crude tileset system in this CPP file, then create an actual one in the TileSet files

int rawMap[15][15]
{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,2,0,0,0,0,0,0,0,0,0,0,0,2,1 },
	{ 1,1,1,2,0,0,0,0,0,0,0,2,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

std::string rawerMap[15]
{
	"000000000000000",
	"000000000000000",
	"000000000000000",
	"000000000000000",
	"000000000000000",
	"000000000000000",
	"000000000000000",
	"100001000100001",
	"111000000000111",
	"100001000100001",
	"100011000110001",
	"120000000000021",
	"112000000000211",
	"111120000021111",
	"111111111111111",
};

Level::Level(int width, int height)
{
	this->width = width;
	this->height = height;
}

Level::Level(SDL_Window* window)
{
	SDL_GetWindowSize(window, (int*)&width, (int*)&height);
	std::cout << "WINDOW WIDTH: " << width << " WINDOW HEIGHT: " << height << std::endl;

	//Crude tileset system
	/*
	for (int x = 0; x < 15; x++)			//Ugly hardcoded "X" for loop
	{
		for (int y = 0; y < 15; y++)		//Ugly hardcoded "Y" for loop
		{
			rawMap[x][y] = rawerMap[y].at(x + 1) - 48;
			std::cout << rawMap[x][y];
		}
		std::cout << std::endl;
	}

	for (int x = 0; x < 15; x++)			//Ugly hardcoded "X" for loop
		for (int y = 0; y < 15; y++)		//Ugly hardcoded "Y" for loop
		{
			switch (rawMap[x][y])
			{
			case 0:							//No tile
				//TODO: Create tile class
				tiles[x][y] = new Sprite("Assets/Tiles/TileSquare-Simple.png", x * 20, y * 20, 20, 20);
				break;
			case 1:							//Square tile
				tiles[x][y] = new Sprite("Assets/Tiles/TileSquare-Simple.png", x * 20, y * 20, 20, 20);
				break;
			case 2:							//Ramp tile
				//TODO: Add additional calculations for the ramp tile.
				tiles[x][y] = new Sprite("Assets/Tiles/TileSquare-Simple.png", x * 20, y * 20, 20, 20);
				break;
			}
		}
		*/
}

Level::~Level()
{
	/*
	for (int x = 0; x < 15; x++)			//Ugly hardcoded "X" for loop
		for (int y = 0; y < 15; y++)		//Ugly hardcoded "Y" for loop
		{
			tiles[x][y]->~Sprite();
		}
		*/
}

void Level::Update()
{

}
