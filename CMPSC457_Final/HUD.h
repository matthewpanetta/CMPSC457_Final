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
	/*void displayWood(unsigned char* text, Cursor c);*/
	void displayWood(OutputResources& o);
	//void displayWood(float x, float y, char* text);

	void displayBrick(OutputResources& o);
	//void displayBrick(float x, float y, char* text);

	void displayFood(OutputResources& o);
	//void displayFood(float x, float y, char* text);

	void displayMoney(OutputResources& o);
	//void displayMoney(float x, float y, char* text);

	//top right of screen (unemployed / total people)
	void displayPeople(OutputResources& o);
	//void displayPeople(float x, float y, char* text);

	//middle of screen (towards top of screen) (can be any error/success/event)
	void displayEvent(unsigned char* text, Cursor c);
	//void displayEvent(float x, float y, char* text);

	//bottom left of screen
	void displayTileInfo(Tile& t);
	//void displayTileInfo(float x, float y, char* text);

	//bottom left of screen (above tile info)
	void displayHelpInfo(unsigned char* text, Cursor c);
	//void displayHelpInfo(float x, float y, char* text);

	void displayResources(OutputResources &o);

	~HUD();
private:
	Text typeWriter;

	const char* buildHelp1 = "Press ENTER to build";
	const char* buildHelp2 = "0-Bank, 1-Farm, 2-House, 3-Mill, 4-Mine, 5-Final, ENTER-Stop Building";
	
	int WinW, WinH;
};

#endif