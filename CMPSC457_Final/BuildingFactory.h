#pragma once
#include "Building.h"
#include <string>

class BuildingFactory
{
public:
	BuildingFactory();
	Building create_building(std::string);
	~BuildingFactory();
};

