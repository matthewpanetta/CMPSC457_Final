#pragma once
#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <string>

class EventManager
{
public:
	EventManager();							/* Default Constructor - set all events to false */
	void initialize_event();				/* Start a random event */
	std::string get_current_event();		/* Return which event is currently happening */
	void stop_event();						/* Stop all events */
	~EventManager();						/* Destructor */
private:
	bool fraud, forest_fire, famine, mine_collapse, drought, flood, depression, festival;	/* Every event in the game */
};

#endif