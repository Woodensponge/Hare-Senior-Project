#include "BasicEnemy.h"
#include "BasicEnemyAI.h"

using namespace Hare::Entities;

Hare::Entities::BasicEnemy::BasicEnemy()
{
	this->ai = new EntityAI::BasicEnemyAI(this);
}

Hare::Entities::BasicEnemy::BasicEnemy(float x, float y)
{
}

Hare::Entities::BasicEnemy::BasicEnemy(int flags)
{
}

Hare::Entities::BasicEnemy::BasicEnemy(float x, float y, int flags)
{

}

Hare::Entities::BasicEnemy::~BasicEnemy()
{
}

void Hare::Entities::BasicEnemy::Update()
{
}
