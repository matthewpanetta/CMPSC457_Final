/*	Bank.cpp
*
*	This class is responsible for creating a Bank object and drawing it to the screen. */

#pragma once
#ifndef BANK_H
#define BANK_H

#include "Building.h"

class Bank :
	public Building
{
public:
	Bank(GLdouble, GLdouble, GLdouble, Tile);		/* Default Constructor - initialize the superclass of Building */
	void draw_building();							/* Draw the building to screen */
	void apply_perk(OutputResources &);				/* Apply the Bank's benefit per tick */
	std::string check_cost(OutputResources &);		/* Check if the user has enough resources to build a bank. If not, return a message with needed resource */
	void apply_initial_cost(OutputResources &);		/* Deduct the user's resources based on how much this building costs */
	bool apply_cost_per_tick(OutputResources &);	/* Deduct the user's resources based on how much this building costs to operate - Return false if user does not have enough resources */
	void delete_benefit(OutputResources &);			/* Add to the user's resources if they decide to remove a bank */
	~Bank();										/* Destructor */
private:
	GLdouble x, y, z;								/* X,Y,Z coordinate of building */
	Tile t;											/* Building tile */
};

#endif