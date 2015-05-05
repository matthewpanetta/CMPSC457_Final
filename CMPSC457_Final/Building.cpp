/*	Building.cpp
*	
*	This class is abstract. It is the base class for every other building type in the game. It provides base functions that every building uses. */

#include "Building.h"
#include "GL\freeglut.h"

/* Overriden Constructor */
Building::Building(GLdouble x, GLdouble y, GLdouble z, Tile t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;
	is_animating = false;
}

/* Compare Function - Allows other classes to compare buildings by their x,y,z position */
bool Building::compare(const Building& b) const
{
	if (x == b.x && y == b.y && z == b.z && t == b.t)	// If both buildings have the same x,y,z coordinates, they are the same building.
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Draw a 3D plane that can have a texture */
// Most of this code was taken from part one of lab 9.
void Building::draw_plane(Image* image)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // scale linearly when image smaller than texture

	// Load texture into OpenGL RC!
	glTexImage2D(GL_TEXTURE_2D,		// 2D texture
		0,							// level of detail 0 (normal)
		3,							// 3 color components
		image->sizeX,				// x size from image
		image->sizeY,				// y size from image
		0,							// border 0 (normal)
		GL_RGB,						// rgb color data order
		GL_UNSIGNED_BYTE,			// color componente types
		image->data					// image data itself
		);

	glBegin(GL_QUADS);		        // begin drawing a cube
	// Front Face (note that the texture's corners have to match the quad's corners)
	glTexCoord2f(0.0f, 0.5f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(0.5f, 0.5f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.5f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);		// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Texture and Quad

	// Back Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad

	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);		// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad

	// Bottom Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad

	// Right face
	glTexCoord2f(0.0f, 0.5f); glVertex3f(1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.5f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);		// Top Left Of The Texture and Quad
	glTexCoord2f(0.5f, 0.5f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad

	// Left Face
	glTexCoord2f(0.0f, 0.5f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(0.5f, 0.5f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.5f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad

	glEnd();					// done with the polygon.
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

/* Draw a 3D roof */
void Building::draw_roof()
{
	glPushMatrix();
	glTranslatef(0.0, 0.58, 0.0);
	glScalef(0.55, 0.2, 0.5);
	glBegin(GL_TRIANGLES);

	// Front
	glNormal3d(0.0, 0.5, 0.5);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Right
	glNormal3d(0.5, 0.5, 0.0);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Back
	glNormal3d(0.0, 0.5, -0.5);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// Left
	glNormal3d(-0.5, 0.5, 0.0);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
	glPopMatrix();
}

/* --------------------- SETTERS AND GETTERS --------------------- */

/* Check if this building is animating */
bool Building::check_animating()
{
	return is_animating;
}

/* Get the building's Tile */
Tile Building::get_tile()
{
	return t;
}

/* Get the building's X position */
GLfloat Building::get_x() 
{
	return x;
}

/* Get the building's Y position */
GLfloat Building::get_y()
{
	return y;
}

/* Get the building's Z position */
GLfloat Building::get_z()
{
	return z;
}

/* Destructor */
Building::~Building()
{

}
