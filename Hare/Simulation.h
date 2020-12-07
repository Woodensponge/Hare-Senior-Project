#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <SDL.h>
#include <vector>
#include "Cell.h"

struct Simulation
{
	Simulation();
	Simulation(Uint32 size);
	Simulation(Uint32 width, Uint32 height);
	~Simulation();

	void GetCell(Uint32 x, Uint32 y);
	
	void SetCell(Uint32 x, Uint32 y, Cell cell);
	void ForceSetCell(Uint32 x, Uint32 y, Cell cell);
	
	void SetCellType(Uint32 x, Uint32 y, CellType type);
	void ForceSetCellType(Uint32 x, Uint32 y, CellType type);

	void UpdateAll();
	void UpdateCell(Uint32 x, Uint32 y);

	Uint32 width = 640;
	Uint32 height = 480;

	std::vector<std::vector<Cell>> table; 
};

#endif