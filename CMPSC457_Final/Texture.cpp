/*	Texture.cpp
*	
*	This class is responsible for loading textures from a .bmp file and returning them as an Image object.
*	The majority of the code was taken from the texture example given in lab 9 (bmpTexture.cpp). All credit goes to Jeff Molofee. */

#include "Texture.h"

/* Default Constructor */
Texture::Texture()
{

}

/* Overriden Constructor which includes a filename string */
Texture::Texture(char *filename)
{
	this->filename = filename;
	this->image = new Image();

	image_load();
}

/* Set the filename */
void Texture::set_filename(char* filename)
{
	this->filename = filename;
	this->image = new Image();

	image_load();
}

/* Load the image from file (specified by filename string) */
int Texture::image_load()
{
	FILE *file;
	unsigned long size;                 // size of the image in bytes.
	//unsigned long i;					// standard counter.
	size_t i;							// standard counter.
	unsigned short int planes;          // number of planes in image (must be 1) 
	unsigned short int bpp;             // number of bits per pixel (must be 24)
	char temp;                          // temporary color storage for bgr-rgb conversion.

	// make sure the file is there.
	if ((file = fopen(filename, "rb")) == NULL)
	{
		printf("File Not Found : %s\n", filename);
		return 0;
	}

	// seek through the bmp header, up to the width/height:
	fseek(file, 18, SEEK_CUR);

	// No 100% errorchecking anymore!!!

	// read the width
	image->sizeX = getint(file);
	printf("Width of %s: %lu\n", filename, image->sizeX);

	// read the height 
	image->sizeY = getint(file);
	printf("Height of %s: %lu\n", filename, image->sizeY);

	// calculate the size (assuming 24 bits or 3 bytes per pixel).
	size = image->sizeX * image->sizeY * 3;

	// read the planes
	planes = getshort(file);
	if (planes != 1)
	{
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	// read the bpp
	bpp = getshort(file);
	if (bpp != 24)
	{
		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}

	// seek past the rest of the bitmap header.
	fseek(file, 24, SEEK_CUR);

	// read the data. 
	image->data = new GLubyte[size];
	if (image->data == NULL)
	{
		printf("Error allocating memory for color-corrected image data");
		return 0;
	}

	if ((i = fread(image->data, size, 1, file)) != 1)
	{
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	// reverse all of the colors. (bgr -> rgb)
	for (i = 0; i<size; i += 3)
	{
		temp = image->data[i];
		image->data[i] = image->data[i + 2];
		image->data[i + 2] = temp;
	}

	// we're done.
	return 1;
}

/* Used by image_load */
unsigned int Texture::getint(FILE *fp)
{
	int c, c1, c2, c3;

	// get 4 bytes
	c = getc(fp);
	c1 = getc(fp);
	c2 = getc(fp);
	c3 = getc(fp);

	return ((unsigned int)c) +
		(((unsigned int)c1) << 8) +
		(((unsigned int)c2) << 16) +
		(((unsigned int)c3) << 24);
}

/* Used by image_load */
unsigned short Texture::getshort(FILE *fp)
{
	int c, c1;

	//get 2 bytes
	c = getc(fp);
	c1 = getc(fp);

	return ((unsigned int)c) + (((unsigned int)c1) << 8);
}

/* Get the image object */
Image* Texture::get_image()
{
	return image;
}

/* Destructor */
Texture::~Texture()
{

}
