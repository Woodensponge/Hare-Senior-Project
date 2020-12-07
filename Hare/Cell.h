#ifndef CELL_H_
#define CELL_H_

#include <vector>

enum class CellType
{
	Sand,
	Empty
};

struct Cell
{
	CellType type;

	int x;
	int y;

	inline void Update(std::vector<std::vector<Cell>>* table);
};

#endif