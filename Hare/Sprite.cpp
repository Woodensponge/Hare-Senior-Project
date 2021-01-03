#include "Sprite.h"
#include "Application.h"
#include "TextureManager.h"

#include <cmath>
#include <SDL_image.h>

//Constructors and destructors
Sprite::Sprite()
{
	this->texture = 0;

	this->size = new SDL_Rect();
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture)
{
	this->texture = texture;

	this->size = new SDL_Rect();
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture, double x, double y)
{
	this->texture = texture;
	this->x = x;
	this->y = y;

	this->size = new SDL_Rect();
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture, double x, double y, int w, int h)
{
	this->texture = texture;
	this->x = x;
	this->y = y;

	this->size->w = w;
	this->size->h = h;
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture, double x, double y, SDL_Rect* size)
{
	this->texture = texture;
	this->x = x;
	this->y = y;

	this->size = size;
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(const char* imageName)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->size = new SDL_Rect();
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(const char* imageName, double x, double y)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->x = x;
	this->y = y;

	this->size = new SDL_Rect();
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(const char* imageName, double x, double y, int w, int h)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->x = x;
	this->y = y;

	this->size->w = w;
	this->size->h = h;
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(const char* imageName, double x, double y, SDL_Rect* size)
{
	this->texture = TextureManager::LoadTexture(imageName);

	this->x = x;
	this->y = y;

	this->size = size;
	this->sourceRect = new SDL_Rect();
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
	delete sourceRect;
	delete size;
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
void Sprite::SetSize(SDL_Rect* size)
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
void Sprite::SetSourceRectangle(SDL_Rect* sourceRect)
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
	this->size->x = lround(x);
	this->size->y = lround(y);

	this->size->w = w;
	this->size->h = h;
}