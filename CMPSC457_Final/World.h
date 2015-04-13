#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"
#include "Building.h"
#include <vector>

using namespace std;

class World
{
public:
	World(int, int);
	vector<Tile> getTiles();
	void addBuilding(Building& b);
	~World();
private:
	vector<Tile> tiles;
};

#endif