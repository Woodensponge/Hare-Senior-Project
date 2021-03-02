#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"

namespace Hare
{
	namespace Entities
	{
		struct Player : Entity
		{
			Player();
			Player(int x, int y);
			Player(int flags);
			Player(int x, int y, int flags);
			~Player();

			void Update();
		};
	}
}


#endif