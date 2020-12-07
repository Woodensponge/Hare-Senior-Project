#ifndef CELLTABLE_H_
#define CELLTABLE_H_

#include "Cell.h"

#include <SDL.h>
#include <vector>

struct CellTable
{
	CellTable(int width, int height);
	CellTable(SDL_Window* window);
	~CellTable();

	//Width of the table/simulation
	Uint32 width;
	//Height of the table/simulation
	Uint32 height;

	std::vector<std::vector<Cell>> table;
	void Update();
};


#endif
