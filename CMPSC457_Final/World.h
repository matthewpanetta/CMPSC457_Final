#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"
#include "Building.h"
#include "BuildingManager.h"
#include "BuildingFactory.h"
#include "Grid.h"
#include "Cursor.h"
#include "HUD.h"
#include <vector>

using namespace std;

class World
{
public:
	World(int, int, int, int);
	void draw_world();
	void restart_world();
	Cursor* get_cursor();
	Grid* get_grid();
	Building* get_building_at_position();
	BuildingFactory* get_building_factory();
	Tile* get_selected_tile();
	OutputResources* get_resources();
	void create_building(int);
	void delete_building();
	void next_tick();
	void displayHUD();
	void updateWinW(int width);
	void updateWinH(int height);
	bool getBuildable();
	void setBuildable(bool booleanie);
	~World();
private:
	int WinW, WinH;
	long tick;
	Grid gr;
	Cursor c;
	BuildingManager bm;
	BuildingFactory bf;
	OutputResources o;
	HUD hud;
	std::string message;
	bool build_mode;
};

#endif