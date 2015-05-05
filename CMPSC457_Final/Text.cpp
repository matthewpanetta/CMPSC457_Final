/*	Text.cpp
*	
*	This class is responsible for drawing text to the screen */

#include "Text.h"
#include "GL\freeglut.h"

/* Default Constructor - set text color to white */
Text::Text()
{
	this->r = 1.0f;
	this->g = 1.0f;
	this->b = 1.0f;
}

/* Display 18 point white Helvetica font to screen */
void Text::textToScreenLarge(float x, float y, unsigned char* text)
{
	// Draw text at screen coordinates (x, y), where (0, 0) is the top-left of the
	// screen in an 18-point Helvetica font
	glColor3d(this->r, this->g, this->b);
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
	
}

/* Display 18 point Helvetica font to screen with custom rgb color */
void Text::textToScreenLarge(float x, float y, unsigned char* text, float r, float g, float b)
{
	if (r <= 1.0f && g <= 1.0f && b <= 1.0f)
		glColor4f(r, g, b, 1.0f);
	else
		glColor4f(this->r, this->g, this->b, 1.0f);
	glRasterPos2i(x, y);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
}

/* Display 12 point white Helvetica font to screen */
void Text::textToScreenMedium(float x, float y, unsigned char* text)
{
	glColor4f(this->r, this->g, this->b, 1.0f);
	glRasterPos2i(x, y);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, text);
}

/* Display 12 point Helvetica font to screen with custom rgb color */
void Text::textToScreenMedium(float x, float y, unsigned char* text, float r, float g, float b)
{
	if (r <= 1.0f && g <= 1.0f && b <= 1.0f)
		glColor4f(r, g, b, 1.0f);
	else
		glColor4f(this->r, this->g, this->b, 1.0f);
	glRasterPos2i(x, y);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, text);
}

/* Destructor */
Text::~Text()
{ 

}