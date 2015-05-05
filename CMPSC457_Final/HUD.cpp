/*	HUD.cpp
*	
*	This class is responsible for displaying messages and stats to the user.
*	There are seperate functions to display each resource/message. However, there is also one function that will call every seperate one. */

#include "HUD.h"
#include "GL\freeglut.h"
#include <string>

/* Overridden constructor - sets the window width and height variables */
HUD::HUD(int WinW, int WinH)
{
	this->WinW = WinW;
	this->WinH = WinH;
}

/* Display user's wood count to screen */
void HUD::displayWood(OutputResources& o)
{
	std::string text = "Wood: " + std::to_string(o.get_wood());		// Text to display

	glDisable(GL_LIGHTING);		// Disable lighting to display HUD elements.
	glMatrixMode(GL_MODELVIEW);	// Switch to window coordinates to model view.
	glPushMatrix();				// Push the matrix for later.
	glLoadIdentity();			// Reset the model view matrix.

	glMatrixMode(GL_PROJECTION);	// Switch to the projection matrix.
	glPushMatrix();					// Push the projection matrix for later.
	glLoadIdentity();				// Reset the projection matrix.
	gluOrtho2D(0, WinW, 0, WinH);	// Apply a 2D orthographic projection to display text to screen without projection and depth.

	/* Draw a translucent black box around the HUD elements, to improve visibility. */
	glColor4f(0.2, 0.2, 0.2, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, WinH, 0.0);				// This black box will be around the user's refined resources (wood, food, brick, money)
	glVertex3f(165.0, WinH, 0.0);			// It is located in the top left of the screen, which is where this box is being drawn.
	glVertex3f(165.0, WinH - 90, 0.0);
	glVertex3f(0.0, WinH - 90.0, 0.0);
	glEnd();

	typeWriter.textToScreenLarge(20, WinH - 20, (unsigned char*)text.c_str());	// Draw the text to the screen at the specified location.

	glPopMatrix();					// Pop the matrix to reset it to normal.
	glMatrixMode(GL_MODELVIEW);		// Switch to model view
	glPopMatrix();					// Pop the matrix to reset it to normal.
	glEnable(GL_LIGHTING);			// Re-enable lighting.
}

/* ----------------------- NOTE: EVERY DISPLAY FUNCTION WILL FOLLOW THE ABOVE FORM. -----------------------  */

/* Display user's food count to screen */
void HUD::displayFood(OutputResources& o)
{
	std::string text = "Food: " + std::to_string(o.get_food());

	glDisable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	typeWriter.textToScreenLarge(20, WinH - 60, (unsigned char*)text.c_str());		// Draw text to screen

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

/* Display user's brick count to screen */
void HUD::displayBrick(OutputResources& o)
{
	std::string text = "Brick: " + std::to_string(o.get_bricks());

	glDisable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	typeWriter.textToScreenLarge(20, WinH - 40, (unsigned char*)text.c_str());		// Draw text to screen

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

/* Display user's money count to screen */
void HUD::displayMoney(OutputResources& o)
{
	std::string text = "Money: $" + std::to_string(o.get_money());
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	typeWriter.textToScreenLarge(20, WinH - 80, (unsigned char*)text.c_str());		// Draw text to screen

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

/* Display population count as Unemployed / Total Population */
void HUD::displayPeople(OutputResources& o)
{
	std::string text = std::to_string(o.get_unemployed()) + "/" + std::to_string(o.get_population()) + " People";
	int textWidth = textWidthLarge(text);

	glDisable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	/* Draw translucent black box around the population counter in top right of screen */
	glColor4f(0.2, 0.2, 0.2, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(WinW - textWidth - 45, WinH, 0.0);
	glVertex3f(WinW, WinH, 0.0);
	glVertex3f(WinW, WinH - 30, 0.0);
	glVertex3f(WinW - textWidth - 45, WinH - 30.0, 0.0);
	glEnd();

	typeWriter.textToScreenLarge(WinW - textWidth - 20, WinH - 20, (unsigned char*)text.c_str());		// Draw text to screen

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

/* Display an event */
void HUD::displayEvent(std::string text)
{
	int textWidth = textWidthLarge(text);		// Get width of text

	glDisable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	if (textWidth > 0)							// If an event is displayed
	{
		glColor4f(0.2, 0.2, 0.2, 0.7);			// Draw a black box around the event text in the top-center of the screen.
		glBegin(GL_POLYGON);
		glVertex3f((WinW / 2 - textWidth / 2) - 25, WinH - 100, 0.0);
		glVertex3f((WinW / 2 - textWidth / 2) + (textWidth)+25, WinH - 100, 0.0);
		glVertex3f((WinW / 2 - textWidth / 2) + (textWidth)+25, WinH - 130, 0.0);
		glVertex3f((WinW / 2 - textWidth / 2 - 25), WinH - 130, 0.0);
		glEnd();
	}

	typeWriter.textToScreenLarge(WinW / 2 - textWidth / 2, WinH - 120, (unsigned char*)text.c_str(), 1.0, 0.0, 0.15);	// Draw text to screen

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

/* Get width of the entire string in pixels */
int HUD::textWidthLarge(std::string text)
{
	int strWidth = 0;

	for (int i = 0; i < text.size(); ++i)
	{
		strWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, text[i]);		// Add up every character's width in the string
	}

	return strWidth;	// Return the width
}

/* Display tile stats to screen at the bottom */
void HUD::displayTileInfo(Tile& t)
{
	std::string text;
	text = "Trees: " + std::to_string(t.get_trees()) + " Soil: " + std::to_string(t.get_soil()) + " Stone: " + std::to_string(t.get_stone());	// Get the tile's stats and put in a string

	glDisable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	/* Draw a translucent black box around the text to improve visibility */
	glColor4f(0.2, 0.2, 0.2, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(WinW, 0.0, 0.0);
	glVertex3f(WinW, 40.0, 0.0);
	glVertex3f(0.0, 40.0, 0.0);
	glEnd();

	typeWriter.textToScreenMedium(10, 25, (unsigned char*)text.c_str());	// Display text to screen

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

/* Display information to user when in build mode. This will tell the user which button to press for each building */
void HUD::displayHelpInfo(bool build)
{
	std::string text;

	if (build){
		text = buildHelp2;		// Display text that maps each building to a button so the user knows what to press.
	}
	else {
		text = buildHelp1;		// Display text that tells the user to press the Enter key to enter build mode, as well as other actions.
	}

	glDisable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);

	typeWriter.textToScreenMedium(10, 10, (unsigned char*)text.c_str());	// Draw text to screen

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

/* Wrapper function that will call the other four display functions */
void HUD::displayResources(OutputResources& o)
{
	displayWood(o);
	displayBrick(o);
	displayMoney(o);
	displayFood(o);
}

/* Set the window width */
void HUD::updateWinW(int width)
{
	this->WinW = width;
}

/* Set the window height */
void HUD::updateWinH(int height)
{
	this->WinH = height;
}

/* Destructor */
HUD::~HUD() 
{ 

}