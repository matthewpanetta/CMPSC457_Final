#include "World.h"

World::World(int rows, int cols) : gr(rows, cols), c(rows, cols)
{
	
}

void World::draw_world()
{
	gr.drawGrid();
	c.draw();
	bm.draw_buildings();
}

Cursor* World::get_cursor()
{
	return &c;
}

Grid* World::get_grid()
{
	return &gr;
}

BuildingFactory* World::get_building_factory()
{
	return &bf;
}

Tile* World::get_selected_tile()
{
	return gr.getTile(c.getPosition()[0], c.getPosition()[1]);
}

void World::create_building(int choice, GLfloat x, GLfloat y, GLfloat z)
{
	Tile tile = (*get_selected_tile());
	bm.add_building(*bf.create_building(choice, x, y, z, tile));
}

World::~World()
{
}
