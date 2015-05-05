/*	Tile.h
*
*	This class is responsible for creating random values for each tile's resources count. */

#pragma once
#ifndef TILE_H
#define TILE_H

#include <vector>

class Tile
{
public:
	Tile();								/* Default Constructor - set values randomly */
	Tile(int, int, int);				/* Overriden Constructor - Provide values for each resource */
	void set_values();					/* Set the values of each raw resource from 0 - 9 using rand() */
	std::vector<int> get_values();		/* Get the values of the tile by vector */
	int get_soil();						/* Get the soil rating for this tile */
	int get_stone();					/* Get the stone rating for this tile */
	int get_trees();					/* Get the trees rating for this tile */

	/* -------------- OVERLOADED OPERATOR -------------- */
	bool operator==(const Tile& t) const
	{
		return (trees == t.trees && soil == t.soil && stone == t.stone);	// Deprecated. Tile is considered equal if its ratings are the same. This is not always true.
	};
	
	~Tile();							/* Destructor */
private:
	int trees;							// Trees value
	int soil;							// Soil value
	int stone;							// Stone value
};

#endif