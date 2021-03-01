#include "Camera.h"
#include "Application.h"
#include "Debug.h"

Camera::Camera()
	:drect(SDL_Rect()), size(SDL_Rect())
{
	SDL_GetWindowMaximumSize(Application::GetWindow(), &drect.w, &drect.h);
	drect.x = 0;
	drect.y = 0;

	InitTexture();
}

Camera::Camera(int width, int height)
	:drect(SDL_Rect()), size(SDL_Rect())
{
	drect.w = width;
	drect.h = height;
	drect.x = 0;
	drect.y = 0;

	InitTexture();
}

Camera::Camera(int width, int height, int viewportWidth, int viewportHeight)
	:drect(SDL_Rect()), size(SDL_Rect())
{
	drect.w = width;
	drect.h = height;
	drect.x = 0;
	drect.y = 0;

	size.w = viewportWidth;
	size.h = viewportHeight;

	InitTexture();
}

Camera::~Camera()
{
	SDL_DestroyTexture(texture);

	DEBUG_LOG << "CAMERA RENDERQUEUE HAS " << renderQueue.size() << " SPRITE(S) LEFT";
	for (Sprite* sprite : renderQueue)
	{
		if (sprite != nullptr)
			delete sprite;
	}
	renderQueue.clear();
	renderQueue.~vector();
}

void Camera::ClearTexture()
{
	SDL_DestroyTexture(texture);
	InitTexture();
}

void Camera::AddToQueue(Sprite* sprite)
{
	sprite->Update();
	renderQueue.push_back(sprite);
}

void Camera::RenderTexture()
{
	SDL_SetRenderTarget(Application::renderer, texture);
	for (Sprite* sprite : renderQueue)
	{
		if (!sprite->ignoreCamera)
		{
			sprite->size.x -= size.x;
			sprite->size.y -= size.y;
		}
		SDL_RenderCopy(Application::renderer, sprite->texture, 0, &sprite->size);
	}
	SDL_SetRenderTarget(Application::renderer, NULL); //NULL SETS TO DEFAULT

	//Clear the render queue, make space for the next frame.
	//Don't delete the sprites here. Rely on the code calling this function to destroy the sprites.
	renderQueue.clear();
}

void Camera::SetSize(int width, int height)
{
	drect.w = width;
	drect.h = height;
}

void Camera::SetPosition(int x, int y)
{
	size.x = x;
	size.y = y;
}

void Camera::InitTexture()
{
	int width;
	int height;
	SDL_GetWindowMaximumSize(Application::GetWindow(), &width, &height);
	texture = SDL_CreateTexture
	(
		Application::renderer, 
		SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_TARGET, 
		drect.w, 
		drect.h
	);

	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
}
