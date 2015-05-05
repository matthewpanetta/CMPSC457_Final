/*	BuildingFactory.h
*
*	This class is responsible for returning the correct building, based on user input.
*
*	Building is an interface, and each building type is a subclass of building.
*	This class uses polymorphism to return a building object as a pointer. */

#pragma once
#ifndef BUILDING_FACTORY_H
#define BUILDING_FACTORY_H

#include "Building.h"
#include <string>

class BuildingFactory
{
public:
	BuildingFactory();														/* Default Constructor */
	Building* create_building(int, GLdouble, GLdouble, GLdouble, Tile);		/* Return the correct building type based on the building type */
	~BuildingFactory();														/* Destructor */
};

#endif