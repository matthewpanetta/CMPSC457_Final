/*	Mill.cpp
*
*	This class is responsible for creating a Mill object and drawing it to the screen. */

#pragma once
#ifndef MILL_H
#define MILL_H

#include "Building.h"
#include "OutputResources.h"

class Mill :
	public Building
{
public:
	Mill(GLdouble, GLdouble, GLdouble, Tile, std::vector<Texture> &images);			/* Default Constructor - initialize the superclass of Building */
	void draw_building();								/* Draw the building to screen */
	std::string check_cost(OutputResources &);			/* Check if the user has enough resources to build a mill. If not, return a message with needed resource */
	std::string check_delete(OutputResources &);		/* Check to see if the building can be deleted */
	void apply_perk(OutputResources &);					/* Apply the Mill's benefit per tick */
	void apply_initial_cost(OutputResources &);			/* Deduct the user's resources based on how much this building costs */
	bool apply_cost_per_tick(OutputResources &);		/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
	void delete_benefit(OutputResources &);				/* Add to the user's resources if they decide to remove a mill */
	~Mill();											/* Destructor */
private:
	GLdouble x, y, z;									/* X,Y,Z position of this building */
	Tile t;												/* Tile the building is on */
};

#endif