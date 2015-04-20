#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"
#include "Building.h"
#include "BuildingManager.h"
#include "BuildingFactory.h"
#include "Grid.h"
#include "Cursor.h"
#include <vector>

using namespace std;

class World
{
public:
	World(int, int);
	void draw_world();
	Cursor* get_cursor();
	Grid* get_grid();
	BuildingFactory* get_building_factory();
	Tile* get_selected_tile();
	OutputResources* get_resources();
	void create_building(int);
	void next_tick();
	~World();
private:
	long tick;
	Grid gr;
	Cursor c;
	BuildingManager bm;
	BuildingFactory bf;
	OutputResources o;
};

#endif