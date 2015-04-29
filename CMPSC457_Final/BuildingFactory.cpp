#include "BuildingFactory.h"
#include "Farm.h"
#include "Mill.h"
#include "Mine.h"
#include "Bank.h"
#include "House.h"
#include "Temple.h"

#include <iostream>

BuildingFactory::BuildingFactory()
{
	
}

Building* BuildingFactory::create_building(int building_type, GLdouble x, GLdouble y, GLdouble z, Tile t)
{
	switch (building_type)
	{
		case 0: return new Bank(x, y, z, t);
		case 1: return new Farm(x, y, z, t);
		case 2: return new House(x, y, z, t);
		case 3: return new Mill(x, y, z, t);
		case 4: return new Mine(x, y, z, t);
		case 5: return new Temple(x, y, z, t);
	}
}

BuildingFactory::~BuildingFactory()
{
}
