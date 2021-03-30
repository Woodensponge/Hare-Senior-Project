#include "TextureManager.h"
#include "Debug.h"
#include "Application.h"

#include <SDL_image.h>
#include <algorithm>

std::vector<Sprite*> TextureManager::spriteQueue;
std::vector<Line> TextureManager::lineQueue;
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

void TextureManager::RenderLine(float x1, float y1, float x2, float y2)
{
	lineQueue.push_back(Line(x1, y2, x1, y1));
}

void TextureManager::RenderLine(Core::Vector2 vectorOne, Core::Vector2 vectorTwo)
{
	lineQueue.push_back(Line(vectorOne, vectorTwo));
}

void TextureManager::RenderLine(Line line)
{
	lineQueue.push_back(line);
}

void TextureManager::RenderSprite(Sprite* sprite)
{
	sprite->Update();
	spriteQueue.push_back(sprite);
}

void TextureManager::RenderQueue()
{
	if (mainCamera != nullptr)
	{
		//Don't run method when minimized.
		if (SDL_GetWindowFlags(Application::GetWindow()) & SDL_WINDOW_MINIMIZED)
			return;

		//Sort the vector
		std::sort(spriteQueue.begin(), spriteQueue.end(), SortSpriteLayer_LessThan());

		for (Sprite* sprite : spriteQueue)
		{
			mainCamera->AddToQueue(sprite);
		}
		for (Line line : lineQueue)
		{
			mainCamera->AddToQueue(line);
		}

		mainCamera->RenderTexture();

		SDL_RenderCopy(Application::renderer, mainCamera->texture, NULL, &mainCamera->drect);

		SDL_SetRenderTarget(Application::renderer, mainCamera->texture);
		SDL_RenderClear(Application::renderer);
		SDL_SetRenderTarget(Application::renderer, NULL);

		return;
	}

	spriteQueue.clear();
}

void TextureManager::ClearQueue()
{
	spriteQueue.clear();
	lineQueue.clear();
}

/*
ONLY RUN THIS DURING APPLICATION DESTRUCTION
*/
void TextureManager::DestroyQueue()
{
	DEBUG_LOG << "RENDERQUEUE HAS " << spriteQueue.size() << " SPRITE(S) LEFT";
	for (Sprite* sprite : spriteQueue)
	{
		if (sprite != nullptr)
			delete sprite;
	}
	spriteQueue.clear();
	spriteQueue.~vector();
}
