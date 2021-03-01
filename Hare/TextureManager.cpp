#include "TextureManager.h"
#include "Application.h"
#include "Debug.h"

#include <SDL_image.h>
#include <algorithm>

std::vector<Sprite*> TextureManager::renderQueue;

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
	renderQueue.push_back(sprite);
}

void TextureManager::RenderQueue()
{
	//Sort the vector
	std::sort(renderQueue.begin(), renderQueue.end(), SortSpriteLayer_LessThan());

	for (Sprite* sprite : renderQueue)
	{
		SDL_RenderCopy(Application::renderer, sprite->texture, 0, &sprite->size);
	}
	//Clear the render queue, make space for the next frame.
	//Don't delete the sprites here. Rely on the code calling this function to destroy the sprites.
	renderQueue.clear();
}

void TextureManager::ClearQueue()
{
	renderQueue.clear();
}

/*
ONLY RUN THIS DURING APPLICATION DESTRUCTION
*/
void TextureManager::DestroyQueue()
{
	DEBUG_LOG << "RENDERQUEUE HAS " << renderQueue.size() << " SPRITE(S) LEFT";
	for (Sprite* sprite : renderQueue)
	{
		if (sprite != nullptr)
			delete sprite;
	}
	renderQueue.clear();
	renderQueue.~vector();
}
