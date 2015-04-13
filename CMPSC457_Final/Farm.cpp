#include "Farm.h"

Farm::Farm(GLdouble x, GLdouble y, GLdouble z) : Building(x, y, z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Farm::draw_building()
{
	glPushMatrix();
	glColor3f(0.69, 0.00, 0.16);
	glTranslatef(x, y*-1, z);
	glutSolidCube(1);
	glPopMatrix();
}

void Farm::apply_perk(OutputResources &o)
{
	o.set_food(o.get_food() + t.get_soil());
}

void Farm::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 150);
	o.set_unemployed(o.get_unemployed() - 2);
}

void Farm::apply_cost_per_tick(OutputResources &o)
{
	o.set_money(o.get_money() - 2 * ((o.get_employed() / 20) + 1));
}

Farm::~Farm()
{

}


