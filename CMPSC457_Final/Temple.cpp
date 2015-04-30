#include "Temple.h"

Temple::Temple(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Temple::draw_building()
{
	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glTranslatef(0.0, -0.5, 0.0);

	//Stairs
	glColor3d(0.54, 0.35, 0.30);
	glPushMatrix();
	glTranslated(0.0, 0.01, 0.2);
	glScaled(0.3, 0.005, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.015, 0.175);
	glScaled(0.3, 0.005, 0.25);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.02, 0.15);
	glScaled(0.3, 0.005, 0.20);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.025, 0.125);
	glScaled(0.3, 0.005, 0.15);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.030, 0.100);
	glScaled(0.3, 0.005, 0.10);
	glutSolidCube(1.0);
	glPopMatrix();

	//railing
	glColor3d(0.58, 0.58, 0.58);
	glPushMatrix();
	glTranslated(0.175, 0.045, 0.2);
	glScaled(0.05, 0.075, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.175, 0.045, 0.2);
	glScaled(0.05, 0.075, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	//middle platform
	glColor3d(0.54, 0.35, 0.30);
	glPushMatrix();
	glTranslated(0.0, 0.02, -0.15);
	glScaled(0.7, 0.025, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();


	//side railings
	glColor3d(0.58, 0.58, 0.58);
	glPushMatrix();
	glTranslated(0.325, 0.055, -0.15);
	glScaled(0.05, 0.055, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.325, 0.055, -0.15);
	glScaled(0.05, 0.055, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	//front railings
	glPushMatrix();
	glTranslated(0.25, 0.055, 0.025);
	glScaled(0.2, 0.055, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.25, 0.055, 0.025);
	glScaled(0.2, 0.055, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	//back railing
	glPushMatrix();
	glTranslated(0.0, 0.055, -0.325);
	glScaled(0.7, 0.055, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	//middle towers
	glColor3d(0.39, 0.23, 0.19);
	glPushMatrix();
	glTranslated(0.0, 0.06, -0.1);
	glScaled(0.1, 0.1, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.085, -0.15);
	glScaled(0.15, 0.15, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.125, -0.215);
	glScaled(0.2, 0.2, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	//front towers
	glPushMatrix();
	glTranslated(-0.25, 0.125, -0.25);
	glScaled(0.05, 0.2, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.25, 0.125, -0.25);
	glScaled(0.05, 0.2, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.25, 0.1075, 0.25);
	glScaled(0.05, 0.2, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.25, 0.1075, 0.25);
	glScaled(0.05, 0.2, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();
}

std::string Temple::check_cost(OutputResources& o)
{
	return "Good";
}

void Temple::apply_perk(OutputResources &o)
{
	o.set_money(o.get_money() + 1);
}

void Temple::apply_initial_cost(OutputResources &o)
{

}

bool Temple::apply_cost_per_tick(OutputResources &o)
{
	return true;
}

Temple::~Temple()
{

}