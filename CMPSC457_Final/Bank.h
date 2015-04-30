#pragma once
#ifndef BANK_H
#define BANK_H

#include "Building.h"

class Bank :
	public Building
{
public:
	Bank(GLdouble, GLdouble, GLdouble, Tile);
	void plop_building();
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	bool apply_cost_per_tick(OutputResources &);
	void delete_benefit(OutputResources &);
	std::string check_cost(OutputResources &);
	~Bank();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif