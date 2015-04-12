#pragma once
#ifndef BANK_H
#define BANK_H

#include "Building.h"

class Bank :
	public Building
{
public:
	Bank(GLdouble, GLdouble, GLdouble);
	void draw_building();
	void set_tile(Tile);
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	void apply_cost_per_tick(OutputResources &);
	~Bank();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif