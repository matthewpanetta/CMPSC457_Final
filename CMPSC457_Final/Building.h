#pragma once
#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include "GL\freeglut.h"
#include "Tile.h"
#include "OutputResources.h"

class Building
{
public:
	Building(GLdouble, GLdouble, GLdouble, Tile);
	GLfloat get_x();
	GLfloat get_y();
	GLfloat get_z();
	bool compare(const Building& b) const;

	bool operator == (const Building& b) const {
		return compare(b);
	};

	bool operator != (const Building& b) const {
		return !compare(b);
	};

	Tile get_tile();

	virtual std::string check_cost(OutputResources& o) = 0;
	virtual void draw_building() = 0;
	virtual void apply_perk(OutputResources &) = 0;
	virtual void apply_initial_cost(OutputResources &) = 0;
	virtual bool apply_cost_per_tick(OutputResources &) = 0;
	~Building();
private:
	GLdouble x, y, z;
	Tile t;
};

#endif