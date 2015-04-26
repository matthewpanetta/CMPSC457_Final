#include "HUD.h"
#include "GL\freeglut.h"

HUD::HUD(){
	
}

void HUD::displayWood(unsigned char* text, Cursor c){
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslated(-1.0, 1.0, 2.0);
	glRotated(90, 1.0, 0.0, 0.0);

	typeWriter.textToScreenLarge(0.0f + c.getPosition()[0], 0.0f + c.getPosition()[1], text);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HUD::displayBrick(unsigned char* text, Cursor c){

}

void HUD::displayFood(unsigned char* text, Cursor c){

}

void HUD::displayMoney(unsigned char* text, Cursor c){

}

HUD::~HUD() { }