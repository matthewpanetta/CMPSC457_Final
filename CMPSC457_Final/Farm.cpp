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
	glTranslatef(x, y*-1, z);
	glTranslatef(0.0, -0.12, 0.0);
	// barn
	glPushMatrix();
	glColor3f(0.89, 0.13, 0.11);
	glScalef(1.0, 0.75, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();

	// window
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-0.15, -0.05, 0.53);
	glScalef(1.5, 3.0, 1.0);

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
	glTranslatef(0.0, 0.58, 0.0);
	glScalef(0.55, 0.2, 0.5);
	glBegin(GL_TRIANGLES);

	// Front
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Right
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Back
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// Left
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


