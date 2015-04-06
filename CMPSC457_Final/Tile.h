#pragma once
#include <vector>

class Tile
{
public:
	Tile();
	Tile(int, int, int, int);
	std::vector<int> getValues();
	void setValues();
	~Tile();
private:
	int crops;
	int meat;
	int lumber;
	int bricks;
};