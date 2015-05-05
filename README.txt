 ___ _______ ___ __   __ ___ ___     ___ _______ _______ _______ ___ _______ __    _ 
|   |       |   |  | |  |   |   |   |   |       |   _   |       |   |       |  |  | |
|   |       |   |  |_|  |   |   |   |   |____   |  |_|  |_     _|   |   _   |   |_| |
|   |       |   |       |   |   |   |   |____|  |       | |   | |   |  | |  |       |
|   |      _|   |       |   |   |___|   | ______|       | |   | |   |  |_|  |  _    |
|   |     |_|   ||     ||   |       |   | |_____|   _   | |   | |   |       | | |   |
|___|_______|___| |___| |___|_______|___|_______|__| |__| |___| |___|_______|_|  |__|

List of Source Files -----------------------------------------------------------------------------------------------------
Bank.cpp     -       Responsible for creating bank objects.



Program: iCivilization
Authors: Eugene Nitka, Tyler Jacobs, Matthew Panetta
Last Modified: 5/5/15
	
Description: This program executes a city simulation game. Players can build/remove buildings and manage their
city's economy. Each building has a benefit and a cost per tick. A tick is the game's time system. One tick = One second.
The world is set up as a grid. You can move around in the grid using the arrow keys on your keyboard. 

Each grid location is called a tile. Each tile has a set of raw resources (randomly generated numbers). 
There are three raw resources in the game: Trees, Soil, and Stone. Buildings use these resources to 
provide their benefits. For example, building a farm on a tile with 9 soil will provide 9 food per tick.
	
To build a building, press Enter to go into build mode. From build mode, press the corresponding number to each building:

There are a total of five buildings in the game:
 		- [0] Bank: The bank is the most expensive normal building in the game, but it is also the most powerful.
 			- Initial Build Cost:	$1000, 40 wood, 30 bricks, 2 unemployed
 			- Cost Per Tick:		10 food, 3 wood
 			- Benefit Per Tick:		Amount of money per tick depends on the tile's stone - the tile's trees
 		
 		- [1] Farm: The farm is necessary to provide food for your population.
 			- Initial Build Cost:	$150, 2 unemployed
 			- Cost Per Tick:		$1
 			- Benefit Per Tick:		Amount of food depends on the tile's soil rating.
 
 		- [2] House: Each house provides an additional three unemployed people to your city.
 			- Initial Build Cost:	$100, 5 wood, 25 bricks
 			- Cost Per Tick:		2 food, 1 wood
 			- Benefit Per Tick:		None
 
 		- [3] Mill: Mills provide wood, which some buildings require.
 			- Initial Build Cost:	$300, 3 unemployed
 			- Cost Per Tick:		$1
 			- Benefit Per Tick:		Amount of wood depends on the tile's trees rating.
 
 		- [4] Mine: Mines convert stone into brick, which houses are built from.
 			- Initial Build Cost:	$350, 4 unemployed
 			- Cost Per Tick:		$3
 			- Benefit Per Tick:		Amount of brick depends on the tile's stone rating.
 
You can delete a building at any time by navigating to it and pressing either the delete or backspace key. You will receive 50% of the building's initial cost back.
 
You can restart the game at any time by pressing the 'r' key.
 
Camera Controls: Rotate the view using the 't' key. Zoom in with the 'z' key. Press Shift + 'z' to zoom out.
