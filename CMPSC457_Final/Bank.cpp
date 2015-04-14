#include "Bank.h"

Bank::Bank(GLdouble x, GLdouble y, GLdouble z) : Building(x, y, z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Bank::draw_building()
{
	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glScalef(0.9, 1.0, 0.8);

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
	glPushMatrix();
	glTranslatef(0.0, 0.5, 0.0);
	glScalef(0.55, 0.3, 0.9);
	glColor3f(0.30, 0.30, 0.30);
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


