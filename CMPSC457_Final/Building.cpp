#include "Building.h"
#include "GL\freeglut.h"


Building::Building(GLdouble x, GLdouble y, GLdouble z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

GLfloat Building::get_x() 
{
	return x;
}

GLfloat Building::get_y()
{
	return y;
}

GLfloat Building::get_z()
{
	return z;
}

void Building::draw_building() 
{
	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glutSolidCube(1);
	glPopMatrix();
}

Building::~Building()
{
}
