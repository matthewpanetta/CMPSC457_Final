#include "Temple.h"

Temple::Temple(GLdouble x, GLdouble y, GLdouble z) : Building(x, y, z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Temple::set_tile(Tile t)
{
	this->t = t;
}

Temple::~Temple()
{

}