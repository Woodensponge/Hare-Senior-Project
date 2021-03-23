#include "Vector2.h"
#include <algorithm>

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
	Vector2 result = Vector2();
	result.x = vectorOne.x - vectorTwo.x;
	result.y = vectorOne.y - vectorTwo.y;
	return result;
}

float Vector2::CalculateDistance(Vector2 vectorOne, Vector2 vectorTwo)	//static
{
	Vector2 result = SubstractVectors(vectorOne, vectorTwo);
	
	return 0.0f;
}

float Vector2::CalculateDistance(Vector2 vector)
{
	return 0.0f;
}

SDL_Rect Vector2::ToRect()
{
	SDL_Rect rect = SDL_Rect();
	rect.x = lround(this->x);
	rect.y = lround(this->y);
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