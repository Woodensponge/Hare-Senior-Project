#include "TextureManager.h"
#include "Debug.h"
#include "Application.h"

#include <SDL_image.h>
#include <algorithm>

std::vector<Sprite*> TextureManager::renderQueue;
Camera* TextureManager::mainCamera = nullptr;

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
	if (mainCamera != nullptr)
	{
		//Sort the vector
		std::sort(renderQueue.begin(), renderQueue.end(), SortSpriteLayer_LessThan());

		for (Sprite* sprite : renderQueue)
		{
			mainCamera->AddToQueue(sprite);
		}
		mainCamera->RenderTexture();

		SDL_RenderCopy(Application::renderer, mainCamera->texture, NULL, &mainCamera->drect);
		mainCamera->ClearTexture();

		return;
	}

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
