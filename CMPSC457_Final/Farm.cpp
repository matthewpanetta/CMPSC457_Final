#include "Farm.h"

Farm::Farm(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t), ground_tex("../Pictures/farm_four_tile.bmp"), farm_tex("../Pictures/barn.bmp")
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Farm::plop_building()
{

}

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
	
	draw_plane(farm_tex.get_image());

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

	// texture
	glTranslatef(0.0, -0.38, 0.5);
	glScalef(0.9, 0.01, 0.9);
	glColor3f(1.0, 1.0, 1.0);
	draw_plane(ground_tex.get_image());

	glPopMatrix();
	glPopMatrix();

	if (y < -0.50)
	{
		Building::is_animating = true;
		y = y + 0.05;
	}
	else
	{
		y = -0.5;
		Building::is_animating = false;
	}
}

void Farm::apply_perk(OutputResources &o)
{
	o.set_food(o.get_food() + t.get_soil());
}

std::string Farm::check_cost(OutputResources& o)
{
	if (o.get_money() < 150)
	{
		return "Not Enough Money";
	}
	else if (o.get_unemployed() < 2)
	{
		return "Not Enough Unemployed";
	}
	else
	{
		return "Good";
	}
}

void Farm::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 150);
	o.set_unemployed(o.get_unemployed() - 2);
	o.set_employed(o.get_employed() + 2);
}

bool Farm::apply_cost_per_tick(OutputResources &o)
{
	o.set_money(o.get_money() - 1);
	return true;
}

void Farm::delete_benefit(OutputResources &o)
{
	o.set_money(o.get_money() + 75);
	o.set_employed(o.get_employed() - 2);
	o.set_unemployed(o.get_unemployed() + 2);
}

Farm::~Farm()
{

}