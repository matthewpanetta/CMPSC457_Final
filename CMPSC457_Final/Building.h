#pragma once
#include "GL\freeglut.h"

class Building
{
public:
	Building(GLdouble, GLdouble, GLdouble);
	GLfloat get_x();
	GLfloat get_y();
	GLfloat get_z();
	void draw_building();
	~Building();
private:
	GLfloat x, y, z;
};