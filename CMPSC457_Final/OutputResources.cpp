#include "OutputResources.h"


OutputResources::OutputResources()
{
	food		= 5;
	money		= 1000;
	population	= 20;
}

std::vector<int> OutputResources::get_resources()
{
	std::vector<int> v;
	v.push_back(food);
	v.push_back(wood);
	v.push_back(bricks);
	v.push_back(money);
	v.push_back(population);

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
	this->food = food;
}

void OutputResources::set_wood(int wood)
{
	this->wood = wood;
}

void OutputResources::set_bricks(int bricks)
{
	this->bricks = bricks;
}

void OutputResources::set_money(int money)
{
	this->money = money;
}

void OutputResources::set_unemployed(int unemployed)
{
	this->unemployed = unemployed;
}

void OutputResources::set_employed(int employed)
{
	this->employed = employed;
}

void OutputResources::set_population(int unemployed, int employed)
{
	this->unemployed	= unemployed;
	this->employed		= employed;
}


OutputResources::~OutputResources()
{
}
