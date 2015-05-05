/*	HUD.h
*
*	This class is responsible for displaying messages and stats to the user.
*	There are seperate functions to display each resource/message. However, there is also one function that will call every seperate one. */

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
	void displayEvent(std::string text);

	//(text is GLUT_BITMAP_HELVETICA_18)
	int textWidthLarge(std::string text);

	//bottom left of screen
	void displayTileInfo(Tile& t);

	//bottom left of screen (above tile info)
	void displayHelpInfo(bool build);

	void displayResources(OutputResources &o);

	void updateWinW(int width);

	void updateWinH(int height);

	~HUD();
private:
	Text typeWriter;

	const char* buildHelp1 = "ENTER-Build Mode, DELETE/BACKSPACE-Remove Building, r-Restart, q-Quit";
	const char* buildHelp2 = "ENTER-Stop Building, 0-Bank, 1-Farm, 2-House, 3-Mill, 4-Mine";
	
	int WinW, WinH;
};

#endif