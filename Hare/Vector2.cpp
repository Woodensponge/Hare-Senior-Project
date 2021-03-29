#include "Vector2.h"
#include "Debug.h"

#include <algorithm>
#include <math.h>

using namespace Core;

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

Vector2 Vector2::SubstractVectors(Vector2 vectorOne, Vector2 vectorTwo)	//static
{
	return vectorOne - vectorTwo;
}

float Vector2::CalculateDistance(Vector2 vectorOne, Vector2 vectorTwo)	//static
{
	Vector2 sum = SubstractVectors(vectorOne, vectorTwo);
	
	return sqrtf((sum.x * sum.x) + (sum.y * sum.y));
}

float Vector2::CalculateDistance(Vector2 vector)
{	
	return 0.0f;
}

SDL_Rect Vector2::ToRect()
{
	SDL_Rect rect = SDL_Rect();
	rect.x = static_cast<int>(this->x);
	rect.y = static_cast<int>(this->y);
	return rect;
}

SDL_Rect Vector2::ToRect(int w, int h)
{
	SDL_Rect rect = SDL_Rect();
	rect.w = w;
	rect.h = h;
	rect.x = lround(this->x);
	rect.y = lround(this->y);
	return rect;
}