#include "BasicEnemyAI.h"
#include "BasicEnemy.h"
#include "EntityManager.h"

using namespace Hare::EntityAI;

BasicEnemyAI::BasicEnemyAI()
	: basicEnemy(nullptr)
{
}

BasicEnemyAI::BasicEnemyAI(Entity* basicEnemy)
	: basicEnemy(basicEnemy)
{
	
}

BasicEnemyAI::~BasicEnemyAI()
{

}

void BasicEnemyAI::Update()
{
	if (basicEnemy->entityFlags & ENTITYSTATE_DEAD)
		return;

	Level* level = basicEnemy->level;
	
	Entity* closestEntity = EntityManager::GetClosestEntity(basicEnemy, level->entities);

	if (closestEntity == nullptr)
		return;

	if (closestEntity->entityType == EntityType::Player
		&& !(closestEntity->entityFlags & ENTITYSTATE_DEAD))
	{
		if (basicEnemy->pos.x != closestEntity->pos.x)			//If BasicEnemies X position isn't 
		{														//the same as the players...
			//Move the BasicEnemy accordingly.
			if (basicEnemy->pos.x < closestEntity->pos.x)
				basicEnemy->speed += 1;
			else if (basicEnemy->pos.x > closestEntity->pos.x)
				basicEnemy->speed -= 1;
		}

		if (basicEnemy->pos.y > closestEntity->pos.y			//If BasicEnemies Y position is
			&& basicEnemy->isGrounded							//more then the players and
			&& !(closestEntity->entityFlags & ENTITYSTATE_DEAD))//BasicEnemy is grounded...
		{
			//Make the BasicEnemy jump.
			basicEnemy->gravity -= 10;
		}
	}
}
