#include "World.h"



World::World(int cols, int rows)
{
	for (int i = 0; i < (cols * rows); i++) {
		Tile t;
		t.set_values();
		tiles.push_back(t);
	}
}

vector<Tile> World::getTiles()
{
	return tiles;
}

World::~World()
{
}
