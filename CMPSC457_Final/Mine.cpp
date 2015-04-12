#include "Mine.h"

Mine::Mine(GLdouble x, GLdouble y, GLdouble z) : Building(x, y, z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Mine::set_tile(Tile t)
{
	this->t = t;
}

void Mine::apply_perk(OutputResources &o)
{
	o.set_bricks(o.get_bricks() + t.get_stone());
}

void Mine::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 350);
	o.set_unemployed(o.get_unemployed() - 4);
}

void Mine::apply_cost_per_tick(OutputResources &o)
{
	o.set_money(o.get_money() - 3 * ((o.get_employed() / 25) + 1));
}

Mine::~Mine()
{

}