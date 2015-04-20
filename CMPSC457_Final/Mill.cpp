#include "Mill.h"

Mill::Mill(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Mill::draw_building()
{
	glPushMatrix();
	glColor3f(0.54, 0.20, 0.14);
	glTranslatef(x, y*-1, z);
	glutSolidCube(1);
	glPopMatrix();
}

void Mill::apply_perk(OutputResources &o)
{
	o.set_wood(o.get_wood() + t.get_trees());
}
std::string Mill::check_cost(OutputResources& o)
{
	if (o.get_money() < 300)
	{
		return "Not Enough Money";
	}
	else if (o.get_unemployed() < 3)
	{
		return "Not Enough Unemployed";
	}
	else
	{
		return "Good";
	}
}


void Mill::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 300);
	o.set_unemployed(o.get_unemployed() - 3);
}

void Mill::apply_cost_per_tick(OutputResources &o)
{
	o.set_money(o.get_money() - 1 * ((o.get_employed() / 15) + 1));
}

Mill::~Mill()
{
}
