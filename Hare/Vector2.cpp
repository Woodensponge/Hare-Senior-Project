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

Vector2::Vector2(int x, int y)
	: x(static_cast<float>(x)), y(static_cast<float>(y))
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

std::string Core::Vector2::ToString()
{
	std::ostringstream oss;
	oss << this->x << " : " << this->y;
	return oss.str();
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