#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "Cell.h"

#include <SDL.h>
#include <vector>

/*
================-| A NOTE TO KEEP IN MIND |-================
As of right now, all of the tables coordinates for the cells
are unsigned. This is subject to change in the future,
mainly because how actual levels are made in the future can
heavily influence how and where Cells are placed in the
simulation.
============================================================
*/

struct Simulation
{
	Simulation();
	Simulation(Uint32 size);
	Simulation(Uint32 width, Uint32 height);
	~Simulation();

	Cell* GetCell(Uint32 x, Uint32 y);
	
	void SetCell(Uint32 x, Uint32 y, Cell cell);
	void ForceSetCell(Uint32 x, Uint32 y, Cell cell);
	
	void SetCellType(Uint32 x, Uint32 y, CellType type);
	void ForceSetCellType(Uint32 x, Uint32 y, CellType type);

	void UpdateAll();
	void UpdateCell(Uint32 x, Uint32 y);

	Uint32 width = 640;
	Uint32 height = 480;

	std::vector<std::vector<Cell>> table; 
private:
	void InitCells();
};

#endif