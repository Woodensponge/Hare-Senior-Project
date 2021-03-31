#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"
#include "Event.h"

namespace Hare
{
	namespace Entities
	{
		struct Player : Entity
		{
			Player();
			Player(float x, float y);
			Player(int flags);
			Player(float x, float y, int flags);
			~Player();

			void Update();

			bool isSlamming = false;
			bool hasDashed = false;

			Events::Event* pc;

			uint16_t storedGravity = 0;	//When slamming, this will increment. This will also add energy to
										//a jump. When grounded, this will decrement.
		};
	}
}


#endif