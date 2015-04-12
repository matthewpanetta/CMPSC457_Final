#pragma once
#ifndef BUILDING_H
#define BUILDING_H

#include "GL\freeglut.h"
#include "Tile.h"

class Building
{
public:
	Building(GLdouble, GLdouble, GLdouble);
	GLfloat get_x();
	GLfloat get_y();
	GLfloat get_z();
	void draw_building();
	void set_tile(Tile t);
	void set_perk();
	void apply_perk();
	void apply_cost();
	~Building();
private:
	GLdouble x, y, z;
};

#endif