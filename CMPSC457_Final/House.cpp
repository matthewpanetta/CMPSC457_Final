/*	House.cpp
*
*	This class is responsible for creating a House object and drawing it to the screen. */

#include "House.h"
#include "Texture.h"

/* Default Constructor - initialize the superclass of Building */
House::House(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
	this->type = rand() % 10 + 1;		// There are three different house textures. Choose one randomly.

	if (type > 7)						// If the random value is greater than 7, display a wooden house
	{
		house_tex.set_filename("../Pictures/wood_house.bmp");
		tex.set_filename("../Pictures/house_grass_dark.bmp");
	}
	else if (type <= 7 && type > 3)		// If the random value is within this range, display a brick house.
	{
		house_tex.set_filename("../Pictures/brick_house.bmp");
		tex.set_filename("../Pictures/house_grass.bmp");
	}
	else								// Otherwise, display a house with siding.
	{
		house_tex.set_filename("../Pictures/house_siding.bmp");
		tex.set_filename("../Pictures/house_grass.bmp");
	}
}

/* Draw the building to screen */
void House::draw_building()
{
	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glTranslatef(0.0, -0.31, -0.25);
	glScalef(0.5, 0.5, 0.5);

	// house
	glPushMatrix();
	glScalef(0.49, 0.38, 0.50);
	
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0, 1.0, 1.0);
	
	draw_plane(house_tex.get_image());		// draw house with texture

	glEnd();	// done with the polygon.
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	// door
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-0.15, -0.05, 0.53);
	glScalef(1.5, 3.0, 1.0);

	glColor3f(0.82, 0.82, 0.82);
	glTranslatef(0.2, -0.04, -0.1);
	glScalef(0.15, 0.15, 0.15);
	glutSolidCube(1);

	glColor3f(0.55, 0.55, 0.0);
	glTranslatef(0.0, 0.0, 0.8);
	glutSolidSphere(0.1, 20, 20);
	glPopMatrix();

	// window
	glPushMatrix();
	glColor3f(0.92, 0.92, 0.92);
	glTranslatef(-0.25, 0.1, 0.39);
	glScalef(0.25, 0.25, 0.25);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

	// roof
	glColor3f(0.17, 0.17, 0.17);
	draw_roof();

	glPushMatrix();
	glTranslatef(0.0, -0.38, 0.5);
	glScalef(0.9, 0.01, 0.9);
	glColor3f(1.0, 1.0, 1.0);

	draw_plane(tex.get_image());	// draw grass texture

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

/* Check if the user has enough resources to build a house. If not, return a message with needed resource */
// Note that this function will return on the first failure. So the message will display only one resource.
std::string House::check_cost(OutputResources &o)
{
	if (o.get_money() < 100)				// House costs $100
	{
		return "Not Enough Money";
	}
	else if (o.get_wood() < 5)				// 5 wood
	{
		return "Not Enough Wood";
	}
	else if (o.get_bricks() < 25)			// 25 bricks
	{
		return "Not Enough Bricks";
	}
	else
	{
		return "Good";						// If the user has enough resources, return a success message that will not be displayed.
	}
}

/* Apply the House's benefit per tick */
void House::apply_perk(OutputResources &o)
{
	// No benefit per tick
}

/* Deduct the user's resources based on how much this building costs */
void House::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 100);				// House costs $100
	o.set_wood(o.get_wood() - 5);					// 5 wood
	o.set_bricks(o.get_bricks() - 25);				// 25 bricks
	o.set_unemployed(o.get_unemployed() + 3);		// Receive 3 unemployed workers
}

/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
bool House::apply_cost_per_tick(OutputResources &o)
{
	o.set_food(o.get_food() - 2);					// House requires 2 food per tick and
	o.set_wood(o.get_wood() - 1);					// 1 wood per tick
	return true;
}

/* Add to the user's resources if they decide to remove a house */
void House::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 50);				// Get $50 back
	
	// BUG in code: Delete a house, take away 3 population. Do we take away from unemployed or employed? Do we need to map each person to an occupation to solve this issue?
	// If the user deletes houses, the population counter will be wrong.
	if (o.get_employed() > o.get_unemployed())
	{
		o.set_employed(o.get_employed() - 3);		// If there are more employed people than unemployed people, take 3 employed people.
	}
	else
	{
		o.set_unemployed(o.get_unemployed() - 3);	// Otherwise, take three unemployed people.
	}
}

/* Destructor */
House::~House()
{

}


