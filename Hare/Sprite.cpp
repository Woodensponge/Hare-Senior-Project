#include "Sprite.h"
#include "Application.h"
#include "TextureManager.h"
#include "Debug.h"

#include <cmath>
#include <SDL_image.h>
#include <cassert>

Sprite::Sprite()
	:x(0), y(0), w(0), h(0)
{
	this->texture = 0;

	this->size = SDL_Rect();
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture)
	:x(0), y(0), w(0), h(0)
{
	this->texture = texture;

	this->size = SDL_Rect();
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture, double x, double y)
{
	this->texture = texture;
	this->x = x;
	this->y = y;

	this->size = SDL_Rect();
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture, double x, double y, int w, int h)
{
	this->texture = texture;
	this->x = x;
	this->y = y;

	this->w = w;
	this->h = h;
	this->size = SDL_Rect();
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture, double x, double y, SDL_Rect size)
{
	this->texture = texture;
	this->x = x;
	this->y = y;

	this->size = size;
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture, SDL_Rect size)
{
	this->texture = texture;
	this->x = size.x;
	this->y = size.y;

	this->size = size;
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(const char* imageName)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->size = SDL_Rect();
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(const char* imageName, double x, double y)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->x = x;
	this->y = y;

	this->size = SDL_Rect();
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(const char* imageName, double x, double y, int w, int h)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->x = x;
	this->y = y;

	this->w = w;
	this->h = h;
	this->size = SDL_Rect();
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(const char* imageName, double x, double y, SDL_Rect size)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->x = x;
	this->y = y;

	this->size = size;
	this->sourceRect = SDL_Rect();
}

Sprite::Sprite(const char* imageName, SDL_Rect size)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->x = size.x;
	this->y = size.y;

	this->size = size;
	this->sourceRect = SDL_Rect();
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

//Function definitions

/*
Sets the sprites X and Y coordinates to whatever the parameters specify.
*/
void Sprite::SetPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}

/*
Sets the size of the sprites SDL_Rect member.
*/
void Sprite::SetSize(SDL_Rect size)
{
	this->size = size;
}

/*
Sets the size of the sprites SDL_Rect member. Will update in the Update function.
*/
void Sprite::SetSize(int w, int h)
{
	this->w = w;
	this->h = h;
}

/*
Sets the source rectangle for the texture of the sprites.
*/
void Sprite::SetSourceRectangle(SDL_Rect sourceRect)
{
	this->sourceRect = sourceRect;
}

/*
Sets the sprites SDL_Texture* member to whatever the parameters specify.
The texture used in the parameter is not freed or modified.
*/
void Sprite::SetTexture(SDL_Texture* texture)
{
	this->texture = texture;
}

/*
Sets the sprites SDL_Texture* member to whatever the parameters specify. Used with SDL_Surface* variables.
The surface used in the parameter is not freed or modified.
*/
void Sprite::SetTextureFromSurface(SDL_Surface* surface)
{
	this->texture = SDL_CreateTextureFromSurface(Application::renderer, surface);
}

/*
Updates the sprite.
*/
void Sprite::Update()
{
	assert(this != nullptr);		//If the assert fails, that means the sprite hasn't even been created.
									//Always make sure to define a sprite pointer.
	this->size.x = lround(x);
	this->size.y = lround(y);

	this->size.w = w;
	this->size.h = h;
}