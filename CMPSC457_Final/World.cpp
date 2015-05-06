/*	World.cpp
*
*	This class is responsible for maintaining the entire environment, including buildings and tick count.
*	Everything flows through the World class, making it a pseudo-Wrapper class.
*
*	The World class is primarily concerned with handling other core classes, such as the BuildingManager, BuildingFactory, HUD, Grid, and Cursor, and OutputResources.
*	
*	Since the World class tracks ticks, this class will be responsible for calling the BuildingManager's draw_building() function
*	every tick. It is also responsible for drawing the grid and cursor. */

#include "World.h"
#include <iostream>

/* Overridden constructor, initialize Grid, Cursor, and HUD objects. */
World::World(int rows, int cols, int WinW, int WinH) : gr(rows, cols), c(rows, cols), hud(WinW, WinH)
{
	init = true;				// Set initializer flag to true while the World class initializes its variables.
	this->WinW = WinW;			// Set window width
	this->WinH = WinH;			// Set window height
	tick = 0;					// Initialize tick count
	create_building(5);			// Create starting temple in the center of the screen
	message = "";				// Initialize message variable
	build_mode = false;			// Initialize build mode to false, this boolean tracks whether the user is in build mode.
	is_animating = false;		// Initialize is_animating to false, this boolean tracks whether a building is currently animating.
	event_displayed = false;	// Initialize event_displayed to false, this boolean tracks whether an event is currently displayed on screen.
	initialize_textures();		// Initialize every texture in the game.
	init = false;				// Set initializer to false, since the World is done initializing.
}

/* This function is called every tick. It will re-draw the entire world. */
void World::draw_world()
{
	gr.drawGrid();			// Draw the grid
	c.draw();				// Draw the cursor
	bm.draw_buildings();	// Draw every building
	displayHUD();			// Draw the HUD
}

/* This function will reset every stat and remove every building. */
void World::restart_world()
{
	bm.remove_all_buildings();		// Remove every building from the building manager.
	c.setPosition(5, 5);			// Reset the cursor's position.

	init = true;					// Temples are not aloud to be built unless init is true.
	create_building(5);				// Create a temple at cursor position.
	init = false;					// Reset init to false.

	o.reset();						// Reset OutputResources. This will reset wood, food, bricks, money, and population to starting values.
}

/* Create a building */
void World::create_building(int choice)		// Choice = building type
{											// 0 = Bank; 1 = Farm; 2 = House; 3 = Mill; 4 = Mine
	if (choice < 5 || init)					// Check if choice is within bounds.
	{
		GLfloat x = c.getPosition()[0];		// Get the Cursor's X position
		GLfloat y = -2.7f;					// Starting Y position of every building
		GLfloat z = c.getPosition()[1];		// Get the Cursor's Z position
		Tile tile = (*get_selected_tile());	// Get the currently selected tile

		message = bm.add_building(*bf.create_building(choice, x, y, z, tile), o);	// Add the building by calling BuildingManager's add_building function. This returns a message.

		if (message == "Good")				// "Good" will be returned when building creation was successful.
		{
			message = "";					// Do not display this message. Reset the message variable.
		}
		else								// If the building creation was not successful, display the message.
		{
			event_displayed = true;			// Set the event_displayed flag, this will display the message when displayHUD() is called. See displayHUD() below.
		}
	}
}

/* Delete a Building */
void World::delete_building()
{
	
	// Delete the building unless it is the starting building
	if (c.getPosition()[0] != 5 || c.getPosition()[1] != 5)
	{
		std::string check = bm.check_delete(c.getPosition()[0], c.getPosition()[1], o);
		if (check == "Good")
		{
			bm.remove_building(c.getPosition()[0], c.getPosition()[1], o);		// Call the BuildingManager's remove_building function. This will remove the building at the current Cursor location.
		}																		// This will also add any deletion benefit the building has (usually 50% of initial cost).
		else
		{
			event_displayed = true;
			message = check;
		}
	}		
}

/* Process the Next Tick */
void World::next_tick()
{
	tick++;					// Increment tick

	/* Take away one of each resource every tick */
	o.set_bricks(o.get_bricks() - 1);
	o.set_wood(o.get_wood() - 1);
	o.set_food(o.get_food() - 1);
	
	if (tick % 3 == 0)			// Replenish resources every three ticks.
	{
		bm.next_tick(o);		// Call BuildingManager's next_tick function, which will redraw every building.
	}

	/* Taxes Logic */
	if (tick % 5 == 0)			// Every five seconds, a small amount of money will be added. This is due to your employed workers paying taxes.
	{
		o.set_money(o.get_money() + (4 * o.get_employed()));	// You will receive $4 for every employed worker in your city, every five seconds.
	}

	/* Attempt to trigger a random event every 15 ticks. */
	if (tick % 15 == 0)
	{
		int val = rand() % 100;		// Generate a random number from 0 - 99

		if (val > 70)				// If the random value is greater than 65, either start the event or stop the current event.
		{
			if (o.get_current_event() == "None")	// If there is no event currently, start one.
			{
				o.start_event();
				event_displayed = true;
				message = o.get_current_event();

				/* There are two events that can quickly be stopped. */
				if (o.get_current_event() == "Flood")
				{
					o.set_bricks(o.get_bricks() - 30);		// Lose 30 of each resource during a flood.
					o.set_wood(o.get_wood() - 30);
					o.set_food(o.get_food() - 30);
					o.stop_event();
				}
				else if (o.get_current_event() == "Festival")
				{
					o.set_money(o.get_money() + (10 * o.get_employed()));	// Gain $10 per employed person during a festival.
					o.stop_event();
				}
			}
			else					// If there is an event going on, stop it.
			{
				o.stop_event();
				event_displayed = true;
				message = "Event has ended.";
			}
		}
	}
}

/* Display the HUD, as well as any event */
void World::displayHUD()
{
	hud.updateWinW(WinW);				// Update the HUD's window width variable
	hud.updateWinH(WinH);				// Update the HUD's window height variable
	hud.displayResources(o);			// Re-draw the OutputResources: wood, food, brick, money
	hud.displayPeople(o);				// Re-draw the population count: Unemployed / Total Population
	Tile t = (*get_selected_tile());	// Get the tile at current Cursor position
	hud.displayTileInfo(t);				// Display the tile's stats at the bottom of the screen: Trees, Soil, Stone

	if (event_displayed)				// If the event_displayed flag is true
		hud.displayEvent(message);		// Display that event to screen

	hud.displayHelpInfo(build_mode);	// If the user is in build mode, display help text. This text tells the user which key corresponds to which building at the bottom of the screen.
}

vector<Texture> World::images;			// Initialize the static vector of textures.

/* Initialize every texture in the game */
// Note that this function solves the case where textures were being loaded in every time a building was created.
// Access the static vector by World::images
void World::initialize_textures()
{
	/* Create a texture object for every texture */
	Texture wood_house("../Pictures/wood_house.bmp");
	Texture house_grass_dark("../Pictures/house_grass_dark.bmp");
	Texture house_roof("../Pictures/house_roof.bmp");
	Texture brick_house("../Pictures/brick_house.bmp");
	Texture house_grass("../Pictures/house_grass.bmp");
	Texture tile_house_roof("../Pictures/tile_house_roof.bmp");
	Texture house_siding("../Pictures/house_siding.bmp");
	Texture wood_door("../Pictures/wood_door.bmp");
	Texture house_window("../Pictures/house_window.bmp");
	Texture farm_ground("../Pictures/farm_four_tile.bmp");
	Texture barn("../Pictures/barn.bmp");

	/* Push the texture into the vector */
	images.push_back(wood_house);
	images.push_back(house_grass_dark);
	images.push_back(house_roof);
	images.push_back(brick_house);
	images.push_back(house_grass);
	images.push_back(tile_house_roof);
	images.push_back(house_siding);
	images.push_back(wood_door);
	images.push_back(house_window);
	images.push_back(farm_ground);
	images.push_back(barn);
}

/* --------------------- GETTERS AND SETTERS --------------------- */

/* Get a pointer to the Cursor object */
Cursor* World::get_cursor()
{
	return &c;
}

/* Get a pointer to the Grid object */
Grid* World::get_grid()
{
	return &gr;
}

/* Get the building at the Cursor's current position */
Building* World::get_building_at_position()
{
	return bm.get_building(c.getPosition()[0], c.getPosition()[1]);
}

/* Get a pointer to the BuildingFactory object */
BuildingFactory* World::get_building_factory()
{
	return &bf;
}

/* Get the Tile at the Cursor's current position */
Tile* World::get_selected_tile()
{
	return gr.getTile(c.getPosition()[0], c.getPosition()[1]);
}

/* Get a pointer to the OutputResources object */
OutputResources* World::get_resources()
{
	return &o;
}

/* Set the window width variable */
void World::updateWinW(int width)
{
	this->WinW = width;
}

/* Set the window height variable */
void World::updateWinH(int height)
{
	this->WinH = height;
}

/* Set if an event should be displayed */
void World::set_event_displayed(bool event_displayed)
{
	this->event_displayed = event_displayed;
}

/* Set the build mode variable */
void World::setBuildable(bool booleanie)
{
	build_mode = booleanie;
}

/* Get the build mode variable, which shows if the user is currently in build mode */
bool World::getBuildable()
{
	return build_mode;
}

/* Check if any building is currently animating */
bool World::check_animating()
{
	return bm.check_animating();
}

/* Check if an event is currently being displayed */
bool World::is_event_displayed()
{
	return event_displayed;
}

/* Destructor */
World::~World()
{

}