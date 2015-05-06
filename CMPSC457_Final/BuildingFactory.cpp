/*	BuildingFactory.cpp
*	
*	This class is responsible for returning the correct building, based on user input.
*	
*	Building is an interface, and each building type is a subclass of building.
*	This class uses polymorphism to return a building object as a pointer. */

#include "BuildingFactory.h"
#include "Farm.h"
#include "Mill.h"
#include "Mine.h"
#include "Bank.h"
#include "House.h"
#include "Temple.h"

#include <iostream>

/* Default Constructor */
BuildingFactory::BuildingFactory()
{
	
}

/* Add the texture vector */
void BuildingFactory::add_texture_vector(std::vector<Texture> & images)
{
	this->images = images;
}

/* Initialize every texture in the game */
// Note that this function solves the case where textures were being loaded in every time a building was created.
// Access the static vector by World::images
void BuildingFactory::initialize_textures()
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
	Texture grass_dirt("../Pictures/grass_dirt.bmp");
	Texture mine_tex("../Pictures/mine_tex.bmp");
	Texture bank_tex("../Pictures/bank_tex.bmp");
	Texture temple_tex("../Pictures/temple_tex.bmp");

	/* Push the texture into the vector */
	images.push_back(wood_house);			// 0
	images.push_back(house_grass_dark);		// 1
	images.push_back(house_roof);			// 2
	images.push_back(brick_house);			// 3
	images.push_back(house_grass);			// 4
	images.push_back(tile_house_roof);		// 5
	images.push_back(house_siding);			// 6
	images.push_back(wood_door);			// 7
	images.push_back(house_window);			// 8
	images.push_back(farm_ground);			// 9
	images.push_back(barn);					// 10
	images.push_back(grass_dirt);			// 11
	images.push_back(mine_tex);				// 12
	images.push_back(bank_tex);				// 13
	images.push_back(temple_tex);			// 14
}

/* Return the correct building type based on the building type */
Building* BuildingFactory::create_building(int building_type, GLdouble x, GLdouble y, GLdouble z, Tile t)
{
	/* Returns a building at the specified location and tile */
	switch (building_type)
	{
		case 0: return new Bank(x, y, z, t, images);
		case 1: return new Farm(x, y, z, t, images);
		case 2: return new House(x, y, z, t, images);
		case 3: return new Mill(x, y, z, t, images);
		case 4: return new Mine(x, y, z, t, images);
		case 5: return new Temple(x, y, z, t, images);
		default: return NULL;
	}
}

/* Destructor */
BuildingFactory::~BuildingFactory()
{
}
