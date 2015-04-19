#include "BuildingManager.h"
#include <algorithm>


BuildingManager::BuildingManager()
{

}

void BuildingManager::add_building(Building& b)
{
	buildings.push_back(&b);
}

void BuildingManager::get_building(Tile t)
{

}

void BuildingManager::remove_building(Building& b)
{
	std::vector<Building*>::iterator position = std::find(buildings.begin(), buildings.end(), &b);

	if (position != buildings.end()) // == vector.end() means the element was not found
		buildings.erase(position);
}

BuildingManager::~BuildingManager()
{

}
