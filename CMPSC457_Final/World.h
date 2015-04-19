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
	void create_building(int, GLfloat, GLfloat, GLfloat);
	~World();
private:
	Grid gr;
	Cursor c;
	BuildingManager bm;
	BuildingFactory bf;
};

#endif