#pragma once
#ifndef CURSOR_H
#define CURSOR_H

class Cursor
{
public:
	Cursor(int, int);
	void ChangeState();
	int* getPostion();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void draw();
	~Cursor();

private:
	int rows, cols;
	int coordinate[2];
	bool selection = false;
};

#endif