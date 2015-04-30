#pragma once
#ifndef OUTPUTRESOURCES_H
#define OUTPUTRESOURCES_H

#include <vector>
class OutputResources
{
public:
	OutputResources();
	std::vector<int> get_resources();
	int get_food();
	int get_wood();
	int get_bricks();
	int get_money();
	int get_population();
	int get_unemployed();
	int get_employed();
	void set_food(int);
	void set_wood(int);
	void set_bricks(int);
	void set_money(int);
	void set_population(int, int);
	void set_employed(int);
	void set_unemployed(int);
	void reset();
	~OutputResources();
private:
	int food, wood, bricks, money, unemployed, employed;
};

#endif