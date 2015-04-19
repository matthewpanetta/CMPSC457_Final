#include "World.h"

World::World(int rows, int cols) : gr(rows, cols), c(rows, cols)
{
	
}

void World::initialize_world()
{
	gr.drawGrid();
	c.draw();
}

Cursor* World::get_cursor()
{
	return &c;
}

Grid World::get_grid()
{
	return gr;
}

World::~World()
{
}
