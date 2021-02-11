#ifndef LAYERMANAGER_H_
#define LAYERMANAGER_H_

#include "Layer.h"

#include <vector>

struct LayerManager
{
	static void AddLayer(Layer* layer);

private:
	static std::vector<Layer*> layers;
};

#endif