/*	Grid.cpp
*
*	This class is responsible for drawing the world's grid, and maintaining every tile on the grid */

#include "Grid.h"
#include <iostream>
#include <GL/glut.h>

/* Overriden Constructor */
Grid::Grid(int rows, int columns)
{
	this->rows = rows;			// Set number of rows to draw
	this->columns = columns;	// Set number of columns to draw
	std::vector<Tile*> vt;		// Initialize vector of Tile objects for each grid element
	Tile* t;					// Initialize a Tile pointer to be used below

	for (int i = 0; i < rows; i++) {

		/*Push new vector for a row*/
		tile_grid.push_back(vt);

		for (int j = 0; j < columns; j++) {

			t = new Tile;		// Create a new Tile
			t->set_values();	// Set the tile's raw resource values randomly

			/*Push tile pointer to vector at ith row*/
			tile_grid.at(i).push_back(t);
		}
	}
}

/* Draw a portion of the grid (this is called by drawGrid)*/
void Grid::drawSubgrid(double xi, double zi)
{
	glPushMatrix();

	glTranslated(xi, 0, zi);

	glBegin(GL_POLYGON);			// Draw a grid sqaure, which denotes one tile.
	glNormal3d(0.0, 1.0, 0.0);
	glVertex3d(-0.5, 0, -0.5);
	glVertex3d(0.5, 0, -0.5);
	glVertex3d(0.5, 0, 0.5);
	glVertex3d(-0.5, 0, 0.5);
	glEnd();

	glPopMatrix();
}

/* Draw the entire grid */
void Grid::drawGrid()
{
	glColor3d(0.0, 0.5, 0.1);

	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			drawSubgrid(column, row);		// Draw every row and column
		}
	}
}

/* Get a Tile at a specified location from the tile vector */
Tile* Grid::getTile(int row, int column)
{
	return tile_grid.at(row).at(column);
}

/* Destructor */
Grid::~Grid()
{
}
