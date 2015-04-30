#pragma once
#ifndef MILL_H
#define MILL_H

#include "Building.h"
#include "OutputResources.h"

class Mill :
	public Building
{
public:
	Mill(GLdouble, GLdouble, GLdouble, Tile);
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	bool apply_cost_per_tick(OutputResources &);
	void delete_benefit(OutputResources &);
	std::string check_cost(OutputResources &);
	~Mill();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif