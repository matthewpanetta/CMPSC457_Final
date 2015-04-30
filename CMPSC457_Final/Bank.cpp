#include "Bank.h"

Bank::Bank(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bank::draw_building()
{
	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.40, 0.40, 0.40);

	// draw building
	glPushMatrix();
	glColor3f(0.52, 0.52, 0.52);
	glTranslatef(0.0, -0.2, -0.1);
	glScalef(0.9, 0.6, 0.85);
	glutSolidCube(1);
	glPopMatrix();

	// draw floor
	glPushMatrix();
	glColor3f(0.85, 0.82, 0.89);
	glTranslatef(0.0, -0.5, 0.0);
	glScalef(1.0, 0.05, 1.0);
	glutSolidCube(1);

	// draw elevated floor
	glColor3f(0.73, 0.70, 0.71);
	glTranslatef(0.0, 1.0, 0.0);
	glScalef(0.95, 1.0, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	// draw four pillars
	glPushMatrix();
	glColor3f(0.86, 0.89, 0.91);
	glTranslatef(-0.4, -0.2, 0.4);
	glScalef(0.1, 0.6, 0.1);
	glutSolidCube(1);

	glTranslatef(2.7, 0.0, 0.0);
	glutSolidCube(1);

	glTranslatef(2.7, 0.0, 0.0);
	glutSolidCube(1);

	glTranslatef(2.7, 0.0, 0.0);
	glutSolidCube(1);
	glPopMatrix();

	// draw roof
	glColor3f(0.37, 0.37, 0.37);
	glTranslatef(0.0, -0.25, 0.0);
	draw_roof();
	glPopMatrix();
}

void Bank::apply_perk(OutputResources &o)
{
	o.set_money(o.get_money() + (t.get_stone() - t.get_trees()));
}

std::string Bank::check_cost(OutputResources& o)
{
	if (o.get_money() < 1000)
	{
		return "Not Enough Money";
	}
	else if (o.get_wood() < 40)
	{
		return "Not Enough Wood";
	}
	else if (o.get_bricks() < 30)
	{
		return "Not Enough Bricks";
	}
	else if (o.get_unemployed() < 2)
	{
		return "Not Enough Unemployed";
	}
	else
	{
		return "Good";
	}
}

void Bank::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 1000);
	o.set_wood(o.get_wood() - 40);
	o.set_bricks(o.get_bricks() - 30);
	o.set_unemployed(o.get_unemployed() - 2);
	o.set_employed(o.get_employed() + 2);
}

bool Bank::apply_cost_per_tick(OutputResources &o)
{
	if (o.get_food() >= 10 && o.get_wood() >= 3)
	{
		o.set_food(o.get_food() - 10);
		o.set_wood(o.get_wood() - 3);
		return true;
	}
	else
	{
		return false;
	}
}

void Bank::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 500);
	o.set_employed(o.get_employed() - 2);
	o.set_unemployed(o.get_unemployed() + 2);
}

Bank::~Bank()
{

}


