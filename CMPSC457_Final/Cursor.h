#pragma once
#ifndef CURSOR_H
#define CURSOR_H

class Cursor
{
public:
	Cursor();
	int* getPostion();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void draw();
	~Cursor();

private:
	int coordinate[2];
};

#endif