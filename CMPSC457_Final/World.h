#pragma once
#include "Tile.h"
#include <vector>

using namespace std;

class World
{
public:
	World(int, int);
	vector<Tile> getTiles();
	~World();
private:
	vector<Tile> tiles;
};

