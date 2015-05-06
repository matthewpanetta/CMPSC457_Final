#include "EventManager.h"

/* Default Constructor - set all events to false */
EventManager::EventManager()
{
	fraud = false;
	forest_fire = false;
	famine = false;
	mine_collapse = false;
	drought = false;
	flood = false;
	depression = false;
	festival = false;
}

/* Start a random event */
void EventManager::initialize_event()
{
	int val = rand() % 8;

	switch (val)
	{
	case 0:
		fraud = true; break;
	case 1:
		forest_fire = true; break;
	case 2:
		famine = true; break;
	case 3:
		mine_collapse = true; break;
	case 4:
		drought = true; break;
	case 5:
		flood = true; break;
	case 6:
		depression = true; break;
	case 7:
		festival = true; break;
	}
}

/* Return which event is currently happening */
std::string EventManager::get_current_event()
{
	if (fraud) return "Fraud";
	else if (forest_fire) return "Forest Fire";
	else if (famine) return "Famine";
	else if (mine_collapse) return "Mine Collapse";
	else if (drought) return "Drought";
	else if (flood) return "Flood";
	else if (depression) return "Depression";
	else if (festival) return "Festival";
	else return "None";
}

/* Stop all events */
void EventManager::stop_event()
{
	fraud = false;
	forest_fire = false;
	famine = false;
	mine_collapse = false;
	drought = false;
	flood = false;
	depression = false;
	festival = false;
}

/* Destructor */
EventManager::~EventManager()
{

}
