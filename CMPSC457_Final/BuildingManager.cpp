#include "BuildingManager.h"
#include <algorithm>
#include <iostream>

BuildingManager::BuildingManager()
{

}

void BuildingManager::add_building(Building& b, OutputResources& o)
{
	if (get_building(b.get_x(), b.get_z()) == NULL)
	{
		if (b.check_cost(o) == "Good")
		{
			buildings.push_back(&b);
			b.apply_initial_cost(o);
		}
		else
		{
			std::cout << b.check_cost(o) << std::endl;
		}
	}
	else
	{
		std::cout << "There is already a building in that position" << std::endl;
	}
}

Building* BuildingManager::get_building(int x, int z)
{
	for (std::vector<Building*>::iterator it = buildings.begin(); it != buildings.end(); ++it)
	{
		if ((*it)->get_x() == x && (*it)->get_z() == z)
		{
			return (*it);
		}
	}

	return NULL;
}

void BuildingManager::remove_building(Building& b)
{
	std::vector<Building*>::iterator position = std::find(buildings.begin(), buildings.end(), &b);

	if (position != buildings.end()) // == vector.end() means the element was not found
		buildings.erase(position);
}

void BuildingManager::draw_buildings()
{
	for (std::vector<Building*>::iterator it = buildings.begin(); it != buildings.end(); ++it)
	{
		(*it)->draw_building();
	}
}

void BuildingManager::next_tick(OutputResources& o)
{
	for (std::vector<Building*>::iterator it = buildings.begin(); it != buildings.end(); ++it)
	{
		(*it)->apply_cost_per_tick(o);
		(*it)->apply_perk(o);
	}
}

BuildingManager::~BuildingManager()
{

}