#ifndef LAYER_H_
#define LAYER_H_

#include "Sprite.h"

struct Layer
{
	Layer();
	~Layer();

	void AddSprite(Sprite* sprite);
	
	
	int order = 0;
};

#endif