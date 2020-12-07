#include "CellTable.h"
#include <iostream>

CellTable::CellTable(int width, int height)
{
	this->width = width;
	this->height = height;

	table.resize(height);
	for (int i = 0; i < height; i++)
	{
		table[i].resize(width);
	}
}

CellTable::CellTable(SDL_Window* window)
{
	SDL_GetWindowSize(window, (int*)&width, (int*)&height);

	std::cout << "WINDOW WIDTH: " << width << " WINDOW HEIGHT: " << height << std::endl;

	table.resize(height);
	for (int i = 0; i < height; i++)
	{
		table[i].resize(width);
	}

	for (int i = 0; i < table.max_size(); i++)
	{
		std::cout << table[i].max_size() << std::endl;
	}
}

CellTable::~CellTable()
{
}

void CellTable::Update()
{

}
