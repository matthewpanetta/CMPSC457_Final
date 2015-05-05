/*	Cursor.h
*
*	This class is responsible for drawing, moving, and keeping track of the position of the cursor object (white rectangle on screen)
*	The cursor moves from tile to tile. */

#pragma once
#ifndef CURSOR_H
#define CURSOR_H

class Cursor
{
public:
	Cursor(int, int);				/* Initialize cursor with r rows and c cols. Initial cursor position = 5,5 */
	int* getPosition();				/* Return array containing the current position of the cursor */
	void setPosition(int, int);		/* Set the cursor's position */
	void moveRight();				/* x = x + 1 */
	void moveLeft();				/* x = x - 1 */
	void moveUp();					/* z = z - 1 */
	void moveDown();				/* z = z + 1 */
	void draw();					/* Draw the cursor to screen */
	void ChangeState();				/* Change the cursor's state */
	~Cursor();						/* Destructor */

private:
	int rows, cols;					/* Total number of rows and cols in grid */
	int coordinate[2];				/* Current cursor position [0] = row; [1] = col */
	bool selection = false;			/* Flag is cursor is selected */
};

#endif