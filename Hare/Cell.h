#ifndef CELL_H_
#define CELL_H_

#include <vector>

//Create a "Class" of Simulation to avoid header recursion
class Simulation;

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

	void Update(Simulation* sim);
};

#endif