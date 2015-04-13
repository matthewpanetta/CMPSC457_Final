#include "Mill.h"

Mill::Mill(GLdouble x, GLdouble y, GLdouble z) : Building(x, y, z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Mill::draw_building()
{
	
}

void Mill::apply_perk(OutputResources &o)
{
	o.set_wood(o.get_wood() + t.get_trees());
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
