#include "House.h"

House::House(GLdouble x, GLdouble y, GLdouble z) : Building(x, y, z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void House::draw_building()
{
	glPushMatrix();
	glColor3f(0.98, 0.81, 0.69);
	glTranslatef(x, y*-1, z);
	glutSolidCube(1);
	glPopMatrix();
}

void House::apply_perk(OutputResources &o)
{
	o.set_food(o.get_food() + (t.get_soil() - t.get_stone()));
}

void House::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 400);
	o.set_wood(o.get_wood() - 5);
	o.set_bricks(o.get_bricks() - 20);
}

void House::apply_cost_per_tick(OutputResources &o)
{
	o.set_food(o.get_food() - 6);
	o.set_wood(o.get_wood() - 5);
}

House::~House()
{

}


