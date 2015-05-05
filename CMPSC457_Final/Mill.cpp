/*	Mill.cpp
*
*	This class is responsible for creating a Mill object and drawing it to the screen. */

#include "Mill.h"

/* Default Constructor - initialize the superclass of Building */
Mill::Mill(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

/* Draw the building to screen */
void Mill::draw_building()
{
	glPushMatrix();
	glTranslatef(x, y*-1, z);

	glTranslatef(0.0, 0.5, 0.0);
	glTranslatef(-0.15, -0.80, 0.1);
	glScalef(0.7, 0.5, 0.8);

	// house
	glPushMatrix();
	glColor3f(0.72, 0.72, 0.72);
	glScalef(0.5, 0.75, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.72, 0.72, 0.72);
	glTranslated(0.3, -0.125, 0.0);
	glScalef(0.75, 0.5, 0.25);
	glutSolidCube(1);
	glPopMatrix();

	glTranslated(0.0, -0.2, 0.0);

	// high roof
	glPushMatrix();
	glScaled(0.5, 1.0, 0.6);
	glColor3f(0.55, 0.27, 0.07);
	glTranslatef(0.0, 0.58, 0.0);
	glScalef(0.55, 0.2, 0.5);

	// Right
	glBegin(GL_POLYGON);
	glNormal3d(0.5, 0.5, 0.0);
	glVertex3f(0.0f, 0.5f, 1.0f);
	glVertex3f(0.0f, 0.5f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glEnd();

	// Left
	glBegin(GL_POLYGON);
	glNormal3d(-0.5, 0.5, 0.0);
	glVertex3f(0.0f, 0.5f, 1.0f);
	glVertex3f(0.0f, 0.5f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glEnd();

	glPopMatrix();

	//Low roof

	glPushMatrix();
	glTranslated(0.45, 0.35, 0.0);
	glRotated(90, 0.0, 1.0, 0.0);
	glScaled(0.4, 0.0, 0.5);
	glColor3f(0.55, 0.27, 0.07);

	glScalef(0.55, 0.2, 0.5);

	// Right
	glBegin(GL_POLYGON);
	glNormal3d(0.0, 0.5, -0.5);
	glVertex3f(0.0f, 0.5f, 1.0f);
	glVertex3f(0.0f, 0.5f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glEnd();

	// Left
	glBegin(GL_POLYGON);
	glNormal3d(0.0, 0.5, 0.5);
	glVertex3f(0.0f, 0.5f, 1.0f);
	glVertex3f(0.0f, 0.5f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glEnd();

	glPopMatrix();

	//Wood
	glPushMatrix();
	glTranslated(0.0, 0.0, 0.24);
	glRotated(45, 1.0, 0.0, 0.0);
	glScaled(0.2, 0.5, 1.0);
	glutSolidCylinder(0.1, 0.15, 10, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.05, 0.0, 0.24);
	glRotated(45, 1.0, 0.0, 0.0);
	glScaled(0.2, 0.5, 1.0);
	glutSolidCylinder(0.1, 0.15, 10, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.1, 0.0, 0.24);
	glRotated(45, 1.0, 0.0, 0.0);
	glScaled(0.2, 0.5, 1.0);
	glutSolidCylinder(0.1, 0.15, 10, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.38, -0.2, 0.22);
	glRotated(45, 0.0, 1.0, 0.0);
	glScaled(0.2, 0.5, 1.0);
	glutSolidCylinder(0.1, 0.15, 10, 3);
	glPopMatrix();

	//Window vertical
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.2, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.14, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	//horizontal
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.38, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.3, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.22, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.1, 0.0, 0.0);

	//Window vertical
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.2, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.14, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	//horizontal
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.38, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.3, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.22, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();
	glTranslated(0.2, 0.0, 0.0);

	//Window vertical
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.2, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.14, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	//horizontal
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.38, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.3, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.22, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();
	glTranslated(0.3, 0.0, 0.0);

	//Window vertical
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.2, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.14, 0.3, 0.25);
	glScaled(0.03, 0.3, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	//horizontal
	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.38, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.3, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(-0.17, 0.22, 0.25);
	glRotated(90, 0.0, 0.0, 1.0);
	glScaled(0.03, 0.15, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	//Door
	glColor3d(0.5, 0.3, 0.2);
	glPushMatrix();
	glTranslated(0.2, -0.082, 0.12);
	glScaled(0.2, 0.35, 0.03);
	glutSolidCube(0.5);
	glPopMatrix();

	glColor3d(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslated(0.2, -0.082, 0.13);
	glScaled(0.1, 0.1, 0.03);
	glutSolidCube(0.5);
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

/* Apply the Mill's benefit per tick */
void Mill::apply_perk(OutputResources &o)
{
	o.set_wood(o.get_wood() + t.get_trees());		// Give (tree rating) wood per tick
}

/* Check if the user has enough resources to build a mill. If not, return a message with needed resource */
// Note that this function will return on the first failure. So the message will display only one resource.
std::string Mill::check_cost(OutputResources& o)
{
	if (o.get_money() < 300)				// Mill costs $300
	{
		return "Not Enough Money";
	}
	else if (o.get_unemployed() < 3)		// 3 unemployed
	{
		return "Not Enough Unemployed";
	}
	else
	{
		return "Good";						// If the user has enough resources, return a success message that will not be displayed.
	}
}

/* Deduct the user's resources based on how much this building costs */
void Mill::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 300);			// Mill costs $300
	o.set_unemployed(o.get_unemployed() - 3);	// 3 unemployed
	o.set_employed(o.get_employed() + 3);		// Make 3 new employed
}

/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
bool Mill::apply_cost_per_tick(OutputResources &o)
{
	if (o.get_money() >= 1)
	{
		o.set_money(o.get_money() - 1);			// Mill requires $1 per tick.
		return true;
	}
	else
	{
		return false;							// Return false if user does not have sufficient amount of resources.
	}
}

/* Add to the user's resources if they decide to remove a mill */
void Mill::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 150);			// Get $150 back
	o.set_employed(o.get_employed() - 3);		// Take three employed people
	o.set_unemployed(o.get_unemployed() + 3);	// Make them unemployed
}

/* Destructor */
Mill::~Mill()
{

}
