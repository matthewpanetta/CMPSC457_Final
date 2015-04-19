#pragma once
#ifndef FARM_H
#define FARM_H

#include "Building.h"

class Farm :
	public Building
{
public:
	Farm(GLdouble, GLdouble, GLdouble, Tile);
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	void apply_cost_per_tick(OutputResources &);
	~Farm();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif