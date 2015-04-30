#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include "Building.h"
#include "Texture.h"

class House :
	public Building
{
public:
	House(GLdouble, GLdouble, GLdouble, Tile);
	void draw_building();
	void draw_house();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	bool apply_cost_per_tick(OutputResources &);
	void delete_benefit(OutputResources &);
	std::string check_cost(OutputResources &);
	~House();
private:
	Texture tex;
	Texture house_tex;
	GLdouble x, y, z;
	Tile t;
	int type;
};

#endif