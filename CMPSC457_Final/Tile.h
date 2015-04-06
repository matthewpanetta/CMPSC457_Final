#pragma once
class Tile
{
public:
	Tile();
	Tile(int, int, int, int);
	void setValues();
	~Tile();
private:
	int crops;
	int animals;
	int lumber;
	int bricks;
};