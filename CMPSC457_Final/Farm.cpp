#include "Farm.h"

Farm::Farm(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Farm::draw_building()
{
	glPushMatrix();

	glTranslatef(x, y*-1, z + 0.0);
	glTranslatef(0.0, -0.4, 0.0);
	glScalef(0.9, 1.0, 0.9);
	// barn
	glPushMatrix();
	glColor3f(0.89, 0.13, 0.11);
	glScalef(1.0, 0.75, 1.0);
	glScaled(0.2, 0.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();

	// window
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-0.03, 0.00, 0.101);
	glScalef(1.5, 3.0, 1.0);
	glScaled(0.2, 0.2, 0.2);

	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.2, 0.0, 0.0);
	glVertex3f(0.2, -0.1, 0.0);
	glVertex3f(0.0, -0.1, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.2, -0.1, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.2, 0.0, 0.0);
	glVertex3f(0.0, -0.1, 0.0);
	glEnd();

	glPopMatrix();

	// roof
	glPushMatrix();
	glTranslatef(0.0, 0.115, 0.0);
	glScalef(0.55, 0.2, 0.5);
	glScaled(0.2, 0.2, 0.2);
	glBegin(GL_TRIANGLES);

	// Front
	glNormal3d(0.0, 0.5, 0.5);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Right
	glNormal3d(0.5, 0.5, 0.0);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Back
	glNormal3d(0.0, 0.5, -0.5);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// Left
	glNormal3d(-0.5, 0.5, 0.0);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void Farm::apply_perk(OutputResources &o)
{
	o.set_food(o.get_food() + t.get_soil());
}

std::string Farm::check_cost(OutputResources& o)
{
	if (o.get_money() < 150)
	{
		return "Not Enough Money";
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

void Farm::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 150);
	o.set_unemployed(o.get_unemployed() - 2);
}

bool Farm::apply_cost_per_tick(OutputResources &o)
{
	if (o.get_money() >= 2 * ((o.get_employed() / 20) + 1))
	{
		o.set_money(o.get_money() - 2 * ((o.get_employed() / 20) + 1));
		return true;
	}
	else
	{
		return false;
	}
}

Farm::~Farm()
{

}


