#ifndef VECTOR2_H_

#include <SDL.h>

struct Vector2
{
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	SDL_Rect ToRect();

	float x;
	float y;
};

#endif