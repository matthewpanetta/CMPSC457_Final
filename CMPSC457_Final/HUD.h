#pragma once
#ifndef HUD_H
#define HUD_H

#include "GL\freeglut.h"
#include "Text.h"

class HUD
{
public:
	HUD();

	void displayWood(char* text);
	void displayWood(float x, float y, char* text);

	void displayBrick(char* text);
	void displayBrick(float x, float y, char* text);

	void displayFood(char* text);
	void displayFood(float x, float y, char* text);

	~HUD();
private:
	Text typeWriter;
};

#endif