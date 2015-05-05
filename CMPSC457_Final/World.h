/*	World.h
*
*	This class is responsible for maintaining the entire environment, including buildings and tick count.
*	Everything flows through the World class, making it a pseudo-Wrapper class.
*
*	The World class is primarily concerned with handling other core classes, such as the BuildingManager, BuildingFactory, HUD, Grid, and Cursor, and OutputResources.
*
*	Since the World class tracks ticks, this class will be responsible for calling the BuildingManager's draw_building() function
*	every tick. It is also responsible for drawing the grid and cursor. */

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

using namespace std;

class World
{
public:
	World(int, int, int, int);		/* Overridden constructor, initialize Grid, Cursor, and HUD objects. */
	void draw_world();				/* This function is called every tick. It will re-draw the entire world. */
	void restart_world();			/* This function will reset every stat and remove every building. */
	void create_building(int);		/* Create a building */
	void delete_building();			/* Delete a Building */
	void next_tick();				/* Process the Next Tick */
	void displayHUD();				/* Display the HUD, as well as any event */

	Cursor* get_cursor();			/* Get a pointer to the Cursor object */
	Grid* get_grid();				/* Get a pointer to the Grid object */
	Building* get_building_at_position();		/* Get the building at the Cursor's current position */
	BuildingFactory* get_building_factory();	/* Get a pointer to the BuildingFactory object */
	Tile* get_selected_tile();					/* Get the Tile at the Cursor's current position */
	OutputResources* get_resources();			/* Get a pointer to the OutputResources object */

	void updateWinW(int width);		/* Set the window width variable */
	void updateWinH(int height);	/* Set the window height variable */
	void set_event_displayed(bool);				/* Set if an event should be displayed */
	void setBuildable(bool booleanie);			/* Set the build mode variable */
	bool getBuildable();			/* Get the build mode variable, which shows if the user is currently in build mode */
	bool check_animating();			/* Check if any building is currently animating */
	bool is_event_displayed();		/* Check if an event is currently being displayed */
	~World();						/* Destructor */
private:
	int WinW, WinH;					/* Window width and height variables */
	long tick;						/* Tick tracker, tick = unit of time. One tick = One second */
	bool build_mode;				/* Build mode flag			- true when the user is in build mode */
	bool is_animating;				/* Animation flag			- true when a building is animating */
	bool event_displayed;			/* Event Displayed flag		- true when the HUD needs to show a message to the user */
	bool init;						/* Init flag				- true when World is initializing */
	std::string message;			/* Message to be displayed to screen */
	Grid gr;						/* Grid object */
	Cursor c;						/* Cursor object */
	BuildingManager bm;				/* BuildingManager object */
	BuildingFactory bf;				/* BuildingFactory object */
	OutputResources o;				/* OutputResources object */
	HUD hud;						/* HUD object */
};

#endif