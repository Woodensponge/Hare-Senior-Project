#include "Line.h"
#include "Application.h"

#include <math.h>
#include <SDL.h>

Line::Line()
	: Line::Line(Core::Vector2(0, 0), Core::Vector2(0, 0))
{
}

Line::Line(float x1, float y1, float x2, float y2)
	: Line::Line(Core::Vector2(x1, y1), Core::Vector2(x2, y2))
{
}

Line::Line(float x1, float y1, float x2, float y2, uint16_t r, uint16_t g, uint16_t b, uint16_t a)
	: Line::Line(Core::Vector2(x1, y1), Core::Vector2(x2, y2), r, g, b, a)
{
}

Line::Line(Core::Vector2 vectorOne, Core::Vector2 vectorTwo)
	: Line::Line(vectorOne, vectorTwo, 0, 255, 0, 255)
{
}

Line::Line(Core::Vector2 vectorOne, Core::Vector2 vectorTwo, uint16_t r, uint16_t g, uint16_t b, uint16_t a)
	:vectorOne(vectorOne), vectorTwo(vectorTwo), r(r), g(g), b(b), a(a)
{
}

Line::~Line()
{
}

Sprite* Line::ToSprite()
{
	SDL_Texture* texture = SDL_CreateTexture
	(
		Application::renderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET,
		abs((vectorOne - vectorTwo).x),
		abs((vectorOne - vectorTwo).y)
	);

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(Application::renderer, texture);
	SDL_SetRenderDrawColor(Application::renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine
	(
		Application::renderer,
		vectorOne.x,
		vectorOne.y,
		vectorTwo.x,
		vectorTwo.y
	);
	SDL_SetRenderTarget(Application::renderer, NULL);		//Reset the renderer to default (the window)

	return new Sprite
	(
		texture,
		vectorOne.x,
		vectorOne.y,
		abs((vectorOne - vectorTwo).x),
		abs((vectorOne - vectorTwo).y)
	);
}
