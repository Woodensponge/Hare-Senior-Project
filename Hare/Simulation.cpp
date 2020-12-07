#include "Simulation.h"

//Constructors and destructors
Simulation::Simulation()
{
}

Simulation::Simulation(Uint32 size)
{
	this->width = size;
	this->height = size;
}

Simulation::Simulation(Uint32 width, Uint32 height)
{
	this->width = width;
	this->height = height;
}

Simulation::~Simulation()
{
	table.clear();
}

/*
======-| Cell Management |-=======
A couple of methods are put in place to organize cell updating, collecting
data from cells, etc.
==================================
*/

/*
Finds the cell in the table and attempts to return it back.
* Uint32 x: The (unsigned) X coordinate of the specified cell.
* Uint32 y: The (unsigned) Y coordinate of the specified cell.
*/
Cell* Simulation::GetCell(Uint32 x, Uint32 y)
{
	return &table[x][y];
}

/*
Sets a certain cell in the table given the specified coordinates. 
Will not set the cell if it is not empty.
* Uint32 x: The (unsigned) X coordinate of the specified cell.
* Uint32 y: The (unsigned) Y coordinate of the specified cell.
* Cell cell: Given cell data replacing the original.
*/
void Simulation::SetCell(Uint32 x, Uint32 y, Cell cell)
{
	if (table[x][y].type == CellType::Empty)
		table[x][y] = cell;
}

/*
Sets a certain cell in the table given the specified coordinates.
Will set the cell regardless if it is empty.
* Uint32 x: The (unsigned) X coordinate of the specified cell.
* Uint32 y: The (unsigned) Y coordinate of the specified cell.
* Cell cell: Given cell data replacing the original.
*/
void Simulation::ForceSetCell(Uint32 x, Uint32 y, Cell cell)
{
	table[x][y] = cell;
}

/*
Sets a certain cell's type in the table given the specified coordinates.
Will not set the cell type if undergoing a status.
* Uint32 x: The (unsigned) X coordinate of the specified cell.
* Uint32 y: The (unsigned) Y coordinate of the specified cell.
* Cell cell: Given cell data replacing the original.
*/
void Simulation::SetCellType(Uint32 x, Uint32 y, CellType type)
{
	//NOTE: Statuses aren't implemented yet, so the raw way of setting
	//it for this function is good enough for now.
	table[x][y].type = type;
}

/*
Sets a certain cell's type in the table given the specified coordinates.
Will set the cell type regardless if the cell is undergoing a status.
* Uint32 x: The (unsigned) X coordinate of the specified cell.
* Uint32 y: The (unsigned) Y coordinate of the specified cell.
* Cell cell: Given cell data replacing the original.
*/
void Simulation::ForceSetCellType(Uint32 x, Uint32 y, CellType type)
{
	table[x][y].type = type;
}

/*
Updates all of the cells at once.
Only recommended for loading up the simulation or for testing purposes.
*/
void Simulation::UpdateAll()
{
	for (int x = 0; x < this->width; x++)
	{
		for (int y = 0; y < this->height; y++)
		{
			table[x][y].Update(this);
		}
	}
}

/*
Updates a singular cell.
*/
void Simulation::UpdateCell(Uint32 x, Uint32 y)
{
	table[x][y].Update(this);
}
