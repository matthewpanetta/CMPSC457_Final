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

int BuildingFactory::get_desired_building()
{
	int building_type = -1;

	do {
		std::cout << "Press number to build:\n\t[0] Bank\n\t[1] Farm\n\t[2] House\n\t[3] Mill\n\t[4] Mine" << std::endl;
		std::cin >> building_type;
		
		if (!std::cin || building_type < 0 || building_type > 4)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (building_type < 0 || building_type > 4);

	return building_type;
}

Building* BuildingFactory::create_building(GLdouble x, GLdouble y, GLdouble z, Tile t)
{
	int building_type = get_desired_building();

	switch (building_type)
	{
	case 0: return new Bank(x, y, z, t);
	case 1: return new Farm(x, y, z, t);
	case 2: return new House(x, y, z, t);
	case 3: return new Mill(x, y, z, t);
	case 4: return new Mine(x, y, z, t);
	}
}

BuildingFactory::~BuildingFactory()
{
}
