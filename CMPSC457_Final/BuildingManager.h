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
	char* add_building(Building& b, OutputResources& o);
	Building* get_building(int x, int z);
	void remove_building(Building& b);
	void draw_buildings();
	void next_tick(OutputResources& o);
	~BuildingManager();
private:
	std::vector<Building*> buildings;
};

#endif