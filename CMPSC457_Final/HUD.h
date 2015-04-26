#pragma once
#ifndef HUD_H
#define HUD_H

#include "GL\freeglut.h"
#include "Text.h"
#include "Cursor.h"

class HUD
{
public:
	HUD();

	//top left of screen (resources)
	void displayWood(unsigned char* text, Cursor c);
	//void displayWood(float x, float y, char* text);

	void displayBrick(unsigned char* text, Cursor c);
	//void displayBrick(float x, float y, char* text);

	void displayFood(unsigned char* text, Cursor c);
	//void displayFood(float x, float y, char* text);

	void displayMoney(unsigned char* text, Cursor c);
	//void displayMoney(float x, float y, char* text);

	//top right of screen (unemployed / total people)
	void displayPeople(unsigned char* text, Cursor c);
	//void displayPeople(float x, float y, char* text);

	//middle of screen (towards top of screen) (can be any error/success/event)
	void displayEvent(unsigned char* text, Cursor c);
	//void displayEvent(float x, float y, char* text);

	//bottom left of screen
	void displayTileInfo(unsigned char* text, Cursor c);
	//void displayTileInfo(float x, float y, char* text);

	//bottom left of screen (above tile info)
	void displayHelpInfo(unsigned char* text, Cursor c);
	//void displayHelpInfo(float x, float y, char* text);

	~HUD();
private:
	Text typeWriter;

	const char* buildHelp1 = "Press ENTER to build";
	const char* buildHelp2 = "0-Bank, 1-Farm, 2-House, 3-Mill, 4-Mine, 5-Final, ENTER-Stop Building";
	


};

#endif