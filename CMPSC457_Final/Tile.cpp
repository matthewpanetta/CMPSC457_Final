#include "Tile.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */


Tile::Tile()
{
	setValues();
}

Tile::Tile(int crops, int animals, int lumber, int bricks)
{
	this->crops = crops;
	this->animals = animals;
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

Tile::~Tile()
{
}
