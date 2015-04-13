#include "BuildingFactory.h"
#include "Farm.h"
#include "Mill.h"
#include "Mine.h"
#include "Bank.h"
#include "House.h"
#include "Temple.h"

BuildingFactory::BuildingFactory()
{
}

Building BuildingFactory::create_building(std::string name, GLdouble x, GLdouble y, GLdouble z)
{
	if (name.compare("Farm"))
	{
		Farm farm(x, y, z);
		return farm;
	}
	else if (name.compare("Mill"))
	{
		Mill mill(x, y, z);
		return mill;
	}
	else if (name.compare("Mine"))
	{
		Mine mine(x, y, z);
		return mine;
	}
	else if (name.compare("Bank"))
	{
		Bank bank(x, y, z);
		return bank;
	}
	else if (name.compare("House"))
	{
		House house(x, y, z);
		return house;
	}
	else if (name.compare("Temple"))
	{
		Temple temple(x, y, z);
		return temple;
	}
	else
	{
		Building building(x, y, z);
		return building;
	}
}


BuildingFactory::~BuildingFactory()
{
}
