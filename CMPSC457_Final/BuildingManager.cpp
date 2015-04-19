#include "BuildingManager.h"
#include <algorithm>


BuildingManager::BuildingManager()
{

}

void BuildingManager::add_building(Building& b)
{
	buildings.push_back(&b);
}

Building* BuildingManager::get_building(Tile t)
{
	for (std::vector<Building*>::iterator it = buildings.begin(); it != buildings.end(); ++it)
	{
		if ((*it)->get_tile() == t)
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

BuildingManager::~BuildingManager()
{

}