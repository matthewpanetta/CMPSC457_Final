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

	glColor4f(0.2, 0.2, 0.2, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, WinH, 0.0);
	glVertex3f(165.0, WinH, 0.0);
	glVertex3f(165.0, WinH - 90, 0.0);
	glVertex3f(0.0, WinH - 90.0, 0.0);
	glEnd();

	typeWriter.textToScreenLarge(20, WinH - 20, (unsigned char*)text.c_str());

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

	typeWriter.textToScreenLarge(20, WinH - 40, (unsigned char*)text.c_str());

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

	typeWriter.textToScreenLarge(20, WinH - 60, (unsigned char*)text.c_str());

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

	typeWriter.textToScreenLarge(20, WinH - 80, (unsigned char*)text.c_str());

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HUD::displayPeople(OutputResources& o)
{
	std::string text = std::to_string(o.get_unemployed()) + "/" + std::to_string(o.get_population()) + " People";
	int textWidth = textWidthLarge(text);

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	glColor4f(0.2, 0.2, 0.2, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(WinW - textWidth - 45, WinH, 0.0);
	glVertex3f(WinW, WinH, 0.0);
	glVertex3f(WinW, WinH - 30, 0.0);
	glVertex3f(WinW - textWidth - 45, WinH - 30.0, 0.0);
	glEnd();

	typeWriter.textToScreenLarge(WinW - textWidth - 20, WinH - 20, (unsigned char*)text.c_str());

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}


void HUD::displayEvent(std::string text){
	int textWidth = textWidthLarge(text);

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	if (textWidth > 0)
	{
		glColor4f(0.2, 0.2, 0.2, 0.7);
		glBegin(GL_POLYGON);
		glVertex3f((WinW / 2 - textWidth / 2) - 25, WinH - 100, 0.0);
		glVertex3f((WinW / 2 - textWidth / 2) + (textWidth)+25, WinH - 100, 0.0);
		glVertex3f((WinW / 2 - textWidth / 2) + (textWidth)+25, WinH - 130, 0.0);
		glVertex3f((WinW / 2 - textWidth / 2 - 25), WinH - 130, 0.0);
		glEnd();
	}

	typeWriter.textToScreenLarge(WinW / 2 - textWidth / 2, WinH - 120, (unsigned char*)text.c_str(), 1.0, 0.0, 0.15);

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}


int HUD::textWidthLarge(std::string text){
	int strWidth = 0;
	for (int i = 0; i < text.size(); ++i){
		strWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
	return strWidth;
}

void HUD::displayTileInfo(Tile& t){
	std::string text;
	text = "Trees: " + std::to_string(t.get_trees()) + " Soil: " + std::to_string(t.get_soil()) + " Stone: " + std::to_string(t.get_stone());

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	glColor4f(0.2, 0.2, 0.2, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(WinW, 0.0, 0.0);
	glVertex3f(WinW, 40.0, 0.0);
	glVertex3f(0.0, 40.0, 0.0);
	glEnd();

	typeWriter.textToScreenMedium(10, 25, (unsigned char*)text.c_str());

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void HUD::displayHelpInfo(bool build){
	std::string text;

	if (build){
		text = buildHelp2;
	}
	else {
		text = buildHelp1;
	}

	glDisable(GL_LIGHTING);
	// Switch to window coordinates to render
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	typeWriter.textToScreenMedium(10, 10, (unsigned char*)text.c_str());

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
}

void HUD::updateWinW(int width){
	this->WinW = width;
}

void HUD::updateWinH(int height){
	this->WinH = height;
}

HUD::~HUD() { }