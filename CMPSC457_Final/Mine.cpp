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
	glTranslatef(x, y*-1, z);

	glColor3d(0.5, 0.2, 0.1);

	glPushMatrix();
	glTranslated(0.0, -0.35, 0.0);

	glPushMatrix();
	glTranslated(0.1, 0.0, 0.0);
	glScaled(0.03, 0.25, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.1, 0.0, 0.0);
	glScaled(0.03, 0.25, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.1, 0.0);
	glScaled(0.2, 0.03, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.0, -0.1);
	glScaled(0.2, 0.25, 0.03);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	//Rails
	glPushMatrix();
	glTranslated(0.03, -0.15, 0.1);
	glScaled(0.01, 0.01, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.03, -0.15, 0.1);
	glScaled(0.01, 0.01, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.15, 0.1);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.15, 0.14);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.15, 0.18);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.15, 0.22);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.15, 0.26);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0.0, -0.15, 0.06);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.15, 0.02);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.15, -0.02);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -0.15, -0.06);
	glScaled(0.1, 0.01, 0.01);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	if (y < -0.50)
	{
		Building::is_animating = true;
		y = y + 0.05;
	}
	else
	{
		y = -0.5;
		Building::is_animating = false;
	}
}

void Mine::plop_building()
{

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

void Mine::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 175);
	o.set_employed(o.get_employed() - 4);
	o.set_unemployed(o.get_unemployed() + 4);
}

Mine::~Mine()
{

}