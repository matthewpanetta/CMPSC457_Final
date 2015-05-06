#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "Texture.h"
#include <vector>

class TextureManager
{
public:
	TextureManager();				/* Default Constructor */
	void initialize_textures();		/* Bind every texture in the game */
	~TextureManager();				/* Destructor */
private:
	std::vector<Texture> textures;
};

#endif