#include "Mouse.h"

#include <SDL.h>

int Mouse::x = 0;
int Mouse::y = 0;

void Mouse::UpdateMousePosition()
{
	SDL_GetMouseState(&x, &y);
}
