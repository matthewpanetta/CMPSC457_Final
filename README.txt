 ___ _______ ___ __   __ ___ ___     ___ _______ _______ _______ ___ _______ __    _
|   |       |   |  | |  |   |   |   |   |       |   _   |       |   |       |  |  | |
|   |       |   |  |_|  |   |   |   |   |____   |  |_|  |_     _|   |   _   |   |_| |
|   |       |   |       |   |   |   |   |____|  |       | |   | |   |  | |  |       |
|   |      _|   |       |   |   |___|   | ______|       | |   | |   |  |_|  |  _    |
|   |     |_|   ||     ||   |       |   | |_____|   _   | |   | |   |       | | |   |
|___|_______|___| |___| |___|_______|___|_______|__| |__| |___| |___|_______|_|  |__|

List of Source Files -----------------------------------------------------------------------------------------------------
  Building.cpp        -    Abstract class, provides base class functionality to all building types. (draw_plane() function taken from a lab 9 example)
    Bank.cpp          -    Responsible for creating Banks
    Farm.cpp          -    Responsible for creating Farms
    House.cpp         -    Responsible for creating Houses
    Mill.cpp          -    Responsible for creating Mills
    Mine.cpp          -    Responsible for creating Mines
    Temple.cpp        -    Responsible for creating Temples

  BuildingFactory.cpp -    Return correct type of building based on input.
  BuildingManager.cpp -    Manage the buildings. Add/Remove and Process Costs/Benefits per tick.
  Cursor.cpp          -    Display and keep track of cursor position.
  Grid.cpp            -    Represents the grid. Contains a vector of tiles.
  HUD.cpp             -    Display the HUD (Heads-Up Display) to the screen.
  OutputResources.cpp -    Manage the player's resource count. (Wood, Food, Bricks, Money, Population).
  Source.cpp          -    Initialize the OpenGL main loop and execute the program.
  Text.cpp            -    Manage text size and font (used for the HUD).
  Texture.cpp         -    Manage textures in the game. Most code in this file taken from texture example in Lab 9 (by Jeff Molofee).
  Tile.cpp            -    Represents one tile in the grid. Contains raw resources, which are assigned random values.
  World.cpp           -    The main wrapper class. Contains an instance of most every other class and represents the game environment.

Compile Instructions ------------------------------------------------------------------------------------------------------
  Double click on CMPSC457_Final.exe to run this program. No installation necessary.
  If there is no CMPSC457_Final.exe on the root folder, navigate to /Release/ folder and double click on
  CMPSC457_Final.exe there.

Program Description and User Manual ---------------------------------------------------------------------------------------

  Quick Controls ------------------------------------
    Arrow Keys       - Navigate World
    Enter            - Enter/Exit Build Mode
    Delete/Backspace - Remove Building
    Home             - Rotate Left
    End              - Rotate Right
    Page Up          - Zoom In
    Page Down        - Zoom Out
    R                - Restart Game
    Q                - Quit Game

  [In Build Mode] ---------------------------
    0              - Build Bank
    1              - Build Farm
    2              - Build House
    3              - Build Mill
    4              - Build Mine
------------------------------------------------------
  Program: iCivilization
  Authors: Eugene Nitka, Tyler Jacobs, Matthew Panetta
  Last Modified: 5/5/15

  Description: This program executes a city simulation game. Players can build/remove buildings and manage their
  city's economy. Each building has a benefit and a cost per tick. A tick is the game's time system. One tick = One second.
  The world is set up as a grid. You can move around in the grid using the arrow keys on your keyboard.

  Each grid location is called a tile. Each tile has a set of raw resources (randomly generated numbers).
  There are three raw resources in the game: Trees, Soil, and Stone. Buildings use these resources to
  provide their benefits. For example, building a farm on a tile with 9 soil will provide 9 food per tick.

  To build a building, press 'Enter' to go into build mode. From build mode, press the corresponding number to each building:

  There are a total of five buildings in the game:
   		- [0] Bank: The bank is the most expensive normal building in the game, but it is also the most powerful.
   			- Initial Build Cost:	$1000, 40 wood, 30 bricks, 2 unemployed
   			- Cost Per Tick:		  10 food, 3 wood
   			- Benefit Per Tick:		Amount of money per tick depends on the tile's stone - the tile's trees

   		- [1] Farm: The farm is necessary to provide food for your population.
   			- Initial Build Cost:	$150, 2 unemployed
   			- Cost Per Tick:		  $1
   			- Benefit Per Tick:		Amount of food depends on the tile's soil rating.

   		- [2] House: Each house provides an additional three unemployed people to your city.
   			- Initial Build Cost:	$100, 5 wood, 25 bricks
   			- Cost Per Tick:		  2 food, 1 wood
   			- Benefit Per Tick:		None

   		- [3] Mill: Mills provide wood, which some buildings require.
   			- Initial Build Cost:	$300, 3 unemployed
   			- Cost Per Tick:	   	$1
   			- Benefit Per Tick:		Amount of wood depends on the tile's trees rating.

   		- [4] Mine: Mines convert stone into brick, which houses are built from.
   			- Initial Build Cost:	$350, 4 unemployed
   			- Cost Per Tick:		  $3
   			- Benefit Per Tick:		Amount of brick depends on the tile's stone rating.

  You can delete a building at any time by navigating to it and pressing either the delete or backspace key. You will receive 50% of the building's initial cost back.

  You can restart the game at any time by pressing the 'r' key.

  Camera Controls: Rotate the view using the 'Home' and 'End' keys. Zoom in using 'Page Up' and Zoom out using 'Page Down'.

Online Resources -------------------------------------------------------------------------------------------------------
  OpenGL documentation   - https://www.opengl.org/sdk/docs/
  FreeGLUT documentation - http://freeglut.sourceforge.net/docs/api.php
  Lighthouse3D Tutorials - http://www.lighthouse3d.com/tutorials/glut-tutorial/
  OpenGL forums          - https://www.opengl.org/discussion_boards/
  Lab 9 Example Programs - Written by Jeff Molofee
