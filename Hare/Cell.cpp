#include "Cell.h"
#include "Simulation.h"

void Cell::Update(Simulation* sim)
{
	switch (this->type)
	{
	case CellType::Sand:
		break;
	case CellType::Empty:
		break;
	}
}
