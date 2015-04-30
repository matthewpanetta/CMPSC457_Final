#include "OutputResources.h"


OutputResources::OutputResources()
{
	food		= 250;
	money		= 1000;
	bricks		= 100;
	wood		= 300;
	employed	= 0;
	unemployed	= 3;
}

std::vector<int> OutputResources::get_resources()
{
	std::vector<int> v;
	v.push_back(food);
	v.push_back(wood);
	v.push_back(bricks);
	v.push_back(money);
	v.push_back(unemployed);

	return v;
}

int OutputResources::get_food()
{
	return food;
}

int OutputResources::get_wood()
{
	return wood;
}

int OutputResources::get_bricks()
{
	return bricks;
}

int OutputResources::get_money()
{
	return money;
}

int OutputResources::get_unemployed()
{
	return unemployed;
}

int OutputResources::get_employed()
{
	return employed;
}

int OutputResources::get_population()
{
	return unemployed + employed;
}

void OutputResources::set_food(int food)
{
	if (food < 0)
	{
		food = 0;
	}
	else 
	{
		this->food = food;
	}
}

void OutputResources::set_wood(int wood)
{
	if (wood < 0)
	{
		wood = 0;
	}
	else
	{
		this->wood = wood;
	}
}

void OutputResources::set_bricks(int bricks)
{
	if (bricks < 0)
	{
		bricks = 0;
	}
	else
	{
		this->bricks = bricks;
	}
}

void OutputResources::set_money(int money)
{
	if (money < 0)
	{
		money = 0;
	}
	else
	{
		this->money = money;
	}
}

void OutputResources::set_unemployed(int unemployed)
{
	if (unemployed < 0)
	{
		unemployed = 0;
	}
	else
	{
		this->unemployed = unemployed;
	}
}

void OutputResources::set_employed(int employed)
{
	if (employed < 0)
	{
		employed = 0;
	}
	else
	{
		this->employed = employed;
	}
}

void OutputResources::set_population(int unemployed, int employed)
{
	if (unemployed < 0)
	{
		unemployed = 0;
	}
	else
	{
		this->unemployed = unemployed;
	}

	if (employed < 0)
	{
		employed = 0;
	}
	else
	{
		this->employed = employed;
	}
}

void OutputResources::reset()
{
	food = 250;
	money = 1000;
	bricks = 100;
	wood = 300;
	employed = 0;
	unemployed = 3;
}

OutputResources::~OutputResources()
{

}
