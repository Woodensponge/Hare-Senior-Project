#include "Cell.h"
#include "Simulation.h"

//Constructors and destructors. (LOL there isnt any destructors yet, they're not needed I think.)

Cell::Cell()
{
	this->type = CellType::Empty;
	SetColor(0, 0, 0, 0);
}

Cell::Cell(CellType type)
{
	this->type = type;
	SetColorBasedOnType(type);
}

Cell::Cell(SDL_Color color)
{
	this->type = CellType::Empty;
	SetColor(color);
}

Cell::Cell(CellType type, SDL_Color color)
{
	this->type = type;
	SetColor(color);
}

//Method definitions.

/*
Updates the cell. Determines almost everything about it depending on the properties it has and what
state it is currently in (eg. Is it falling? Is it interacting with the player?)
* Simulation* sim: Simulation pointer. Used to check and modify other cells in the given simuation.
*/
void Cell::Update(Simulation* sim)
{
	if (IsCustomColor())
		SetColorBasedOnType();

	switch (this->type)
	{
	case CellType::Sand:
		break;
	case CellType::Empty:
		break;
	}
}

/*
Sets the color of the cell.
*SDL_Color color: Given color class replacing the original.
*/
void Cell::SetColor(SDL_Color color)
{
	this->color = color;
	isCustomColor = true;
}

/*
Sets the color of the cell.
*Uint8 r: Sets the red value for the color.
*Uint8 g: Sets the green value for the color.
*Uint8 b: Sets the blue value for the color.
*Uint8 a: Sets the alpha value for the color.
*/
void Cell::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;
	this->color.a = a;
	isCustomColor = true;
}

void Cell::SetColorBasedOnType()
{
	switch (type)
	{
	case CellType::Empty:
		SetColor(255, 255, 255, 255);
		break;
	case CellType::Sand:
		SetColor(50, 50, 50, 255);
		break;
	}
}

void Cell::SetColorBasedOnType(CellType type)
{
	switch (type)
	{
	case CellType::Empty:
		SetColor(255, 255, 255, 255);
		break;
	case CellType::Sand:
		SetColor(50, 50, 50, 255);
		break;
	}
}
