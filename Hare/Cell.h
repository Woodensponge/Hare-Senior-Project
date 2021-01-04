#ifndef CELL_H_
#define CELL_H_

#include <vector>
#include <SDL.h>

//Create a "Class" of Simulation to avoid header recursion
struct Simulation;

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
	Cell();
	Cell(CellType type);
	Cell(SDL_Color color);
	Cell(CellType type, SDL_Color color);

	void Update(Simulation* sim);
	void SetColor(SDL_Color color);
	void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	
	SDL_Color color;
	CellType type;

	bool IsCustomColor() { return isCustomColor; };

private:
	void SetColorBasedOnType();
	void SetColorBasedOnType(CellType type);
	bool isCustomColor = false;
};

#endif