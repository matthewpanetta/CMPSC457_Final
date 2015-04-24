#include "Cursor.h"
#include <windows.h>
#include <GL/glut.h>

//Initialize cursor with r rows and c cols. Initial cursor position = 0,0
Cursor::Cursor(int r, int c)
{
	this->rows = r;
	this->cols = c;

	coordinate[0] = 5;
	coordinate[1] = 5;
}

//Return array containing the current position of the cursor
int* Cursor::getPosition()
{
	return coordinate;
}

//x = x + 1
void Cursor::moveRight()
{
	if (coordinate[0] + 1 < cols)
		coordinate[0] += 1;
}

//x = x - 1
void Cursor::moveLeft()
{
	if (coordinate[0] - 1 >= 0)
		coordinate[0] -= 1;
}

//z = z - 1
void Cursor::moveUp()
{
	if (coordinate[1] - 1 >= 0)
		coordinate[1] -= 1;
}

//z = z + 1
void Cursor::moveDown()
{
	if (coordinate[1] + 1 < rows)
		coordinate[1] += 1;
}

//draw a cursor
void Cursor::draw()
{
	if (selection)
	{
		glColor3d(1.0, 0.0, 0.0);
	}
	else
	{
		glColor3d(1.0, 1.0, 1.0);
	}

	glPushMatrix();

	glTranslated(coordinate[0], 0.01, coordinate[1]);

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

void Cursor::ChangeState()
{
	selection = !selection;
}

Cursor::~Cursor()
{
}
