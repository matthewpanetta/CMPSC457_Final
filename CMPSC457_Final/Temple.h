#pragma once
#ifndef TEMPLE_H
#define TEMPLE_H

#include "Building.h"

class Temple :
	public Building
{
public:
	Temple(GLdouble, GLdouble, GLdouble);
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	void apply_cost_per_tick(OutputResources &);
	~Temple();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif