/*	Grid.h
*
*	This class is responsible for drawing the world's grid, and maintaining every tile on the grid */

#pragma once
#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include <vector>

class Grid
{
public:
	Grid(int row, int column);					/* Overriden Constructor */
	void drawSubgrid(double xi, double zi);		/* Draw a portion of the grid (this is called by drawGrid)*/
	void drawGrid();							/* Draw the entire grid */
	Tile* getTile(int row, int column);			/* Get a Tile at a specified location from the tile vector */
	~Grid();									/* Destructor */
private:
	int rows, columns;							/* Rows and Columns in the grid */
	std::vector<std::vector<Tile*>> tile_grid;	/* Vector of Tile objects */
};

#endif