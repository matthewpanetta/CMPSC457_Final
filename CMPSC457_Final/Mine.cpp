/*	Mine.cpp
*
*	This class is responsible for creating a Mine object and drawing it to the screen. */

#include "Mine.h"

/* Default Constructor - initialize the superclass of Building */
Mine::Mine(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

/* Draw the building to screen */
void Mine::draw_building()
{
	GLfloat mine_material[4] = { 0.50, 0.20, 0.10, 1.00 };
	GLfloat rails_material[4] = { 0.20, 0.20, 0.20, 1.00 };

	glPushMatrix();
	glTranslatef(x, y*-1, z);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mine_material);

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

	glMaterialfv(GL_FRONT, GL_DIFFUSE, rails_material);
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

	// Animation checking
	// Each building will fly in from the sky and continue to fall until it lands on the grid.

	if (y < -0.50)		// If the building's Y position is below -0.50 (grid Y coordinate)
	{
		Building::is_animating = true;		// The building is animating
		y = y + 0.05;						// Increment the Y value (moving it up). This is because the Y value is inverted in the draw_building function.
	}
	else				// If the building's Y position is on the ground (or above -0.50)
	{
		y = -0.50;							// Set the Y coordinate to -0.50
		Building::is_animating = false;		// Set the animation flag to false.
	}
}

/* Apply the Mine's benefit per tick */
void Mine::apply_perk(OutputResources &o)
{
	o.set_bricks(o.get_bricks() + t.get_stone());	// Give (tile's bricks rating) stone per tick.
}

/* Check if the user has enough resources to build a mine. If not, return a message with needed resource */
// Note that this function will return on the first failure. So the message will display only one resource.
std::string Mine::check_cost(OutputResources& o)
{
	if (o.get_money() < 350)						// Mine costs $350
	{
		return "Not Enough Money";
	}
	else if (o.get_unemployed() < 4)				// 4 unemployed
	{
		return "Not Enough Unemployed";
	}
	else
	{
		return "Good";								// If the user has enough resources, return a success message that will not be displayed.
	}
}

/* Deduct the user's resources based on how much this building costs */
void Mine::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 350);				// Mine costs $350
	o.set_unemployed(o.get_unemployed() - 4);		// Take 4 unemployed people
	o.set_employed(o.get_employed() + 4);			// Make them employed
}

/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
bool Mine::apply_cost_per_tick(OutputResources &o)
{
	if (o.get_money() >= 3)
	{
		o.set_money(o.get_money() - 3);				// Mine requires $3 per tick.
		return true;
	}
	else
	{
		return false;								// Return false if user does not have sufficient amount of resources.
	}
}

/* Add to the user's resources if they decide to remove a mine */
void Mine::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 175);				// Give $175
	o.set_employed(o.get_employed() - 4);			// Take the 4 employed people
	o.set_unemployed(o.get_unemployed() + 4);		// Make them unemployed
}

/* Destructor */
Mine::~Mine()
{

}