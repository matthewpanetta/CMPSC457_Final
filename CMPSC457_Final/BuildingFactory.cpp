#include "BuildingFactory.h"


BuildingFactory::BuildingFactory()
{
}

Building BuildingFactory::create_building(std::string name)
{
	if (name.compare("Hospital") == 0)
	{

	}
	else if (name.compare("Brothel") == 0)
	{

	}
	else if (name.compare("Strip Club") == 0)
	{

	}
	else if (name.compare("Whore house") == 0)
	{

	}
	else if (name.compare("Lonely Shack") == 0)
	{

	}
	else if (name.compare("Church") == 0)
	{

	}

}


BuildingFactory::~BuildingFactory()
{
}
