#include "Temple.h"

Temple::Temple(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Temple::draw_building()
{
	glPushMatrix();
	glColor3f(0.18, 0.31, 0.31);
	glTranslatef(x, y*-1, z);
	glutSolidCube(1);
	glPopMatrix();
}

std::string Temple::check_cost(OutputResources& o)
{
	return "Good";
}

void Temple::apply_perk(OutputResources &o)
{

}

void Temple::apply_initial_cost(OutputResources &o)
{

}

bool Temple::apply_cost_per_tick(OutputResources &o)
{
	return false;
}

Temple::~Temple()
{

}