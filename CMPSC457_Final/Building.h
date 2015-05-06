/*	Building.h
*
*	This class is abstract. It is the base class for every other building type in the game. It provides base functions that every building uses. */

#pragma once
#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include "GL\freeglut.h"
#include "Tile.h"
#include "OutputResources.h"
#include "Texture.h"

class Building
{
public:
	Building(GLdouble, GLdouble, GLdouble, Tile);		/* Overriden Constructor */
	bool compare(const Building& b) const;				/* Compare Function - Allows other classes to compare buildings by their x,y,z position */
	
	void draw_plane(Image* image);						/* Draw a 3D plane that can have a texture */
	void draw_roof();									/* Draw a 3D roof */
	void draw_roof(Image* image);						/* Draw a 3D roof with a texture */

	bool check_animating();
	Tile get_tile();									/* Get the building's Tile */
	GLfloat get_x();									/* Get the building's X position */
	GLfloat get_y();									/* Get the building's Y position */
	GLfloat get_z();									/* Get the building's Z position */

	/* ---------- OVERLOADED OPERATORS ---------- */
	bool operator == (const Building& b) const {
		return compare(b);		// Compare both buildings when == is called
	};

	bool operator != (const Building& b) const {
		return !compare(b);		// Return opposite of compare when != is called
	};

	/* ---------- ABSTRACT FUNCTIONS ---------- */
	virtual std::string check_cost(OutputResources& o) = 0;			// Check if the user has enough resources for the specific building.
	virtual void draw_building() = 0;								// Draw the specific building according to its own polygons.
	virtual void apply_perk(OutputResources &) = 0;					// Apply the specific building's benefit per tick.
	virtual void apply_initial_cost(OutputResources &) = 0;			// Apply the building's initial cost.
	virtual bool apply_cost_per_tick(OutputResources &) = 0;		// Apply the building's cost per tick.
	virtual void delete_benefit(OutputResources&) = 0;				// Apply the building's delete benefit (usually 50% of its initial cost).
	~Building();										/* Destructor */
protected:
	bool is_animating;			// Flag to see if the building is currently animating.
private:
	GLdouble x, y, z;			// X,Y,Z coordinates of building
	Tile t;						// Tile that the building is on.
};

#endif