/*	Temple.cpp
*
*	This class is responsible for creating a Temple object and drawing it to the screen. */

#include "Temple.h"
#include "World.h"

/* Default Constructor - initialize the superclass of Building */
Temple::Temple(GLdouble x, GLdouble y, GLdouble z, Tile t, std::vector<Texture> &images) : Building(x, y, z, t, images)
{
	this->t = t;
	this->x = x;
	this->y = -0.5;
	this->z = z;
	ground_tex = this->images.at(14);
}

/* Draw the building to screen */
void Temple::draw_building()
{
	GLfloat stair_material[4] = { 0.54, 0.35, 0.30, 1.00 };
	GLfloat railing_material[4] = { 0.58, 0.58, 0.58, 1.00 };
	GLfloat mid_plat_material[4] = { 0.54, 0.35, 0.30, 1.00 };
	GLfloat side_rail_material[4] = { 0.58, 0.58, 0.58, 1.00 };
	GLfloat front_rail_material[4] = { 0.25, 0.055, 0.025, 1.00 };
	GLfloat middle_towers_material[4] = { 0.39, 0.23, 0.19, 1.00 };

	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glTranslatef(0.0, -0.5, 0.0);

	//Stairs
	glMaterialfv(GL_FRONT, GL_DIFFUSE, stair_material);
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
	glMaterialfv(GL_FRONT, GL_DIFFUSE, railing_material);
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
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mid_plat_material);
	glPushMatrix();
	glTranslated(0.0, 0.02, -0.15);
	glScaled(0.7, 0.025, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();


	//side railings
	glMaterialfv(GL_FRONT, GL_DIFFUSE, side_rail_material);
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
	glMaterialfv(GL_FRONT, GL_DIFFUSE, middle_towers_material);
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

	// draw ground
	glPushMatrix();
	glTranslatef(0.00, -0.005, 0.00);
	glScalef(0.47, 0.01, 0.47);
	draw_plane(ground_tex.get_image());
	glPopMatrix();

	glPopMatrix();
}

/* Check if the user has enough resources to build a bank. If not, return a message with needed resource */
// Note that since the user cannot create a temple, it does not check anything.
std::string Temple::check_cost(OutputResources& o)
{
	return "Good";
}

/* Check to see if the building can be deleted. */
std::string Temple::check_delete(OutputResources& o)
{
	return "Can't Delete Temple";						// Temples cannot be deleted.
}

/* Apply the Temple's benefit per tick */
void Temple::apply_perk(OutputResources &o)
{
	o.set_money(o.get_money() + 1);		// Give $1 per tick
}

/* Deduct the user's resources based on how much this building costs */
void Temple::apply_initial_cost(OutputResources &o)
{
	// No initial cost
}

/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
bool Temple::apply_cost_per_tick(OutputResources &o)
{
	return true;		// There is no cost per tick, so this will always be true.
}

/* User cannot remove a temple */
void Temple::delete_benefit(OutputResources &o)
{
	// The user cannot delete the temple object. There is nothing here.
}

/* Destructor */
Temple::~Temple()
{

}