#include "World.h"
#include <iostream>

World::World(int rows, int cols) : gr(rows, cols), c(rows, cols)
{
	tick = 0;
	create_building(5);
}

void World::draw_world()
{
	gr.drawGrid();
	c.draw();
	bm.draw_buildings();
	displayHUD();
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

void World::displayHUD(){
	/*//#camelCaseRules
	//"Wood: + # + ( + # + /tick)"
	char txt2[24];
	_itoa(o.get_wood(), txt2, 10);
	//strcat(txt1, txt2);
	char* txt1 = "Wood: " + txt2;
	//*txt1 = *txt1 + *txt2;
	unsigned char mem[20];
	unsigned char* text = mem;
	strcpy((char*)text, txt1);
	hud.displayWood(text, c);*/
}

World::~World()
{

}
