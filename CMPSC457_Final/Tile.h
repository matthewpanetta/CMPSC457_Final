#pragma once
#ifndef TILE_H
#define TILE_H

#include <vector>

class Tile
{
public:
	Tile();
	Tile(int, int, int);
	std::vector<int> getValues();
	void setValues();
	int getTrees();
	int getSoil();
	int getStone();
	~Tile();
private:
	int trees;
	int soil;
	int stone;
};

#endif