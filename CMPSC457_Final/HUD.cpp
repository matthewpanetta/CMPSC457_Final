#include "HUD.h"
#include "GL\freeglut.h"
#include <string>

HUD::HUD(int WinW, int WinH){
	this->WinW = WinW;
	this->WinH = WinH;
}

void HUD::displayWood(OutputResources& o){
	std::string text = "Wood: " + std::to_string(o.get_wood());

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(20, WinH - 20);  // or wherever in window coordinates
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)text.c_str());

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HUD::displayBrick(OutputResources& o){
	std::string text = "Brick: " + std::to_string(o.get_bricks());

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(20, WinH - 40);  // or wherever in window coordinates
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)text.c_str());

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HUD::displayFood(OutputResources& o){
	std::string text = "Food: " + std::to_string(o.get_food());

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(20, WinH - 60);  // or wherever in window coordinates
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)text.c_str());

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HUD::displayMoney(OutputResources& o){
	std::string text = "Money: $" + std::to_string(o.get_money());

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(20, WinH - 80);  // or wherever in window coordinates
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)text.c_str());

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HUD::displayPeople(OutputResources& o)
{
	std::string text = "People: " + std::to_string(o.get_employed());

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(20, WinH - 100);  // or wherever in window coordinates
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)text.c_str());

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HUD::displayResources(OutputResources& o)
{
	displayWood(o);
	displayBrick(o);
	displayMoney(o);
	displayFood(o);
	displayPeople(o);
}

HUD::~HUD() { }