#include "Grid.h"
#include <iostream>


Grid::Grid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	vector<Tile*> vt;
	Tile* t;

	for (int i = 0; i < rows; i++) {

		/*Push new vector for a row*/
		tile_grid.push_back(vt);

		for (int j = 0; j < columns; j++) {

			t = new Tile;
			t->set_values();

			/*Push tile pointer to vector at ith row*/
			tile_grid.at(i).push_back(t);
		}
	}
}

Tile* Grid::getTile(int row, int column)
{
	return tile_grid.at(row).at(column);
}

Grid::~Grid()
{
}
