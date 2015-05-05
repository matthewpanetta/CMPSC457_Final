/*	Farm.cpp
*
*	This class is responsible for creating a Farm object and drawing it to the screen. */

#include "Farm.h"

/* Default Constructor - initialize the superclass of Building */
Farm::Farm(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t), ground_tex("../Pictures/farm_four_tile.bmp"), farm_tex("../Pictures/barn.bmp")
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

/* Draw the building to screen */
void Farm::draw_building()
{
	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glTranslatef(0.0, -0.31, -0.25);
	glScalef(0.5, 0.5, 0.5);

	// barn
	glPushMatrix();
	glColor3f(0.89, 0.13, 0.11);
	glScalef(0.49, 0.38, 0.50);
	
	draw_plane(farm_tex.get_image());	// apply texture to the barn

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
	glColor3f(0.92, 0.92, 0.92);
	draw_roof();

	// apply texture to the ground
	glTranslatef(0.0, -0.38, 0.5);
	glScalef(0.9, 0.01, 0.9);
	glColor3f(1.0, 1.0, 1.0);
	draw_plane(ground_tex.get_image());

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

/* Apply the Farm's benefit per tick */
void Farm::apply_perk(OutputResources &o)
{
	o.set_food(o.get_food() + t.get_soil());		// Give (tile soil) food per tick.
}

/* Check if the user has enough resources to build a farm. If not, return a message with needed resource */
// Note that this function will return on the first failure. So the message will display only one resource.
std::string Farm::check_cost(OutputResources& o)
{
	if (o.get_money() < 150)				// Farm costs $150
	{
		return "Not Enough Money";
	}
	else if (o.get_unemployed() < 2)		// 2 unemployed
	{
		return "Not Enough Unemployed";
	}
	else
	{
		return "Good";							// If the user has enough resources, return a success message that will not be displayed.
	}
}

/* Deduct the user's resources based on how much this building costs */
void Farm::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 150);			// Farm costs $150
	o.set_unemployed(o.get_unemployed() - 2);	// 2 unemployed
	o.set_employed(o.get_employed() + 2);		// Make 2 employed
}

/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
bool Farm::apply_cost_per_tick(OutputResources &o)
{
	o.set_money(o.get_money() - 1);				// Farm costs $1 per tick
	return true;
}

/* Add to the user's resources if they decide to remove a farm */
void Farm::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 75);			// Get $75 back
	o.set_employed(o.get_employed() - 2);		// Take two employed
	o.set_unemployed(o.get_unemployed() + 2);	// Make them unemployed.
}

/* Destructor */
Farm::~Farm()
{

}