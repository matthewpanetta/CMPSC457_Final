#include "Building.h"
#include "GL\freeglut.h"

Building::Building(GLdouble x, GLdouble y, GLdouble z, Tile t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

Tile Building::get_tile()
{
	return t;
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

bool Building::compare(const Building& b) const
{
	if (x == b.x && y == b.y && z == b.z && t == b.t) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Building::~Building()
{

}
