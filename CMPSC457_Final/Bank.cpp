#include "Bank.h"

Bank::Bank(GLdouble x, GLdouble y, GLdouble z) : Building(x, y, z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bank::draw_building()
{

}

void Bank::apply_perk(OutputResources &o)
{
	o.set_money(o.get_money() + (t.get_stone() - t.get_trees()));
}

void Bank::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 1000);
	o.set_wood(o.get_wood() - 40);
	o.set_bricks(o.get_bricks() - 30);
}

void Bank::apply_cost_per_tick(OutputResources &o)
{
	o.set_food(o.get_food() - 10);
	o.set_wood(o.get_wood() - 3);
}

Bank::~Bank()
{

}


