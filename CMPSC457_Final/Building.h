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
	void set_tile(Tile t);

	virtual void draw_building() = 0;
	virtual void apply_perk(OutputResources &) = 0;
	virtual void apply_initial_cost(OutputResources &) = 0;
	virtual void apply_cost_per_tick(OutputResources &) = 0;
	~Building();
private:
	GLdouble x, y, z;
};

#endif