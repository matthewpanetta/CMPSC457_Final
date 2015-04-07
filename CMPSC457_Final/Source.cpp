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

#include "Building.h"
#include "Tile.h"
#include "World.h"

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 
#include <time.h>

using namespace std;

#define WinW 500
#define WinH 500

World w(10,10);		// Create a 10x10 world.

/*
*  This function is called whenever the display needs to redrawn.
*  First call when program starts.
*/
void Display(void)
{
	/* draw to the back buffer */
	glDrawBuffer(GL_BACK);

	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* insert graphics code here that draws the scene */
	cout << "Display event occurred" << endl;

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
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
		2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat)w / (GLfloat)h,
		2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
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
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		GLdouble model[16];
		GLdouble projection[16];
		GLint viewport[4];
		GLfloat winX, winY, z;
		GLdouble x_pos, y_pos, z_pos;

		glGetDoublev(GL_MODELVIEW_MATRIX, model);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;

		glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);

		gluUnProject(x, y, z, model, projection, viewport, &x_pos, &y_pos, &z_pos);

		cout << "Creating a building object at" << endl;
		cout << "X: " << x_pos << endl;
		cout << "Y: " << y_pos << endl;
		cout << "Z: " << z_pos << endl;

		/*Building b(x_pos, y_pos, z_pos);
		buildings.push_back(b);*/
	}
}

/*
*  A keyboard event occurs when the user presses a key.
*/
void Keyboard(unsigned char key, int x, int y)
{
	cout << "Keyboard event occurred\n";
	cout << "key:    " << key << endl;
	cout << "x:      " << x << endl;
	cout << "y:      " << y << endl;

	switch (key)
	{
	case 'q':	exit(0);
	}
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
	glutTimerFunc(100, Timer, 1);
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
	glOrtho(-2, 2, -2, 2, -10.0, 10.0);

	/* Enable hidden--surface--removal */
	glEnable(GL_DEPTH_TEST);

	srand(time(NULL));

	vector<Tile> t = w.getTiles();		// Initialize random tiles.
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
	glutMouseFunc(Mouse);
	glutReshapeFunc(Reshape);
	/* glutTimerFunc( 100, Timer, 1 );
	glutIdleFunc(Idle);
	*/
	/* set window attributes */
	myInit();

	/* start event processing */
	glutMainLoop();
}