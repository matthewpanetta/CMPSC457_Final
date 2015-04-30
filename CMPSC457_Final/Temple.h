#pragma once
#ifndef TEMPLE_H
#define TEMPLE_H

#include "Building.h"

class Temple :
	public Building
{
public:
	Temple(GLdouble, GLdouble, GLdouble, Tile);
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	bool apply_cost_per_tick(OutputResources &);
	void delete_benefit(OutputResources &);
	std::string check_cost(OutputResources &);
	~Temple();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif