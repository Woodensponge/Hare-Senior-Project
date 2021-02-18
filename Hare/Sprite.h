#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL.h>
#undef main

struct Sprite
{
	Sprite();
	Sprite(SDL_Texture* texture);
	Sprite(SDL_Texture* texture, double x, double y);
	Sprite(SDL_Texture* texture, double x, double y, int w, int h);
	Sprite(SDL_Texture* texture, double x, double y, SDL_Rect size);

	Sprite(const char* imageName);
	Sprite(const char* imageName, double x, double y);
	Sprite(const char* imageName, double x, double y, int w, int h);
	Sprite(const char* imageName, double x, double y, SDL_Rect size);

	~Sprite();

	void SetPosition(double x, double y);
	void SetSize(SDL_Rect size);
	void SetSize(int w, int h);
	void SetSourceRectangle(SDL_Rect sourceRect);
	void SetTexture(SDL_Texture* texture);
	void SetTextureFromSurface(SDL_Surface* surface);
	void Update();

	double x = 0;
	double y = 0;

	int w = 640;
	int h = 480;

	SDL_Rect sourceRect;
	SDL_Rect size;
	SDL_Texture* texture;
	bool fuckme = false;
};

#endif