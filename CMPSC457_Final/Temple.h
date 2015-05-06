/*	Temple.cpp
*
*	This class is responsible for creating a Temple object and drawing it to the screen. */

#pragma once
#ifndef TEMPLE_H
#define TEMPLE_H

#include "Building.h"

class Temple :
	public Building
{
public:
	Temple(GLdouble, GLdouble, GLdouble, Tile);			/* Default Constructor - initialize the superclass of Building */
	void draw_building();								/* Draw the building to screen */
	std::string check_cost(OutputResources &);			/* Check if the user has enough resources to build a bank. If not, return a message with needed resource */
	std::string check_delete(OutputResources &);		/* Check to see if the building can be deleted */
	void apply_perk(OutputResources &);					/* Apply the Temple's benefit per tick */
	void apply_initial_cost(OutputResources &);			/* Deduct the user's resources based on how much this building costs */
	bool apply_cost_per_tick(OutputResources &);		/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
	void delete_benefit(OutputResources &);				/* User cannot remove a temple */
	~Temple();											/* Destructor */
private:
	GLdouble x, y, z;									/* X,Y,Z position of this building */
	Tile t;												/* Tile the building is on */
};

#endif