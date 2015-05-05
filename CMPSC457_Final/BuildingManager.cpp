/*	BuildingManager.cpp
*	
*	This class is responsible for maintaining the vector of all buildings. When the user enters build mode and builds a building,
*	the building is created here. This class also handles building deletion, as well as processing each building's cost/benefit per tick. */

#include "BuildingManager.h"
#include <algorithm>
#include <iostream>

/* Default Constructor */
BuildingManager::BuildingManager()
{

}

/* Add building to vector */
std::string BuildingManager::add_building(Building& b, OutputResources& o)
{
	if (get_building(b.get_x(), b.get_z()) == NULL)		// If a building does NOT exist at the desired building's location
	{
		if (b.check_cost(o) == "Good")					// If the user has enough resources to build the building
		{
			buildings.push_back(&b);					// Push back the building to the building vector.
			b.apply_initial_cost(o);					// Apply the building cost to the user's resources.
			return "Good";								// Return success message. This message is not displayed.
		}
		else											// If the user DOES NOT have enough resources to build the building
		{
			return &b.check_cost(o)[0u];				// Return the error message to be displayed. This error message will describe which resource the user needs in order to build the building.
		}
	}
	else															// If a building DOES exist at the desired building's location
	{
		return "There is already a building in that position";		// Return error message to be displayed.
	}
}

/* Get pointer to building at a specified X and Y coordinate */
Building* BuildingManager::get_building(int x, int z)
{
	for (std::vector<Building*>::iterator it = buildings.begin(); it != buildings.end(); ++it)		// Vector iterator
	{
		if ((*it)->get_x() == x && (*it)->get_z() == z)		// If current iteration's building X and Y values match the passed in values.
		{
			return (*it);									// Return pointer to building.
		}
	}

	return NULL;											// Return null if no building exists at specified location.
}

/* Remove building from the vector */
void BuildingManager::remove_building(int x, int z, OutputResources &o)
{
	Building* b = get_building(x, z);			// Get building at specified location.
	std::vector<Building*>::iterator position = std::find(buildings.begin(), buildings.end(), b);	// Find the building's position in the building vector.

	if (position != buildings.end())				// If the building's position is within the vector
	{
		b->delete_benefit(o);		// Apply the building's deletion benefit to the user's resources. (Usually 50% of the building's initial cost.)
		buildings.erase(position);	// Erase the building from the building vector. It will no longer be redrawn.
	}
}

/* Remove every building */
void BuildingManager::remove_all_buildings()
{
	buildings.clear();				// Clear the building vector.
}

/* Draw each building in the vector */
void BuildingManager::draw_buildings()
{
	for (std::vector<Building*>::iterator it = buildings.begin(); it != buildings.end(); ++it)		// Building iterator
	{
		(*it)->draw_building();		// Call each building's draw function.
	}
}

/* Process the next tick and update user's resources */
void BuildingManager::next_tick(OutputResources& o)
{
	for (std::vector<Building*>::iterator it = buildings.begin(); it != buildings.end(); ++it)		// Building iterator
	{
		if ((*it)->apply_cost_per_tick(o))		// If the user has enough resources for the building's cost per tick
		{
			(*it)->apply_perk(o);				// Apply the building's benefit. Note that the benefit will NOT be applied if the user does not have enough resources for the cost.
		}
	}
}

/* Check if a building is currently animating */
bool BuildingManager::check_animating()
{
	for (std::vector<Building*>::iterator it = buildings.begin(); it != buildings.end(); ++it)		// Building iterator
	{
		if ((*it)->check_animating())		// If ANY building in the vector is animating
		{
			return true;					// Return true
		}
	}

	return false;							// If no building is animating, return false
}

/* Destructor */
BuildingManager::~BuildingManager()
{

}