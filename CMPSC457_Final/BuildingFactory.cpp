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

Building* BuildingFactory::create_building(std::string name, GLdouble x, GLdouble y, GLdouble z)
{
	if (name == "Farm")
	{
		return new Farm(x, y, z);
	}
	else if (name == "Mill")
	{
		return new Mill(x, y, z);
	}
	else if (name == "Mine")
	{
		return new Mine(x, y, z);
	}
	else if (name == "Bank")
	{
		return new Bank(x, y, z);
	}
	else if (name == "House")
	{
		return new House(x, y, z);
	}
	else if (name == "Temple")
	{
		return new Temple(x, y, z);
	}
	else
	{
		return new Farm(x, y, z);
	}
}

BuildingFactory::~BuildingFactory()
{
}
