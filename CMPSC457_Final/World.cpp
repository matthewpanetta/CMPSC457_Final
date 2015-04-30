#include "World.h"
#include <iostream>

World::World(int rows, int cols, int WinW, int WinH) : gr(rows, cols), c(rows, cols), hud(WinW, WinH)
{
	this->WinW = WinW;
	this->WinH = WinH;
	tick = 0;
	create_building(5);
	message = "";
}

void World::draw_world()
{
	gr.drawGrid();
	c.draw();
	bm.draw_buildings();
	displayHUD();
}

void World::restart_world()
{
	bm.remove_all_buildings();
	c.setPosition(5, 5);
	create_building(5);
	o.reset();
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

Building* World::get_building_at_position()
{
	return bm.get_building(c.getPosition()[0], c.getPosition()[1]);
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

	message = bm.add_building(*bf.create_building(choice, x, y, z, tile), o);

	if (message != "Good")
	{
		//cout << message << endl;
	}
	else {
		message = "";
	}
}

void World::delete_building()
{
	// Delete the building unless it is the starting building
	if (c.getPosition()[0] != 5 || c.getPosition()[1] != 5)
	{
		bm.remove_building(*bm.get_building(c.getPosition()[0], c.getPosition()[1]));
		o.set_money(o.get_money() + 100);
	}
}

void World::next_tick()
{
	tick++;
	bm.next_tick(o);

	if (tick % 5 == 0)
	{
		o.set_money(o.get_money() + (2 * o.get_employed()));
	}
}

OutputResources* World::get_resources()
{
	return &o;
}

void World::displayHUD(){
	hud.updateWinW(WinW);
	hud.updateWinH(WinH);
	hud.displayResources(o);
	hud.displayPeople(o);
	Tile t = (*get_selected_tile());
	hud.displayTileInfo(t);
	hud.displayEvent(message);
}

void World::updateWinW(int width){
	this->WinW = width;
}

void World::updateWinH(int height){
	this->WinH = height;
}

World::~World()
{

}
