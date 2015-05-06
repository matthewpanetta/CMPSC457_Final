/*	Program: iCivilization
*	Authors: Eugene Nitka, Tyler Jacobs, Matthew Panetta
*	Last Modified: 5/5/15
*	
*	Description: This program executes a city simulation game. Players can build/remove buildings and manage their
*	city's economy. Each building has a benefit and a cost per tick. A tick is the game's time system. One tick = One second.
*	The world is set up as a grid. You can move around in the grid using the arrow keys on your keyboard. 
*
*	Each grid location is called a tile. Each tile has a set of raw resources (randomly generated numbers). 
*	There are three raw resources in the game: Trees, Soil, and Stone. Buildings use these resources to 
*	provide their benefits. For example, building a farm on a tile with 9 soil will provide 9 food per tick.
*	
*	To build a building, press Enter to go into build mode. From build mode, press the corresponding number to each building:
*
*	There are a total of five buildings in the game:
*		- [0] Bank: The bank is the most expensive normal building in the game, but it is also the most powerful.
*			- Initial Build Cost:	$1000, 40 wood, 30 bricks, 2 unemployed
*			- Cost Per Tick:		10 food, 3 wood
*			- Benefit Per Tick:		Amount of money per tick depends on the tile's stone - the tile's trees
*		
*		- [1] Farm: The farm is necessary to provide food for your population.
*			- Initial Build Cost:	$150, 2 unemployed
*			- Cost Per Tick:		$1
*			- Benefit Per Tick:		Amount of food depends on the tile's soil rating.
*
*		- [2] House: Each house provides an additional three unemployed people to your city.
*			- Initial Build Cost:	$100, 5 wood, 25 bricks
*			- Cost Per Tick:		2 food, 1 wood
*			- Benefit Per Tick:		None
*
*		- [3] Mill: Mills provide wood, which some buildings require.
*			- Initial Build Cost:	$300, 3 unemployed
*			- Cost Per Tick:		$1
*			- Benefit Per Tick:		Amount of wood depends on the tile's trees rating.
*
*		- [4] Mine: Mines convert stone into brick, which houses are built from.
*			- Initial Build Cost:	$350, 4 unemployed
*			- Cost Per Tick:		$3
*			- Benefit Per Tick:		Amount of brick depends on the tile's stone rating.
*
*	You can delete a building at any time by navigating to it and pressing either the delete or backspace key. You will receive 50% of the building's initial cost back.
*	
*	You can restart the game at any time by pressing the 'r' key.
*
*	Camera Controls: Rotate the view using the 'Home' and 'End' keys. Zoom in and out using the 'Page Up' and 'Page Down' keys respectively. Reset the camera by hitting the 'v' key.
*/

#ifdef __APPLE__
#include <unistd.h>
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#endif

#include "Grid.h"
#include "Building.h"
#include "Tile.h"
#include "World.h"
#include "Cursor.h"
#include "Farm.h"
#include "BuildingFactory.h"

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 
#include <time.h>
#include <string>

using namespace std;

int WinW = 500;			// window width
int WinH = 500;			// window height

double theta = 1.57;	// window rotation factor
double zoom = 0;		// window zoom

#define PI 3.14159265

double rotate = 0;		// window rotation
int tick = 0;			// global time

World w(10, 10, WinW, WinH);		// Create a 10x10 world.

/* World Light Properties */
GLfloat diffuse0[4] = { 0.75, 0.75, 0.75, 1.0f };
GLfloat position0[4] = { 5.00, 33.00, 11.00, 1.0f };
GLfloat ambient0[4] = { 0.45, 0.45, 0.45, 1.0f };
GLfloat specular0[4] = { 0.5, 0.5, 0.5, 1.0f };

GLfloat diffuse1[4] = { 0.60, 0.60, 0.60, 1.0f };
GLfloat position1[4] = { 5.00, 3.00, 0.00, 1.0f };
GLfloat ambient1[4] = { 0.35, 0.35, 0.35, 1.0f };
GLfloat specular1[4] = { 0.5, 0.5, 0.5, 1.0f };

Text typeWriter;		// Text helper

/* Main Display Function */
void Display(void)
{
	/* Load the identity matrix */
	glLoadIdentity();

	/* Set the view to follow the cursor */
	gluLookAt
	(
		cos(theta) * (5.0 + zoom) + 0.0 + w.get_cursor()->getPosition()[0],		// eye x
		4.0,																	// eye y
		sin(theta) * (5.0 + zoom) + w.get_cursor()->getPosition()[1],			// eye z
		w.get_cursor()->getPosition()[0],			// grid x 
		0.0,										// grid y
		w.get_cursor()->getPosition()[1],			// grid z
		0.0, 
		1.0,																	// up vector
		0.0
	);

	/* draw to the back buffer */
	glDrawBuffer(GL_BACK);

	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*Position and set the lighting*/
	glPushMatrix();
	//glTranslated(5.0, 5.0, 5.0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
	glLightfv(GL_LIGHT0, GL_POSITION, position0);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
	glPopMatrix();

	/* Draw the grid and buildings */
	w.draw_world();

	/* Draw immediately */
	glFlush();
	glutSwapBuffers();
}

/*
*  reshape event occurs when the user resizes
*  the window and when the window first pops up;
*  unregistered callback.
*/
void Reshape(int width, int height)
{
	/* Compute new window dimensions */
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (GLfloat)width / (GLfloat)height, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Set the window width and height variables to the new parameters */
	WinW = width;
	WinH = height;
	
	/* Update the width and height variables in the world class */
	w.updateWinW(width);
	w.updateWinH(height);
}

void Timer(int value)
{
	/* Display event timer. Allow an event to be displayed on screen for a max of three seconds. */
	if (w.is_event_displayed())
	{
		if (tick == 3)
		{
			w.set_event_displayed(false);	// Tell world to stop drawing the event to screen.
			tick = 0;						// Reset the tick count.
		}

		tick++;		// If tick doesn't equal three, continue counting.
	}

	/* Basic tick calculator */
	if (!w.check_animating())			// If there is no building currently animating
	{
		w.next_tick();					// Process the next tick in the world class
		glutPostRedisplay();			// Redraw the scene
		glutTimerFunc(1000, Timer, 1);	// Set up the Timer function for the next tick. This function will be called about once every second.
	}
	else								// If there is a building currently animating
	{
		glutTimerFunc(15, Timer, 1);	// Quickly cycle through the Timer function, but do NOT process the next tick in the world class.
		glutPostRedisplay();			// Redraw the scene.
	}
}

/* Keyboard Event Function */
void Keyboard(unsigned char key, int x, int y)
{
	if (!w.getBuildable())						// If the user is NOT currently in build mode
	{
		switch (key)
		{
		case 8:									// Backspace key
			w.delete_building(); break;			// Remove building

		case 13:									// Enter key
			w.setBuildable(true);	break;			// Switch to build mode, allowing user to type in a number (0-4) to build a building.

		case 127:								// Delete key
			w.delete_building(); break;			// Remove building

		case 'R':
		case 'r':									// R key
			w.restart_world(); break;				// Restart the world

		case 'Q':
		case 'q':								// Q key
			exit(0);							// Quit the program

		case 'V':
		case 'v':									// V key
			theta = 1.57;
			zoom  = 0.0;	   break;				// Reset the screen display
		}
	}
	else											// If the user IS currently in build mode
	{
		int choice = 0;								// Reset building choice variable

		if (key >= 48 && key <= 53)					// 0 = Bank; 1 = Farm; 2 = House; 3 = Mill; 4 = Mine
		{
			choice = key - 48;						// 0 = key code 48.
			w.create_building(choice);				// Create the building
		}
		else
		{
			cout << "Invalid building type" << endl;	// Invalid building, building choice out of bounds.
		}

		w.setBuildable(false);						// Take user out of build mode once the building is created.
	}

	glutPostRedisplay();							// Redraw the scene with building
}

/* Special Key Function */
void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		w.get_cursor()->moveUp();		break;		// Move up one tile		
	case GLUT_KEY_DOWN:
		w.get_cursor()->moveDown();		break;		// Move down one tile
	case GLUT_KEY_LEFT:
		w.get_cursor()->moveLeft();		break;		// Move left one tile
	case GLUT_KEY_RIGHT:
		w.get_cursor()->moveRight();	break;		// Move right one tile
	case GLUT_KEY_HOME:
		theta = theta + PI / 8;			break;		// Rotate around tile clockwise
	case GLUT_KEY_END:
		theta = theta - PI / 8;			break;		// Rotate around tile counter clockwise
	case GLUT_KEY_PAGE_UP:
		zoom = zoom - 0.2;				break;		// Zoom in on tile
	case GLUT_KEY_PAGE_DOWN:
		zoom = zoom + 0.2;				break;		// Zoom out on tile
	}

	glutPostRedisplay();
}

/*
* Set window attributes
*/
void myInit()
{
	/* set color used when clearing the window to black */
	//glClearColor(0.0, 0.0, 0.0, 0.0);

	/* Enable OpenGL attributes */
	glEnable(GL_DEPTH_TEST);		// Allows for 3D depth
	glEnable(GL_NORMALIZE);			// Automatically normalize
	glEnable(GL_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);									// Allow transparency
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Allow transparency
	glDepthFunc(GL_LEQUAL);

	/* Enable lights and lighting */
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	/* set drawing color to white */
	//glColor3f(1.0, 1.0, 1.0);

	/* set up orthographic projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*Create random seed using the time(doesn't work, the object is initialized before the seed)*/
	srand(time(NULL));
}

void main(int argc, char ** argv)
{
	/* initialize graphics window */
	glutInit(&argc, argv);

	/* need both double buffering and z buffer */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	/* set size of graphics window and position
	* of upper left corner on display */
	glutInitWindowSize(WinW, WinH);
	glutInitWindowPosition(0, 0);

	/* create the window */
	glutCreateWindow("CMPSC 457 Final Project");

	/* register callback functions */
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeys);
	glutReshapeFunc(Reshape);
	glutTimerFunc(1000, Timer, 1);		// Set timer function for every second. This is used to calculate ticks.

	/* set window attributes */
	myInit();

	/* start event processing */
	glutMainLoop();
}