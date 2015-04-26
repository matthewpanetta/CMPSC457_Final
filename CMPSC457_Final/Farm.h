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
	bool apply_cost_per_tick(OutputResources &);
	std::string check_cost(OutputResources &);
	~Farm();
private:
	GLdouble x, y, z;
	Tile t;
	GLuint texture[1];
};

#endif