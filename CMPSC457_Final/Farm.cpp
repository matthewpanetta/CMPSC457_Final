#include "Farm.h"

Farm::Farm(GLdouble x, GLdouble y, GLdouble z, Tile t) : Building(x, y, z, t)
{
	this->t = t;
	this->x = x;
	this->y = y;
	this->z = z;

	Texture tex("../Pictures/farm_grass.bmp");
	Image* image1 = tex.get_image();

	//Set Texture Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // scale linearly when image smaller than texture

	// Load texture into OpenGL RC!
	glTexImage2D(GL_TEXTURE_2D,		// 2D texture
		0,					// level of detail 0 (normal)
		3,					// 3 color components
		image1->sizeX,		// x size from image
		image1->sizeY,		// y size from image
		0,					// border 0 (normal)
		GL_RGB,				// rgb color data order
		GL_UNSIGNED_BYTE,	// color componente types
		image1->data		// image data itself
	);
}

void Farm::draw_building()
{
	glPushMatrix();
	glTranslatef(x, y*-1, z);
	glTranslatef(0.0, -0.31, -0.25);
	glScalef(0.5, 0.5, 0.5);

	// barn
	glPushMatrix();
	glColor3f(0.89, 0.13, 0.11);
	glScalef(1.0, 0.75, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();

	// window
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-0.15, -0.05, 0.53);
	glScalef(1.5, 3.0, 1.0);

	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.2, 0.0, 0.0);
	glVertex3f(0.2, -0.1, 0.0);
	glVertex3f(0.0, -0.1, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.2, -0.1, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.2, 0.0, 0.0);
	glVertex3f(0.0, -0.1, 0.0);
	glEnd();

	glPopMatrix();

	// roof
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

	glPushMatrix();
	glTranslatef(0.0, -0.38, 0.45);
	glScalef(0.9, 0.01, 0.9);

	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);		                // begin drawing a cube

	// Front Face (note that the texture's corners have to match the quad's corners)
	glTexCoord2f(0.0f, 0.5f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(0.5f, 0.5f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.5f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Texture and Quad

	// Back Face
	glTexCoord2f(0.0f, 0.2f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.2f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.2f, 0.2f); glVertex3f(1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad

	// Top Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad

	// Bottom Face
	glTexCoord2f(0.5f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.5f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(0.5f, 0.5f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad

	// Right face
	glTexCoord2f(0.0f, 0.5f); glVertex3f(1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.5f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.5f, 0.5f); glVertex3f(1.0f, -1.0f, 1.0f);	// Bottom Left Of The Texture and Quad

	// Left Face
	glTexCoord2f(0.0f, 0.5f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(0.5f, 0.5f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(0.5f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// Top Left Of The Texture and Quad

	glEnd();	// done with the polygon.
	glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Farm::apply_perk(OutputResources &o)
{
	o.set_food(o.get_food() + t.get_soil());
}

std::string Farm::check_cost(OutputResources& o)
{
	if (o.get_money() < 150)
	{
		return "Not Enough Money";
	}
	else if (o.get_unemployed() < 2)
	{
		return "Not Enough Unemployed";
	}
	else
	{
		return "Good";
	}
}

void Farm::apply_initial_cost(OutputResources &o)
{
	o.set_money(o.get_money() - 150);
	o.set_unemployed(o.get_unemployed() - 2);
}

bool Farm::apply_cost_per_tick(OutputResources &o)
{
	if (o.get_money() >= 2 * ((o.get_employed() / 20) + 1))
	{
		o.set_money(o.get_money() - 2 * ((o.get_employed() / 20) + 1));
		return true;
	}
	else
	{
		return false;
	}
}

Farm::~Farm()
{

}