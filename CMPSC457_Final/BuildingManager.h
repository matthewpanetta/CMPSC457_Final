/*	BuildingManager.h
*
*	This class is responsible for maintaining the vector of all buildings. When the user enters build mode and builds a building,
*	the building is created here. This class also handles building deletion, as well as processing each building's cost/benefit per tick. */

#pragma once
#ifndef BUILDING_MANAGER_H
#define BUILDING_MANAGER_H

#include "Building.h"
#include "BuildingFactory.h"
#include <vector>

class BuildingManager
{
public:
	BuildingManager();											/* Default Constructor */
	std::string add_building(Building& b, OutputResources& o);	/* Add building to vector */
	Building* get_building(int x, int z);						/* Get pointer to building at a specified X and Y coordinate */
	void remove_building(int x, int z, OutputResources& o);		/* Remove building from the vector */
	void remove_all_buildings();								/* Remove every building */
	void draw_buildings();										/* Draw each building in the vector */
	void next_tick(OutputResources& o);							/* Process the next tick and update user's resources */
	bool check_animating();										/* Check if a building is currently animating */
	~BuildingManager();											/* Destructor */
private:
	std::vector<Building*> buildings;							/* Vector of buildings */
};

#endif