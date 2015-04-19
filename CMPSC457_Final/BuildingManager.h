#pragma once
#ifndef BUILDING_MANAGER_H
#define BUILDING_MANAGER_H

#include "Building.h"
#include "BuildingFactory.h"
#include <vector>

class BuildingManager
{
public:
	BuildingManager();
	void add_building(Building& b);
	Building* get_building(Tile t);
	void remove_building(Building& b);
	void draw_buildings();
	~BuildingManager();
private:
	std::vector<Building*> buildings;
};

#endif