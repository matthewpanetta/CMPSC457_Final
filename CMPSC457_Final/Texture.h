#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL\freeglut.h>
#include <stdio.h>

struct Image
{
	unsigned long sizeX;
	unsigned long sizeY;
	GLubyte *data;
};

class Texture
{
public:
	Texture(char *filename);
	int image_load();
	static unsigned int getint(FILE *fp);
	static unsigned short getshort(FILE *fp);
	Image* get_image();
	~Texture();

private:
	char *filename;
	Image *image;
};

#endif