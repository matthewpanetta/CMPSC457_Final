#include "Text.h"
#include "GL\freeglut.h"

Text::Text(){
	this->r = 1.0;
	this->g = 1.0;
	this->b = 1.0;
}

//default text color is white (can change in function call) 
void Text::textToScreenLarge(float x, float y, unsigned char* text){
	// Draw text at screen coordinates (x, y), where (0, 0) is the top-left of the
	// screen in an 18-point Helvetica font
	glRasterPos2i(x, y);
	glColor4f(this->r, this->g, this->b, 1.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
}

//choose text color to be displayed
void Text::textToScreenLarge(float x, float y, unsigned char* text, float r, float g, float b){
	glRasterPos2i(x, y);
	if (r >= 1.0 || g >= 1.0 || b >= 1.0)
		glColor4f(r, g, b, 1.0f);
	else
		glColor4f(this->r, this->g, this->b, 1.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
}

void Text::textToScreenMedium(float x, float y, unsigned char* text){
	glRasterPos2i(x, y);
	glColor4f(this->r, this->g, this->b, 1.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, text);
}

void Text::textToScreenMedium(float x, float y, unsigned char* text, float r, float g, float b){
	glRasterPos2i(x, y);
	if (r >= 1.0 || g >= 1.0 || b >= 1.0)
		glColor4f(r, g, b, 1.0f);
	else
		glColor4f(this->r, this->g, this->b, 1.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, text);
}

Text::~Text(){ }