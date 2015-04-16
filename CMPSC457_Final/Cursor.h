#pragma once
#ifndef CURSOR_H
#define CURSOR_H

class Cursor
{
public:
	Cursor();
	void ChangeState();
	int* getPostion();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void draw();
	~Cursor();

private:
	int coordinate[2];
	bool selection = false;
};

#endif