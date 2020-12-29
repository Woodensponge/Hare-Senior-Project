#include "Level.h"
#include <iostream>

//TODO: Create a crude tileset system in this CPP file, then create and actual one in the TileSet files

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
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1 },
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

}

Level::~Level()
{
}

void Level::Update()
{

}
