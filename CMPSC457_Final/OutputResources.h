/*	OutputResources.h
*
*	This class is responsible for maintaining the user's resources. This class is made up of setters and getters, mostly.
*	This class also contains a reset function that will reset the user's resources. */

#pragma once
#ifndef OUTPUTRESOURCES_H
#define OUTPUTRESOURCES_H

#include <vector>
class OutputResources
{
public:
	OutputResources();					/* Default Constructor */
	std::vector<int> get_resources();	/* Get all resources as a vector */
	void reset();						/* Reset resources to initial values */

	/* -------------------- SETTERS AND GETTERS -------------------- */

	int get_food();
	int get_wood();
	int get_bricks();
	int get_money();
	int get_population();
	int get_unemployed();
	int get_employed();
	void set_food(int);
	void set_wood(int);
	void set_bricks(int);
	void set_money(int);
	void set_population(int, int);
	void set_employed(int);
	void set_unemployed(int);

	~OutputResources();					/* Destructor */
private:
	int food, wood, bricks, money, unemployed, employed;
};

#endif