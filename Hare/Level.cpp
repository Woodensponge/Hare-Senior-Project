#include "Level.h"
#include <iostream>

Level::Level(int width, int height)
{
	this->width = width;
	this->height = height;
}

Level::Level(SDL_Window* window)
{
	SDL_GetWindowSize(window, (int*)&width, (int*)&height);
	std::cout << "WINDOW WIDTH: " << width << " WINDOW HEIGHT: " << height << std::endl;
}

Level::~Level()
{
}

void Level::Update()
{

}
