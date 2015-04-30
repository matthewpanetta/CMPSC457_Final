#include "House.h"
#include "Texture.h"

House::House(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
	this->type = rand() % 10 + 1;

	if (type > 7)
	{
		house_tex.set_filename("../Pictures/wood_house.bmp");
		tex.set_filename("../Pictures/house_grass_dark.bmp");
	}
	else if (type <= 7 && type > 3)
	{
		house_tex.set_filename("../Pictures/brick_house.bmp");
		tex.set_filename("../Pictures/house_grass.bmp");
	}
	else
	{
		house_tex.set_filename("../Pictures/house_siding.bmp");
		tex.set_filename("../Pictures/house_grass.bmp");
	}
}

void House::draw_building()
{
	draw_house();
}

void House::draw_house()
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
	
	draw_plane(house_tex.get_image());

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

	draw_plane(tex.get_image());

	glPopMatrix();
	glPopMatrix();
}

void House::apply_perk(OutputResources &o)
{
	/*o.set_food(o.get_food() + (t.get_soil() - t.get_stone()));*/
}

std::string House::check_cost(OutputResources &o)
{
	if (o.get_money() < 400)
	{
		return "Not Enough Money";
	}
	else if (o.get_wood() < 5)
	{
		return "Not Enough Wood";
	}
	else if (o.get_bricks() < 20)
	{
		return "Not Enough Bricks";
	}
	else
	{
		return "Good";
	}
}

void House::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 100);
	o.set_wood(o.get_wood() - 5);
	o.set_bricks(o.get_bricks() - 20);
	o.set_unemployed(o.get_unemployed() + 3);
}

bool House::apply_cost_per_tick(OutputResources &o)
{
	o.set_food(o.get_food() - 2);
	o.set_wood(o.get_wood() - 1);
	return true;
}

void House::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 50);

	o.set_unemployed(o.get_unemployed() - 3);
}

House::~House()
{

}


