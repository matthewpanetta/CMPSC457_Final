#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include "Building.h"

class House :
	public Building
{
public:
	House(GLdouble, GLdouble, GLdouble, Tile);
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	bool apply_cost_per_tick(OutputResources &);
	std::string check_cost(OutputResources &);
	~House();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif