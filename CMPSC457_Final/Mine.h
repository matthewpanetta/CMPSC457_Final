#pragma once
#ifndef MINE_H
#define MINE_H

#include "Building.h"
#include "OutputResources.h"

class Mine :
	public Building
{
public:
	Mine(GLdouble, GLdouble, GLdouble, Tile);
	void plop_building();
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	bool apply_cost_per_tick(OutputResources &);
	void delete_benefit(OutputResources &);
	std::string check_cost(OutputResources &);
	~Mine();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif