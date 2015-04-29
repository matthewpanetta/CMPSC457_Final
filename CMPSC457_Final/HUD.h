#pragma once
#ifndef HUD_H
#define HUD_H

#include "GL\freeglut.h"
#include "Text.h"
#include "Cursor.h"
#include "OutputResources.h"
#include "Tile.h"

class HUD
{
public:
	HUD(int WinW, int WinH);

	//top left of screen (resources)
	void displayWood(OutputResources& o);

	void displayBrick(OutputResources& o);

	void displayFood(OutputResources& o);

	void displayMoney(OutputResources& o);

	//top right of screen (unemployed / total people)
	void displayPeople(OutputResources& o);

	//middle of screen (towards top of screen) (can be any error/success/event)
	void displayEvent(unsigned char* text, Cursor c);

	//bottom left of screen
	void displayTileInfo(Tile& t);

	//bottom left of screen (above tile info)
	void displayHelpInfo(unsigned char* text, Cursor c);

	void displayResources(OutputResources &o);

	~HUD();
private:
	Text typeWriter;

	const char* buildHelp1 = "Press ENTER to build";
	const char* buildHelp2 = "0-Bank, 1-Farm, 2-House, 3-Mill, 4-Mine, 5-Final, ENTER-Stop Building";
	
	int WinW, WinH;
};

#endif