#include "Mine.h"

Mine::Mine(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Mine::draw_building()
{
	glPushMatrix();
	glColor3f(1.00, 0.94, 0.00);
	glTranslatef(x, y*-1, z);
	glutSolidCube(1);
	glPopMatrix();
}

void Mine::apply_perk(OutputResources &o)
{
	o.set_bricks(o.get_bricks() + t.get_stone());
}

std::string Mine::check_cost(OutputResources& o)
{
	if (o.get_money() < 350)
	{
		return "Not Enough Money";
	}
	else if (o.get_unemployed() < 4)
	{
		return "Not Enough Unemployed";
	}
	else
	{
		return "Good";
	}
}

void Mine::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 350);
	o.set_unemployed(o.get_unemployed() - 4);
	o.set_employed(o.get_employed() + 4);
}

bool Mine::apply_cost_per_tick(OutputResources &o)
{
	if (o.get_money() >= 3 * ((o.get_employed() / 25) + 1))
	{
		o.set_money(o.get_money() - 3 * ((o.get_employed() / 25) + 1));
		return true;
	}
	else
	{
		return false;
	}
}

Mine::~Mine()
{

}