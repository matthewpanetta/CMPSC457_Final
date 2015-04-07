#include "Tile.h"
#include <stdlib.h>     /* srand, rand */


Tile::Tile()
{
	setValues();
}

Tile::Tile(int trees, int soil, int stone)
{
	this->trees = trees;
	this->soil = soil;
	this->stone - stone;
}

void Tile::setValues()
{
	trees	= rand() % 10;
	soil	= rand() % 10;
	stone	= rand() % 10;
}

std::vector<int> Tile::getValues()
{
	std::vector<int> v;
	v.push_back(trees);
	v.push_back(soil);
	v.push_back(stone);

	return v;
}

Tile::~Tile()
{
}
