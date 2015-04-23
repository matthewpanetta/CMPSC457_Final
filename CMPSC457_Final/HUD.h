#pragma once
#ifndef HUD_H
#define HUD_H

#include "GL\freeglut.h"
#include "Text.h"

class HUD
{
public:
	HUD();

	//top left of screen (resources)
	void displayWood(char* text);
	void displayWood(float x, float y, char* text);

	void displayBrick(char* text);
	void displayBrick(float x, float y, char* text);

	void displayFood(char* text);
	void displayFood(float x, float y, char* text);

	void displayMoney(char* text);
	void displayMoney(float x, float y, char* text);

	//top right of screen (unemployed / total people)
	void displayPeople(char* text);
	void displayPeople(float x, float y, char* text);

	//middle of screen (towards top of screen) (can be any error/success/event)
	void displayEvent(char* text);
	void displayEvent(float x, float y, char* text);

	//bottom left of screen
	void displayTileInfo(char* text);
	void displayTileInfo(float x, float y, char* text);

	//bottom left of screen (above tile info)
	void displayHelpInfo(char* text);
	void displayHelpInfo(float x, float y, char* text);

	~HUD();
private:
	Text typeWriter;

	const char* buildHelp1 = "Press ENTER to build";
	const char* buildHelp2 = "0-Bank, 1-Farm, 2-House, 3-Mill, 4-Mine, 5-Final, ENTER-Stop Building";
	
};

#endif