#include "Sprite.h"

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

Sprite::Sprite(SDL_Texture* texture, int x, int y)
{
	this->texture = texture;
	this->x = x;
	this->y = y;

	this->size = new SDL_Rect();
	this->sourceRect = new SDL_Rect();
}

Sprite::Sprite(SDL_Texture* texture, int x, int y, SDL_Rect* size)
{
	this->texture = texture;
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
void Sprite::SetPosition(int x, int y)
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
void Sprite::SetTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface)
{
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);	
}

/*
Updates the sprite.
*/
void Sprite::Update()
{
	this->size->x = x;
	this->size->y = y;

	this->size->w = w;
	this->size->h = h;
}