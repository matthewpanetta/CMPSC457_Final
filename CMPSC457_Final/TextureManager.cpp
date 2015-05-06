/*	TextureManager.cpp
*	
*	This class is responsible for binding every texture in the game.
*/


#include "TextureManager.h"

/* Default Constructor */
TextureManager::TextureManager()
{
	textures.push_back(Texture("../Pictures/wood_house.bmp"));
	textures.push_back(Texture("../Pictures/house_grass_dark.bmp"));
	textures.push_back(Texture("../Pictures/house_roof.bmp"));
	textures.push_back(Texture("../Pictures/brick_house.bmp"));
	textures.push_back(Texture("../Pictures/house_grass.bmp"));
	textures.push_back(Texture("../Pictures/tile_house_roof.bmp"));
	textures.push_back(Texture("../Pictures/house_siding.bmp"));
	textures.push_back(Texture("../Pictures/wood_door.bmp"));
	textures.push_back(Texture("../Pictures/house_window.bmp"));
	textures.push_back(Texture("../Pictures/farm_four_tile.bmp"));
	textures.push_back(Texture("../Pictures/barn.bmp"));
}

void TextureManager::initialize_textures()
{

}

/* Destructor */
TextureManager::~TextureManager()
{

}
