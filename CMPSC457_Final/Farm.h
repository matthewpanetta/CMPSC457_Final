/*	Farm.h
*
*	This class is responsible for creating a Farm object and drawing it to the screen. */

#pragma once
#ifndef FARM_H
#define FARM_H

#include "Building.h"
#include "Texture.h"

class Farm :
	public Building
{
public:
	Farm(GLdouble, GLdouble, GLdouble, Tile);			/* Default Constructor - initialize the superclass of Building */
	void draw_building();								/* Draw the building to screen */
	void apply_perk(OutputResources &);					/* Apply the Farm's benefit per tick */
	std::string check_cost(OutputResources &);			/* Check if the user has enough resources to build a farm. If not, return a message with needed resource */
	void Farm::apply_initial_cost(OutputResources &o);	/* Deduct the user's resources based on how much this building costs */
	bool apply_cost_per_tick(OutputResources &);		/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
	void delete_benefit(OutputResources &);				/* Add to the user's resources if they decide to remove a farm */
	~Farm();											/* Destructor */
private:
	GLdouble x, y, z;									/* X,Y,Z position of this building */
	Tile t;												/* Tile building is on */
};

#endif