#include "RectStuff.h"
#include "Debug.h"

using namespace Core;

int RectStuff::OriginPenetration(SDL_Rect rect, SDL_Rect target)
{
	SDL_assert(SDL_HasIntersection(&rect, &target));

	const Core::Vector2 targetOrigin = Core::Vector2(target.x, target.y);
	const Core::Vector2 rectOrigin = Core::Vector2(rect.x, rect.y);

	return static_cast<int>(Core::Vector2::CalculateDistance(rectOrigin, targetOrigin));
}

int RectStuff::Penetration(SDL_Rect rect, SDL_Rect target)
{
	SDL_assert(SDL_HasIntersection(&rect, &target));

	const Core::Vector2 targetOrigin = Core::Vector2(target.x, target.y);

	const Core::Vector2 rectUpperLeft = Core::Vector2(rect.x, rect.y);
	const Core::Vector2 rectUpperRight = Core::Vector2(rect.x + rect.w, rect.y);
	const Core::Vector2 rectLowerLeft = Core::Vector2(rect.x, rect.y + rect.h);
	const Core::Vector2 rectLowerRight = Core::Vector2(rect.x + rect.w, rect.y + rect.h);

	return static_cast<int>(std::min
	(
		std::min
		(
			Core::Vector2::CalculateDistance(rectUpperLeft, targetOrigin),
			Core::Vector2::CalculateDistance(rectUpperRight, targetOrigin)
		),
		std::min
		(
			Core::Vector2::CalculateDistance(rectLowerLeft, targetOrigin),
			Core::Vector2::CalculateDistance(rectLowerRight, targetOrigin)
		)
	));
}

Core::Vector2 Core::RectStuff::FindNearestCornerInOrigin(SDL_Rect rect, SDL_Rect target)
{
	SDL_assert(SDL_HasIntersection(&rect, &target));

	const Core::Vector2 targetOrigin = Core::Vector2(target.x, target.y);

	const Core::Vector2 rectUpperLeft = Core::Vector2(rect.x, rect.y);
	const Core::Vector2 rectUpperRight = Core::Vector2(rect.x + rect.w, rect.y);
	const Core::Vector2 rectLowerLeft = Core::Vector2(rect.x, rect.y + rect.h);
	const Core::Vector2 rectLowerRight = Core::Vector2(rect.x + rect.w, rect.y + rect.h);

	float nearestDistance = std::min
	(
		std::min
		(
			Core::Vector2::CalculateDistance(rectUpperLeft, targetOrigin),
			Core::Vector2::CalculateDistance(rectUpperRight, targetOrigin)
		),
		std::min
		(
			Core::Vector2::CalculateDistance(rectLowerLeft, targetOrigin),
			Core::Vector2::CalculateDistance(rectLowerRight, targetOrigin)
		)
	);

	Core::Vector2 result;

	if (nearestDistance == Core::Vector2::CalculateDistance(rectUpperLeft, targetOrigin))
	{
		//DEBUG_LOG << "NEAREST CORNER UPPER LEFT";
		result = rectUpperLeft;
	}
	else if (nearestDistance == Core::Vector2::CalculateDistance(rectUpperRight, targetOrigin))
	{
		//DEBUG_LOG << "NEAREST CORNER UPPER RIGHT";
		result = rectUpperRight;
	}
	else if (nearestDistance == Core::Vector2::CalculateDistance(rectLowerLeft, targetOrigin))
	{
		//DEBUG_LOG << "NEAREST CORNER LOWER LEFT";
		result = rectLowerLeft;
	}
	else if (nearestDistance == Core::Vector2::CalculateDistance(rectLowerRight, targetOrigin))
	{
		//DEBUG_LOG << "NEAREST CORNER LOWER RIGHT";
		result = rectLowerRight;
	}
		
	return result;
}
