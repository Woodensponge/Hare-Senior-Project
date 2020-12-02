#include "Sprite.h"

//Constructors and destructors
Sprite::Sprite()
{
	this->texture = 0;
	this->x = 0;
	this->y = 0;
}

Sprite::Sprite(SDL_Texture* texture)
{
	this->texture = texture;
	this->x = 0;
	this->y = 0;
}

Sprite::Sprite(SDL_Texture* texture, int x, int y)
{
	this->texture = texture;
	this->x = x;
	this->y = y;

	//TODO: Does not calling SDL_DestroyTexture on a perameter cause a memory leak?
	SDL_DestroyTexture(texture);
}

Sprite::Sprite(SDL_Texture* texture, int x, int y, SDL_Rect size)
{
	this->texture = texture;
	this->x = x;
	this->y = y;
	this->size = size;

	//TODO: Does not calling SDL_DestroyTexture on a perameter cause a memory leak?
	SDL_DestroyTexture(texture);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
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
void Sprite::SetSize(SDL_Rect size)
{
	this->size = size;
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