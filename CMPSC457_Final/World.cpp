#include "World.h"

World::World(int rows, int cols) : gr(rows, cols), c(rows, cols)
{
	tick = 0;
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

void World::create_building(int choice)
{
	GLfloat x = c.getPosition()[0];
	GLfloat y = -0.5f;
	GLfloat z = c.getPosition()[1];
	Tile tile = (*get_selected_tile());

	char* message = bm.add_building(*bf.create_building(choice, x, y, z, tile), o);

	if (message != "Good")
	{
		//hud.displayEvent(message);
	}
}

void World::next_tick()
{
	tick++;
	bm.next_tick(o);

	if (tick % 10 == 0)
	{
		o.set_money(o.get_money() + 100);
	}
}

OutputResources* World::get_resources()
{
	return &o;
}

World::~World()
{

}
