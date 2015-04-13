#pragma once
#ifndef BUILDING_FACTORY_H
#define BUILDING_FACTORY_H

#include "Building.h"
#include <string>

class BuildingFactory
{
public:
	BuildingFactory();
	Building* create_building(GLdouble, GLdouble, GLdouble);
	int get_desired_building();
	~BuildingFactory();
};

#endif