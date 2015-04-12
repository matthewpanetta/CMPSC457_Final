#pragma once
#ifndef MILL_H
#define MILL_H

#include "Building.h"
#include "OutputResources.h"

class Mill :
	public Building
{
public:
	Mill(GLdouble, GLdouble, GLdouble);
	void draw_building();
	void set_tile(Tile);
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	void apply_cost_per_tick(OutputResources &);
	~Mill();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif