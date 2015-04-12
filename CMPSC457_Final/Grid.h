#pragma once
#include "World.h"
#include "Tile.h"

class Grid
{
public:
	Grid(int, int, vector<int>);
	~Grid();

private:
	std::vector<vector<Tile>> grid;
};

