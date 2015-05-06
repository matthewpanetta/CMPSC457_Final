/*	House.cpp
*
*	This class is responsible for creating a House object and drawing it to the screen. */

#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include "Building.h"
#include "Texture.h"

class House :
	public Building
{
public:
	House(GLdouble, GLdouble, GLdouble, Tile);			/* Default Constructor - initialize the superclass of Building */
	void draw_building();								/* Draw the building to screen */
	std::string check_cost(OutputResources &);			/* Check if the user has enough resources to build a house. If not, return a message with needed resource */
	void apply_perk(OutputResources &);					/* Apply the House's benefit per tick */
	void apply_initial_cost(OutputResources &);			/* Deduct the user's resources based on how much this building costs */
	bool apply_cost_per_tick(OutputResources &);		/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
	void delete_benefit(OutputResources &);				/* Add to the user's resources if they decide to remove a house */
	~House();											/* Destructor */
private:
	GLdouble x, y, z;									/* X,Y,Z position of the building */
	Tile t;												/* Tile that the building is on */
	Texture tex;										/* Ground texture */
	Texture house_tex;									/* House texture */
	Texture door_tex;									/* Door texture */
	Texture window_tex;									/* Window texture */
	Texture roof_tex;									/* Roof texture */
	int type;											/* Type of house */
};

#endif