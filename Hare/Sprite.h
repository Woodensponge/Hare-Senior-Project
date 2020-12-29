#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL.h>
#undef main

struct Sprite
{
	Sprite();
	Sprite(SDL_Texture* texture);
	Sprite(SDL_Texture* texture, int x, int y);
	Sprite(SDL_Texture* texture, int x, int y, int w, int h);
	Sprite(SDL_Texture* texture, int x, int y, SDL_Rect* size);
	~Sprite();

	void SetPosition(int x, int y);
	void SetSize(SDL_Rect* size);
	void SetSize(int w, int h);
	void SetSourceRectangle(SDL_Rect* sourceRect);
	void SetTexture(SDL_Texture* texture);
	void SetTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
	void Update();

	int x = 0;
	int y = 0;

	int w = 640;
	int h = 480;

	SDL_Rect* sourceRect;
	SDL_Rect* size;
	SDL_Texture* texture;
};

#endif