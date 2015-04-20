/* Program: skeleton_code3D.cpp
*
* This skeleton can be used as a starting
* point for most 3D applications.
*
*/

#ifdef __APPLE__
#include <unistd.h>
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
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

using namespace std;

int WinW = 500;
int WinH = 500;

int grid[10][10];
double rotate = 0;
bool build_mode = false;

World w(10,10);		// Create a 10x10 world.

/*
*  This function is called whenever the display needs to redrawn.
*  First call when program starts.
*/

void Display(void)
{
	/* Load the identity matrix */
	glLoadIdentity();

	/* Set the view to follow the cursor */
	gluLookAt
	(
		0.0 + w.get_cursor()->getPosition()[0],		// eye x
		5.0,										// eye y
		10.0 + w.get_cursor()->getPosition()[1],	// eye z
		w.get_cursor()->getPosition()[0],			// grid x 
		0.0,										// grid y
		w.get_cursor()->getPosition()[1],			// grid z
		0.0, 
		1.0,										// up vector
		0.0
	);

	/* draw to the back buffer */
	glDrawBuffer(GL_BACK);

	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Draw the grid and buildings */
	w.draw_world();

	/* before returning, flush the graphics buffer
	* so all graphics appear in the window */
	glFlush();
	glutSwapBuffers();
}

/*
*  reshape event occurs when the user resizes
*  the window and when the window first pops up;
*  unregistered callback.
*/
void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	WinW = w;
	WinH = h;
}

/*
*  Mouse event occurs when a mouse button is pressed
*  OR released. The button parameter may be
*  GLUT_LEFT_BUTTON (0), GLUT_RIGHT_BOTTON (2), or
*  GLUT_MIDDLE_BUTTON (1). The state parameter is
*  GLUT_DOWN (0) if the mouse button was pressed, and
*  GLUT_UP (1) if the mouse button was released.
*  (x,y) is the location of the mouse in the screen
*  window coordinate system.
*/
void Mouse(int button, int state, int x, int y)
{

}

/*
*  A keyboard event occurs when the user presses a key.
*/
void Keyboard(unsigned char key, int x, int y)
{
	if (!build_mode)
	{
		switch (key)
		{
		case 13:
			build_mode = true;	break;		// Switch to build mode, allowing user to type in a number (0-4) to build a building.
		case 'q':
			exit(0);
		}
	}
	else
	{
		int choice = 0;

		if (key >= 48 && key <= 52)			// 0 = Bank; 1 = Farm; 2 = House; 3 = Mill; 4 = Mine
		{
			choice = key - 48;				// 0 = key code 48.
			w.create_building(choice);		// create a building
		}
		else
		{
			cout << "Invalid building type" << endl;	// Invalid building
		}

		build_mode = false;					// reset build mode to false
	}

	glutPostRedisplay();					// redraw scene with building
}

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
	}

	glutPostRedisplay();
}

/*
* An idle event is generated when no other
* event occurs.
*/
void Idle(void)
{
	cout << "Idle event occurred\n";
}

/*
* Timer callback function.
*/
void Timer(int value)
{
	/* Set the next timer event to occur.
	* The arguments 100, Timer, and 1 are
	* the number of milliseconds until the
	* event is triggered, the name of the
	* function to invoke at that time, and
	* the value to be passed to that function.
	*/
	w.next_tick();
	glutPostRedisplay();

	glutTimerFunc(1000, Timer, 1);
}

/*
* Set window attributes
*/
void myInit()
{
	/* set color used when clearing the window to black */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* set drawing color to white */
	glColor3f(1.0, 1.0, 1.0);

	/* set up orthographic projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Enable hidden--surface--removal */
	glEnable(GL_DEPTH_TEST);

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
	glutMouseFunc(Mouse);
	glutReshapeFunc(Reshape);
	glutTimerFunc(1000, Timer, 1);

	/* set window attributes */
	myInit();

	/* start event processing */
	glutMainLoop();
}