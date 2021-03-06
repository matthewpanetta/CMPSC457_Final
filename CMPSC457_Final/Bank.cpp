/*	Bank.cpp
*
*	This class is responsible for creating a Bank object and drawing it to the screen. */

#include "Bank.h"
#include "World.h"

/* Default Constructor - initialize the superclass of Building */
Bank::Bank(GLdouble x, GLdouble y, GLdouble z, Tile t, std::vector<Texture> &images) : Building(x, y, z, t, images)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

/* Draw the building to screen */
void Bank::draw_building()
{
	/* Materials */
	GLfloat building_material[4] = { 0.52, 0.52, 0.52, 1.00 };
	GLfloat floor_material[4] = { 0.85, 0.82, 0.89, 1.00 };
	GLfloat pillar_material[4] = { 0.86, 0.89, 0.91, 1.00 };
	GLfloat roof_material[4] = { 0.37, 0.37, 0.37, 1.00 };

	/* Lights */
	GLfloat bank_light_diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat bank_light_position[4] = { 0.0, 0.0, 0.0, 1.0 };

	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.40, 0.40, 0.40);

	// draw building
	glPushMatrix();
	//glColor3f(0.52, 0.52, 0.52);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, building_material);
	glLightfv(GL_FRONT, GL_POSITION, bank_light_position);
	glLightfv(GL_FRONT, GL_DIFFUSE, bank_light_diffuse);
	glTranslatef(0.0, -0.2, -0.1);
	glScalef(0.9, 0.6, 0.85);
	glutSolidCube(1);
	glPopMatrix();

	// draw floor
	glPushMatrix();
	//glColor3f(0.85, 0.82, 0.89);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, floor_material);
	glTranslatef(0.0, -0.5, 0.0);
	glScalef(1.0, 0.05, 1.0);
	glutSolidCube(1);

	// draw elevated floor
	//glColor3f(0.73, 0.70, 0.71);
	glTranslatef(0.0, 1.0, 0.0);
	glScalef(0.95, 1.0, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	// draw four pillars
	glPushMatrix();
	//glColor3f(0.86, 0.89, 0.91);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pillar_material);
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

	// draw ground
	glPushMatrix();
	glTranslatef(0.00, -0.62, 0.00);
	glScalef(1.13, 0.01, 1.11);
	draw_plane(this->images.at(13).get_image());
	glPopMatrix();

	// draw roof
	//glColor3f(0.37, 0.37, 0.37);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, roof_material);
	glTranslatef(0.0, -0.25, 0.0);
	draw_roof();
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

/* Apply the Bank's benefit per tick */
void Bank::apply_perk(OutputResources &o)
{
	if (o.get_current_event() == "Fraud")
	{
		o.set_money(o.get_money() + ((t.get_stone() - t.get_trees()) * 0.25));		// Banks operate at 25% efficiency during fraud.
	}
	// Note: During depression, banks do not generate any money.
	else if (o.get_current_event() != "Depression")
	{
		o.set_money(o.get_money() + (t.get_stone() - t.get_trees()));				// Give (tile stone - tile trees) money per tick.
	}
}

/* Check if the user has enough resources to build a bank. If not, return a message with needed resource */
// Note that this function will return on the first failure. So the message will display only one resource.
std::string Bank::check_cost(OutputResources& o)
{
	if (o.get_money() < 1000)			// Bank costs $1000
	{
		return "Not Enough Money";
	}
	else if (o.get_wood() < 40)			// 40 wood
	{
		return "Not Enough Wood";
	}
	else if (o.get_bricks() < 30)		// 30 bricks
	{
		return "Not Enough Bricks";
	}
	else if (o.get_unemployed() < 2)	// 2 unemployed
	{
		return "Not Enough Unemployed";
	}
	else								// If the user has enough resources, return a success message that will not be displayed.
	{
		return "Good";
	}
}

/* Check to see if the building can be deleted. */
std::string Bank::check_delete(OutputResources& o)
{
	return "Good";						// Banks can always be deleted, so return success.
}

/* Deduct the user's resources based on how much this building costs */
void Bank::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 1000);				// Bank costs $1000
	o.set_wood(o.get_wood() - 40);					// 40 wood
	o.set_bricks(o.get_bricks() - 30);				// 30 bricks
	o.set_unemployed(o.get_unemployed() - 2);		// 2 unemployed
	o.set_employed(o.get_employed() + 2);			// Make 2 new employed
}

/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
bool Bank::apply_cost_per_tick(OutputResources &o)
{
	if (o.get_food() >= 10 && o.get_wood() >= 3)	// Bank requires 10 food and 3 woord per tick
	{
		o.set_food(o.get_food() - 10);				// Deduct resources
		o.set_wood(o.get_wood() - 3);
		return true;
	}
	else
	{
		return false;								// Return false if user does not have sufficient amount of resources.
	}
}

/* Add to the user's resources if they decide to remove a bank */
void Bank::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 500);				// Return half of the bank's initial building cost. ($500)
	o.set_employed(o.get_employed() - 2);			// Take two employed people and make them unemployed.
	o.set_unemployed(o.get_unemployed() + 2);
}

/* Destructor */
Bank::~Bank()
{

}