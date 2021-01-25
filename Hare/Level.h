#ifndef LEVEL_H_
#define LEVEL_H_

#include "Cell.h"
#include "Simulation.h"
#include "Sprite.h"

#include <SDL.h>
#include <vector>

struct Level
{
	Level(int width, int height);
	Level(SDL_Window* window);
	~Level();

	void Update();

	//Width of the level
	Uint32 width;
	//Height of the level
	Uint32 height;

	//Simulation sim;
};


#endif
