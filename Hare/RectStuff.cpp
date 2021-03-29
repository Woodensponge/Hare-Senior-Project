#include "RectStuff.h"

using namespace Core;

int RectStuff::RectPenetration(SDL_Rect rect, SDL_Rect target)
{
	SDL_assert(SDL_HasIntersection(&rect, &target));
	if (!SDL_HasIntersection(&rect, &target))					//If there is no intersection between rects...
		return -1;													//Return failure value.

	Core::Vector2 targetOrigin = Core::Vector2(target.x, target.y);

	Core::Vector2 rectUpperLeft = Core::Vector2(rect.x, rect.y);
	Core::Vector2 rectUpperRight = Core::Vector2(rect.x + rect.w, rect.y);
	Core::Vector2 rectLowerLeft = Core::Vector2(rect.x, rect.y + rect.h);
	Core::Vector2 rectLowerRight = Core::Vector2(rect.x + rect.w, rect.y + rect.h);

	return std::max
	(
		std::max
		(
			Core::Vector2::CalculateDistance(rectUpperLeft, targetOrigin),
			Core::Vector2::CalculateDistance(rectUpperRight, targetOrigin)
		),
		std::max
		(
			Core::Vector2::CalculateDistance(rectLowerLeft, targetOrigin),
			Core::Vector2::CalculateDistance(rectLowerRight, targetOrigin)
		)
	);
}