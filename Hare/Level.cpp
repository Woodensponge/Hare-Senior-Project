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

	for (int x = 0; x < 15; x++)			//Ugly hardcoded "X" for loop
		for (int y = 0; y < 15; y++)		//Ugly hardcoded "Y" for loop
		{
			switch (rawMap[x][y])
			{
			case 0:							//No tile
				break;
			case 1:							//Square Tile
			case 2:							//Ramp tile
				//TODO: Add code for the ramp tile.
				//Keep in mind that code for the ramp tile has not been added yet, so
				//a square tile will be placed instead of a ramp tile.


				break;
			}
		}
}

Level::~Level()
{
	for (int x = 0; x < 15; x++)			//Ugly hardcoded "X" for loop
		for (int y = 0; y < 15; y++)		//Ugly hardcoded "Y" for loop
		{
			tiles[x][y].~Sprite();
		}
}

void Level::Update()
{

}
