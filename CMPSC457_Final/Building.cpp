#include "Building.h"
#include "GL\freeglut.h"


Building::Building()
{
}

float Building::get_x() 
{
	return x;
}

float Building::get_y()
{
	return y;
}

void Building::draw_building() 
{
	glPushMatrix();
	glutSolidCube(1);
	glPopMatrix();
}

Building::~Building()
{
}
