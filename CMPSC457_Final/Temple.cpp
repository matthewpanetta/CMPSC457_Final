#include "Temple.h"

Temple::Temple(GLdouble x, GLdouble y, GLdouble z) : Building(x, y, z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Temple::draw_building()
{

}

void Temple::apply_perk(OutputResources &o)
{

}

void Temple::apply_initial_cost(OutputResources &o)
{

}

void Temple::apply_cost_per_tick(OutputResources &o)
{

}

Temple::~Temple()
{

}