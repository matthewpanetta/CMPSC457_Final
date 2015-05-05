/*	Texture.h
*
*	This class is responsible for loading textures from a .bmp file and returning them as an Image object.
*	The majority of the code was taken from the texture example given in lab 9 (bmpTexture.cpp). All credit goes to Jeff Molofee. */

#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL\freeglut.h>
#include <stdio.h>

/* Image struct - used in the .cpp file */
struct Image
{
	unsigned long sizeX;
	unsigned long sizeY;
	GLubyte *data;
};

class Texture
{
public:
	Texture();										/* Default Constructor */
	Texture(char *filename);						/* Overriden Constructor which includes a filename string */
	void set_filename(char* filename);				/* Set the filename */
	int image_load();								/* Load the image from file (specified by filename string) */
	static unsigned int getint(FILE *fp);			/* Used by image_load */
	static unsigned short getshort(FILE *fp);		/* Used by image_load */
	Image* get_image();								/* Get the image object */
	~Texture();										/* Destructor */

private:
	char *filename;									/* File name of the texture file */
	Image *image;									/* Instance of the image struct */
};

#endif