/*	Tile.cpp
*	
*	This class is responsible for creating random values for each tile's resources count. */

#include "Tile.h"
#include <stdlib.h>     /* srand, rand */

/* Default Constructor -  set values randomly */
Tile::Tile()
{
	set_values();	// Set random values for all three raw resources (trees, soil, and stone).
}

/* Overriden Constructor - Provide values for each resource */
Tile::Tile(int trees, int soil, int stone)
{
	this->trees = trees;
	this->soil = soil;
	this->stone - stone;
}

/* Set the values of each raw resource from 0 - 9 using rand() */
void Tile::set_values()
{
	trees	= rand() % 10;	// Restrict value to 0-9 range.
	soil	= rand() % 10;
	stone	= rand() % 10;
}

/* Get the values of the tile by vector */
std::vector<int> Tile::get_values()
{
	std::vector<int> v;
	v.push_back(trees);
	v.push_back(soil);
	v.push_back(stone);

	return v;
}

/* Get the soil rating for this tile */
int Tile::get_soil()
{
	return soil;
}

/* Get the stone rating for this tile */
int Tile::get_stone()
{
	return stone;
}

/* Get the trees rating for this tile */
int Tile::get_trees()
{
	return trees;
}

/* Destructor */
Tile::~Tile()
{
}
