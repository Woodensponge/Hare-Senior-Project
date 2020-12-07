#ifndef CELL_H_
#define CELL_H_

#include "Simulation.h"

#include <vector>

enum class CellType
{
	Sand,
	Empty
};

enum class CellStatus
{
	OnFire
};

struct Cell
{
	CellType type;

	inline void Update(Simulation* sim);
};

#endif