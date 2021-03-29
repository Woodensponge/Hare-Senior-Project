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

			Events::Event* pc;
		};
	}
}


#endif