#pragma once
#ifndef TILE_H
#define TILE_H

#include <vector>

class Tile
{
public:
	Tile();
	Tile(int, int, int);
	std::vector<int> get_values();
	void set_values();
	int get_trees();
	int get_soil();
	int get_stone();
	~Tile();
private:
	int trees;
	int soil;
	int stone;
};

#endif