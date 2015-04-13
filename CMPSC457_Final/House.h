#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include "Building.h"

class House :
	public Building
{
public:
	House(GLdouble, GLdouble, GLdouble);
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	void apply_cost_per_tick(OutputResources &);
	~House();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif