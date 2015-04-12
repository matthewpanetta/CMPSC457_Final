#pragma once
#ifndef BUILDING_H
#define BUILDING_H

#include "GL\freeglut.h"
#include "Tile.h"
#include "OutputResources.h"

class Building
{
public:
	Building(GLdouble, GLdouble, GLdouble);
	GLfloat get_x();
	GLfloat get_y();
	GLfloat get_z();
	void draw_building();
	void set_tile(Tile t);
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	void apply_cost_per_tick(OutputResources &);
	~Building();
private:
	GLdouble x, y, z;
};

#endif