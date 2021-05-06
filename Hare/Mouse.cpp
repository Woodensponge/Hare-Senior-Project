#include "Mouse.h"
#include "Application.h"

#include <algorithm>
#include <SDL.h>

int Mouse::x = 0;
int Mouse::y = 0;

Core::Vector2 Mouse::pos = Core::Vector2((float)x, (float)y);

void Mouse::UpdateMouse()
{
	int windowWidth, windowHeight;
	SDL_GetWindowSize(Application::GetWindow(), &windowWidth, &windowHeight);
	SDL_GetMouseState(&x, &y);
	pos.x = (float)std::clamp(x, 0, windowWidth);
	pos.y = (float)std::clamp(y, 0, windowHeight);
}
