#pragma once
#ifndef MINE_H
#define MINE_H

#include "Building.h"
#include "OutputResources.h"

class Mine :
	public Building
{
public:
	Mine(GLdouble, GLdouble, GLdouble);
	void draw_building();
	void set_tile(Tile);
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	void apply_cost_per_tick(OutputResources &);
	~Mine();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif