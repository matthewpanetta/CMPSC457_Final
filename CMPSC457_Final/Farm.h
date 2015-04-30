#pragma once
#ifndef FARM_H
#define FARM_H

#include "Building.h"
#include "Texture.h"

class Farm :
	public Building
{
public:
	Farm(GLdouble, GLdouble, GLdouble, Tile);
	void plop_building();
	void draw_building();
	void apply_perk(OutputResources &);
	void apply_initial_cost(OutputResources &);
	bool apply_cost_per_tick(OutputResources &);
	void delete_benefit(OutputResources &);
	std::string check_cost(OutputResources &);
	~Farm();
private:
	GLdouble x, y, z;
	Tile t;
	GLuint texture[1];
	Texture ground_tex;
	Texture farm_tex;
};

#endif