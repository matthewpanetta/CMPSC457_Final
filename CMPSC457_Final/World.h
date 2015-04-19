#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"
#include "Building.h"
#include "Grid.h"
#include "Cursor.h"
#include <vector>

using namespace std;

class World
{
public:
	World(int, int);
	void initialize_world();
	Cursor* get_cursor();
	Grid get_grid();
	~World();
private:
	Grid gr;
	Cursor c;
};

#endif