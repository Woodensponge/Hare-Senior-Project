#include "Mouse.h"

#include <SDL.h>

int Mouse::x = 0;
int Mouse::y = 0;

Core::Vector2 Mouse::pos = Core::Vector2(x, y);

void Mouse::UpdateMouse()
{
	SDL_GetMouseState(&x, &y);
	pos.x = x;
	pos.y = y;
}
