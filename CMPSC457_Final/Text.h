#pragma once
#ifndef TEXT_H
#define TEXT_H

#include <cstdlib>
#include "GL\freeglut.h"

class Text
{
public:
	Text();

	//default text color is white (text is GLUT_BITMAP_HELVETICA_18)
	void textToScreenLarge(float x, float y, unsigned char* text);

	//choose text color to be displayed
	void textToScreenLarge(float x, float y, unsigned char* text, float r, float g, float b);

	//(text is GLUT_BITMAP_HELVETICA_12)
	void textToScreenMedium(float x, float y, unsigned char* text);

	void textToScreenMedium(float x, float y, unsigned char* text, float r, float g, float b);

	~Text();
private:
	float r, g, b;
};

#endif