#include "Vector2.h"
#include <algorithm>

Vector2::Vector2()
	:x(0), y(0)
{
}

Vector2::Vector2(float x, float y)
	:x(x), y(y)
{
}

Vector2::~Vector2()
{
}

SDL_Rect Vector2::ToRect()
{
	SDL_Rect rect = SDL_Rect();
	rect.x = lround(this->x);
	rect.y = lround(this->y);
	return rect;
}