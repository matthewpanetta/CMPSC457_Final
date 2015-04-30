#include "Text.h"
#include "GL\freeglut.h"

Text::Text(){
	this->r = 1.0f;
	this->g = 1.0f;
	this->b = 1.0f;
}

//default text color is white (can change in function call) 
void Text::textToScreenLarge(float x, float y, unsigned char* text){
	// Draw text at screen coordinates (x, y), where (0, 0) is the top-left of the
	// screen in an 18-point Helvetica font
	glColor3d(this->r, this->g, this->b);
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
	
}

//choose text color to be displayed
void Text::textToScreenLarge(float x, float y, unsigned char* text, float r, float g, float b){
	if (r <= 1.0f && g <= 1.0f && b <= 1.0f)
		glColor4f(r, g, b, 1.0f);
	else
		glColor4f(this->r, this->g, this->b, 1.0f);
	glRasterPos2i(x, y);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
}

void Text::textToScreenMedium(float x, float y, unsigned char* text){
	glColor4f(this->r, this->g, this->b, 1.0f);
	glRasterPos2i(x, y);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, text);
}

void Text::textToScreenMedium(float x, float y, unsigned char* text, float r, float g, float b){
	if (r <= 1.0f && g <= 1.0f && b <= 1.0f)
		glColor4f(r, g, b, 1.0f);
	else
		glColor4f(this->r, this->g, this->b, 1.0f);
	glRasterPos2i(x, y);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, text);
}

Text::~Text(){ }