#ifndef LINE_H_
#define LINE_H_

#include "Sprite.h"
#include "Vector2.h"

struct Line
{
	Line();
	Line(float x1, float y1, float x2, float y2);
	Line(float x1, float y1, float x2, float y2, uint16_t r, uint16_t g, uint16_t b, uint16_t a);
	Line(Core::Vector2 vectorOne, Core::Vector2 vectorTwo);
	Line(Core::Vector2 vectorOne, Core::Vector2 vectorTwo, uint16_t r, uint16_t g, uint16_t b, uint16_t a);
	~Line();

	Sprite* ToSprite();

	Core::Vector2 vectorOne;
	Core::Vector2 vectorTwo;

	uint16_t r = 0;
	uint16_t g = 255;
	uint16_t b = 0;
	uint16_t a = 255;
};

#endif