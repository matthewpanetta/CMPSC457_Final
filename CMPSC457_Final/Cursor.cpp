#include "Cursor.h"
#include <windows.h>
#include <GL/glut.h>

//Initialize cursor to 0,0 (x,z)
Cursor::Cursor()
{
	coordinate[0] = 5;
	coordinate[1] = 9;
}

//Return array containing the current position of the cursor
int* Cursor::getPostion()
{
	return coordinate;
}

//x = x + 1
void Cursor::moveRight()
{
	coordinate[0] += 1;
}

//x = x - 1
void Cursor::moveLeft()
{
	coordinate[0] -= 1;
}

//z = z + 1
void Cursor::moveUp()
{
	coordinate[1] -= 1;
}

//z = z - 1
void Cursor::moveDown()
{
	coordinate[1] += 1;
}

//draw a cursor
void Cursor::draw()
{
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

Cursor::~Cursor()
{
}
