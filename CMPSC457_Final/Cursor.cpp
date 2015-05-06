/*	Cursor.cpp 
*	
*	This class is responsible for drawing, moving, and keeping track of the position of the cursor object (white rectangle on screen)
*	The cursor moves from tile to tile. */

#include "Cursor.h"
#include <windows.h>
#include <GL/glut.h>

/* Initialize cursor with r rows and c cols. Initial cursor position = 5,5 */
Cursor::Cursor(int r, int c)
{
	/* These values are used to check if the grid is out of bounds */
	this->rows = r;		// This value should equal the total number of rows in the grid.
	this->cols = c;		// This value should equal the total number of columns in the grid.

	/* These values define what position the cursor is initailized */
	coordinate[0] = 5;	// Starting grid row
	coordinate[1] = 5;	// Starting grid column
}

/* Return array containing the current position of the cursor */
int* Cursor::getPosition()
{
	return coordinate;
}

/* Set the cursor's position */
void Cursor::setPosition(int x, int y)
{
	coordinate[0] = x;
	coordinate[1] = y;
}

/* x = x + 1 */
void Cursor::moveRight()
{
	if (coordinate[0] + 1 < cols)
		coordinate[0] += 1;
}

/* x = x - 1 */
void Cursor::moveLeft()
{
	if (coordinate[0] - 1 >= 0)
		coordinate[0] -= 1;
}

/* z = z - 1 */
void Cursor::moveUp()
{
	if (coordinate[1] - 1 >= 0)
		coordinate[1] -= 1;
}

/* z = z + 1 */
void Cursor::moveDown()
{
	if (coordinate[1] + 1 < rows)
		coordinate[1] += 1;
}

/* Draw the cursor to screen */
void Cursor::draw()
{
	if (selection)
	{
		GLfloat grid_material[4] = { 1.00, 0.00, 0.00, 1.00 };		// Cursor's material color

		glMaterialfv(GL_FRONT, GL_DIFFUSE, grid_material);			// Apply the material
	}
	else
	{
		GLfloat grid_material[4] = { 1.00, 1.00, 1.00, 1.00 };		// Cursor's material color

		glMaterialfv(GL_FRONT, GL_DIFFUSE, grid_material);			// Apply the material
	}

	glPushMatrix();

	glTranslated(coordinate[0], 0.01, coordinate[1]);		// Draw the cursor at its position

	glBegin(GL_POLYGON);
	glVertex3d(-0.45, 0, 0.45);
	glVertex3d(-0.45, 0, 0.5);
	glVertex3d(0.5, 0, 0.5);
	glVertex3d(0.5, 0, 0.45);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(0.45, 0, 0.45);
	glVertex3d(0.5, 0, 0.45);
	glVertex3d(0.5, 0, -0.5);
	glVertex3d(0.45, 0, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(0.45, 0, -0.45);
	glVertex3d(0.45, 0, -0.5);
	glVertex3d(-0.5, 0, -0.5);
	glVertex3d(-0.5, 0, -0.45);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3d(-0.45, 0, -0.45);
	glVertex3d(-0.5, 0, -0.45);
	glVertex3d(-0.5, 0, 0.5);
	glVertex3d(-0.45, 0, 0.5);
	glEnd();

	glPopMatrix();
}

/* Change the cursor's state */
void Cursor::ChangeState()
{
	selection = !selection;
}

/* Destructor */
Cursor::~Cursor()
{
}
