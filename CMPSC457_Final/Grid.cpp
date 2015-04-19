#include "Grid.h"
#include <iostream>
#include <GL/glut.h>

Grid::Grid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	std::vector<Tile*> vt;
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

void Grid::drawSubgrid(double xi, double zi, double color[3])
{

	glColor3d(color[0], color[1], color[2]);

	glPushMatrix();

	glTranslated(xi, 0, zi);

	glBegin(GL_POLYGON);
	glVertex3d(-0.5, 0, -0.5);
	glVertex3d(0.5, 0, -0.5);
	glVertex3d(0.5, 0, 0.5);
	glVertex3d(-0.5, 0, 0.5);
	glEnd();

	glPopMatrix();
}

void Grid::drawGrid()
{
	double color[3] = { 255, 0, 0 };

	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			color[1] = row * 0.1;
			color[2] = column * 0.1;
			drawSubgrid(column, row, color);
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
