/*	Mine.cpp
*
*	This class is responsible for creating a Mine object and drawing it to the screen. */

#pragma once
#ifndef MINE_H
#define MINE_H

#include "Building.h"
#include "OutputResources.h"

class Mine :
	public Building
{
public:
	Mine(GLdouble, GLdouble, GLdouble, Tile);			/* Default Constructor - initialize the superclass of Building */
	void draw_building();								/* Draw the building to screen */
	void apply_perk(OutputResources &);					/* Apply the Mine's benefit per tick */
	std::string check_cost(OutputResources &);			/* Check if the user has enough resources to build a mine. If not, return a message with needed resource */
	void apply_initial_cost(OutputResources &);			/* Deduct the user's resources based on how much this building costs */
	bool apply_cost_per_tick(OutputResources &);		/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
	void delete_benefit(OutputResources &);				/* Add to the user's resources if they decide to remove a mine */
	~Mine();											/* Destructor */
private:
	GLdouble x, y, z;									/* X,Y,Z position of the building */
	Tile t;												/* Tile the building is on */
};

#endif