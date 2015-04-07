#include "BuildingFactory.h"

BuildingFactory::BuildingFactory()
{
}

Building BuildingFactory::create_building(std::string name)
{
	if (name.compare("Farm"))
	{

	}
	else if (name.compare("Mill"))
	{

	}
	else if (name.compare("Mine"))
	{

	}
	else if (name.compare("Bank"))
	{

	}
	else if (name.compare("House"))
	{

	}
	else if (name.compare("Temple"))
	{

	}
}


BuildingFactory::~BuildingFactory()
{
}
