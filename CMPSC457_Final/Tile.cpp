#include "Tile.h"
#include <stdlib.h>     /* srand, rand */


Tile::Tile()
{
	set_values();
}

Tile::Tile(int trees, int soil, int stone)
{
	this->trees = trees;
	this->soil = soil;
	this->stone - stone;
}

void Tile::set_values()
{
	trees	= rand() % 10;
	soil	= rand() % 10;
	stone	= rand() % 10;
}

std::vector<int> Tile::get_values()
{
	std::vector<int> v;
	v.push_back(trees);
	v.push_back(soil);
	v.push_back(stone);

	return v;
}

int Tile::get_soil()
{
	return soil;
}

int Tile::get_stone()
{
	return stone;
}

int Tile::get_trees()
{
	return trees;
}

Tile::~Tile()
{
}
