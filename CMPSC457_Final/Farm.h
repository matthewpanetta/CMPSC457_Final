#pragma once
#include "Building.h"
#include "OutputResources.h"

class Farm :
	public Building
{
public:
	Farm(GLdouble, GLdouble, GLdouble);
	void draw_building();
	void set_tile(Tile);
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	void apply_cost_per_tick(OutputResources &);
	~Farm();
private:
	GLdouble x, y, z;
	Tile t;
};

