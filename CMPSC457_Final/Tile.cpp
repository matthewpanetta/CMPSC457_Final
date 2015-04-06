#include "Tile.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <vector>


Tile::Tile()
{
	setValues();
}

Tile::Tile(int crops, int meat, int lumber, int bricks)
{
	this->crops = crops;
	this->meat = meat;
	this->lumber = lumber;
	this->bricks = bricks;
}

void Tile::setValues()
{
	crops	= rand() % 10;
	std::cout << crops << std::endl;

	animals = rand() % 10;
	std::cout << animals << std::endl;

	lumber	= rand() % 10;
	std::cout << lumber << std::endl;

	bricks	= rand() % 10;
	std::cout << bricks << std::endl;
}

std::vector<int> Tile::getValues()
{
	std::vector<int> v;
	v.push_back(crops);
	v.push_back(animals);
	v.push_back(lumber);
	v.push_back(bricks);

	return v;
}

Tile::~Tile()
{
}
