#pragma once
#include "World.h"
#include "Tile.h"

class Grid
{
public:
	Grid(int row, int column);
	~Grid();
	Tile* getTile(int row, int column);
	

private:
	int rows, columns;
	vector<vector<Tile*>> tile_grid;
};