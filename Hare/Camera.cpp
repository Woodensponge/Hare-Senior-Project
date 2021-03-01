#include "Camera.h"
#include "Application.h"
#include "Debug.h"

Camera::Camera()
	:rect(SDL_Rect())
{
	SDL_GetWindowMaximumSize(Application::GetWindow(), &rect.w, &rect.h);
	rect.x = 0;
	rect.y = 0;
}

Camera::Camera(int width, int height)
	:rect(SDL_Rect())
{
	rect.w = width;
	rect.h = height;
	rect.x = 0;
	rect.y = 0;
}

Camera::~Camera()
{
}

void Camera::SetSize(int width, int height)
{
	rect.w = width;
	rect.h = height;
}

void Camera::SetPosition(int x, int y)
{
	rect.x = x;
	rect.y = y;
}

void Camera::Update()
{
	SDL_RenderDrawRect(Application::renderer, &rect);
}
