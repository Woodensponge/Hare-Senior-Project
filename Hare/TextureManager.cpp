#include "TextureManager.h"
#include "Application.h"
#include "Debug.h"

#include <SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* imagePath)
{
	SDL_Surface* image = IMG_Load(imagePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Application::renderer, image);
	SDL_FreeSurface(image);

	return texture;
}

SDL_Texture* TextureManager::LoadTextureFromSurface(SDL_Surface* surface)
{
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Application::renderer, surface);
	return texture;
}

void TextureManager::RenderSprite(Sprite* sprite)
{
	sprite->Update();
	SDL_RenderCopy(Application::renderer, sprite->texture, 0, &sprite->size);
}
