#pragma once
#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include <vector>

class Grid
{
public:
	Grid(int row, int column);
	Tile* getTile(int row, int column);
	void drawGrid();
	void drawSubgrid(double xi, double zi, double color[3]);
	~Grid();
private:
	int rows, columns;
	std::vector<std::vector<Tile*>> tile_grid;
};

#endif