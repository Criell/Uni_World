#include "classes.h"


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <curses.h>

#include "player.h"
#include "item.h"
#include "event.h"
#include "creature.h"


map::map(int area)
{
	xCoord = (rand()%8);
	yCoord = (rand()%8);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if ((j == yCoord) & (i == xCoord))
			{
				mapGrid[i][j] = location(area, "Woodsman's lodge");
			}
			else
			{
				mapGrid[i][j] = location(area, "None");
			}
		}
	}

	mapGrid[xCoord][yCoord].makeVisited();

	// then check if map is valids

}

void map::printMap()
{
	std::string lines[8][6] = {{"|","|","|","|","|","|"},{"|","|","|","|","|","|"},{"|","|","|","|","|","|"},{"|","|","|","|","|","|"},{"|","|","|","|","|","|"},{"|","|","|","|","|","|"},{"|","|","|","|","|","|"},{"|","|","|","|","|","|"}};
	// each string will be 64 characters long, as map is an 8x8 grid of locations each 8x8 characters - each string is a row

	std::string buffer = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCurrent map:\n";

	for (int i = 0; i < 8; ++i) // y coord
	{
		for (int j = 0; j < 8; ++j) // x coord - these 2 are iterating through every location
		{
			if ( ((mapGrid[j][i]).getVisited()) == true )
			{
				if ( ((mapGrid[j][i]).getTerrain()) == "Hills" )
				{
					lines[i][0] += "----___------";
					lines[i][1] += "---/   \\--_--";
					lines[i][2] += "--__-----/ \\-";
					lines[i][3] += "-/  \\--_-----";
					lines[i][4] += "---_--/ \\----";
					lines[i][5] += "--/ \\--------";
				}
				else if ( ((mapGrid[j][i]).getTerrain()) == "Woodsman's lodge" )
				{
					lines[i][0] += "-------------";
					lines[i][1] += "---______----";
					lines[i][2] += "--/__+___\\---";
					lines[i][3] += "--|  _ + |O--";
					lines[i][4] += "--| | |  |OO-";
					lines[i][5] += "-------------";
				}
				else
				{
					lines[i][0] += "-------------";
					lines[i][1] += "-------------";
					lines[i][2] += "-------------";
					lines[i][3] += "-------------";
					lines[i][4] += "-------------";
					lines[i][5] += "-------------";
				}
			}
			else
			{
				lines[i][0] += "             ";
				lines[i][1] += "             ";
				lines[i][2] += "             ";
				lines[i][3] += "             ";
				lines[i][4] += "             ";
				lines[i][5] += "             ";
			}
		}
	}

	lines[yCoord][3].replace( (13*xCoord+7), 1, "X");


	buffer += "----------------------------------------------------------------------------------------------------------\n"; // 98 chars long
	for (int m = 0; m < 8; ++m)
	{
		for (int n = 0; n < 6; ++n)
		{
			buffer += (lines[m][n] + "|\n");
		}
	}
	buffer += "----------------------------------------------------------------------------------------------------------\n"; // 98 chars long
	std::cout << buffer;
}

std::string map::getCurrentTerrain()
{
	return mapGrid[xCoord][yCoord].getTerrain();
}

void map::describeCurrentTerrain()
{
	std::cout << "You are in a " << mapGrid[xCoord][yCoord].getTerrain() << " at co-ordinates " << xCoord << ", " << yCoord << endl;
}

int map::getXcoord()
{
	return xCoord;
}

int map::getYcoord()
{
	return yCoord;
}

bool map::move(int xChange, int yChange)
{
	if ( (( xCoord + xChange ) > 7 )|(( xCoord + xChange ) < 0 )|(( yCoord + yChange ) > 7 )|(( yCoord + yChange ) < 0 ) )
	{
		return false;
	}
	else
	{
		xCoord += xChange;
		yCoord += yChange;
		mapGrid[xCoord][yCoord].makeVisited();
		return true;
	}
}

void map::setLocation(int newX, int newY) // if new coordinates exceed limitations, will set to limit.
{
	if (newX > 7)
	{
		xCoord = 7;
	}
	else if (newX < 0)
	{
		xCoord = 0;
	}
	else
	{
		xCoord = newX;
	}

	if (newY > 7)
	{
		yCoord = 7;
	}
	else if (newY < 0)
	{
		yCoord = 0;
	}
	else
	{
		yCoord = newY;
	}
}

location* map::getCurrentLocation()
{
	return &(mapGrid[xCoord][yCoord]);
}

map::~map()
{
	// cout << "deleted the map" << endl;  // only used for troubleshooting/ testing
}


location::location()
{
	terrain = "?"; // only used for troubleshooting
	visited = false;
	for (int j = 0; j < 7; ++j)
	{
		for (int i = 0; i < 12; ++i)
		{
			tileGrid[i][j] = tile();
		}
	}
	xCoord = 1;
	yCoord = 1;
	eventHere = new event();
	isEventHere = true;
}

location::location(int area, std::string specification)
{
	int random = rand();
	visited = false;
	if (specification == "None")
	{
		if (area == 1)
		{
			if ( (random%7) > 2 ) // remember, it ranges from 0 to 6
			{
				terrain = "Plains";	// Plains
			}
			else
			{
				terrain = "Hills";	// Hills
			}
		}
	}
	else
	{
		terrain = specification;
	}

	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			tileGrid[i][j] = tile();
		}
	}

	random = (rand()%3);
	
	if (random < 1)
	{
		eventHere = new event();
	}
	else
	{
		eventHere = new fight(terrain);
	}

	isEventHere = true;
	xCoord = 1;
	yCoord = 1;
}

void location::setTerrain(string terType)
{
	terrain = terType;  // potentially used for fixing a map that doesnt work, or adding story element locations
}

string location::getTerrain()
{
	return terrain;
}

bool location::getVisited()
{
	return visited;
}

void location::makeVisited()
{
	visited = true;
}

bool location::move(int xChange, int yChange)
{
	bool enemyThere = false;
	int numCreatures = eventHere->getNumberOfEnemies();
	creature** creatureList = eventHere->getCreatureList();
	for (int i = 0; i < numCreatures; ++i)
	{
		if ( ( creatureList[i]->isAlive() ) && ( creatureList[i]->getXcoord() == xCoord+xChange ) && ( creatureList[i]->getYcoord() == yCoord+yChange ) )
		{
			enemyThere = true;
		}
	}


	if ( ((xCoord + xChange)>11) || ((yCoord + yChange)>6) || ((xCoord + xChange)<0) || ((yCoord + yChange)<0) )
	{
		return false;
	}
	else if ( enemyThere )
	{
		return false;
	}
	else
	{
		xCoord += xChange;
		yCoord += yChange;
		return true;
	}
}

void location::printTileGrid(creature** creatures, int numberOfCreatures)
{
	std::string lines[7][6] = {{"","","","","",""},{"","","","","",""},{"","","","","",""},{"","","","","",""},{"","","","","",""},{"","","","","",""},{"","","","","",""}};
	std::string buffer = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	for (int i = 0; i < 7; ++i) // y coord
	{
		for (int j = 0; j < 12; ++j) // x coord
		{

			if ( ((tileGrid[j][i]).getType()) == "Grass" )
			{
				lines[i][0] += "--------/----";
				lines[i][1] += "---\\---------";
				lines[i][2] += "------\\---/--";
				lines[i][3] += "-/--/--------";
				lines[i][4] += "---------\\---";
				lines[i][5] += "--\\--------/-";
			}
			else if ( ((tileGrid[j][i]).getType()) == "Dirt" )
			{
				lines[i][0] += "-..---...----";
				lines[i][1] += "--  ----...--";
				lines[i][2] += "-----..-  ---";
				lines[i][3] += "-..---------.";
				lines[i][4] += "--  ---...---";
				lines[i][5] += "-..----------";
			}
			else if ( ((tileGrid[j][i]).getType()) == "Tree" )
			{
				lines[i][0] += "----/\\---/---";
				lines[i][1] += "---//\\\\------";
				lines[i][2] += "--//||\\\\-----";
				lines[i][3] += "----||-----\\-";
				lines[i][4] += "--\\-||--/----";
				lines[i][5] += "-------------";
			}
			else
			{
				lines[i][0] += "-------------";
				lines[i][1] += "-------------";
				lines[i][2] += "-------------";
				lines[i][3] += "-------------";
				lines[i][4] += "-------------";
				lines[i][5] += "-------------";
			}
		}
	}

	int enemyXcoord, enemyYcoord;
	for (int i = 0; i < numberOfCreatures; ++i)
	{
		if ( (creatures[i]->isAlive()) )
		{
			enemyYcoord = (creatures[i]->getYcoord());
			enemyXcoord = (creatures[i]->getXcoord());

			lines[enemyYcoord][0].replace( (13*enemyXcoord), 13, " enemy  here "); // all graphics are 13 characters wide
			lines[enemyYcoord][1].replace( (13*enemyXcoord), 13, " enemy  here ");
			lines[enemyYcoord][2].replace( (13*enemyXcoord), 13, " enemy  here ");
			lines[enemyYcoord][3].replace( (13*enemyXcoord), 13, " enemy  here ");
			lines[enemyYcoord][4].replace( (13*enemyXcoord), 13, " enemy  here ");
			lines[enemyYcoord][5].replace( (13*enemyXcoord), 13, " enemy  here ");
		}
	}

	lines[yCoord][0].replace( (13*xCoord), 13, " player here ");
	lines[yCoord][1].replace( (13*xCoord), 13, " player here ");
	lines[yCoord][2].replace( (13*xCoord), 13, " player here ");
	lines[yCoord][3].replace( (13*xCoord), 13, " player here ");
	lines[yCoord][4].replace( (13*xCoord), 13, " player here ");
	lines[yCoord][5].replace( (13*xCoord), 13, " player here ");

	buffer += "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n"; // 12x13 + 2 dashes
	for (int m = 0; m < 7; ++m)
	{
		for (int n = 0; n < 6; ++n)
		{
			buffer += ("|" + lines[m][n] + "|\n") ;
		}
	}
	buffer += "--------------------------------------------------------------------------------------------------------------------------------------------------------------\n"; // 12x13 + 2 dashes
	std::cout << buffer;
}

event* location::getEvent()
{
	return eventHere;
}

bool location::isEvent()
{
	return isEventHere;
}

int location::getLocX()
{
	return xCoord;
}

int location::getLocY()
{
	return yCoord;
}


location::~location() 
{
	// cout << "deleted a " << terrain << endl;  // only used for troubleshooting/ testing
}

tile::tile()
{
	int random = (rand()%8);
	if (random < 5)
	{
		type = "Grass";
	}
	else if (random < 6)
	{
		type = "Tree";
	}
	else
	{
		type = "Dirt";
	}
}

tile::tile(std::string givenType)
{
	type = givenType;
}

void tile::setType(std::string givenType)
{
	type = givenType;
}

std::string tile::getType()
{
	return type;
}

tile::~tile()
{

}

string aOrAn(string subsequentWord)
{
	string firstLetter = subsequentWord.substr(0,1);

	if ((firstLetter=="a")|(firstLetter=="e")|(firstLetter=="i")|(firstLetter=="o")|(firstLetter=="u")|(firstLetter=="A")|(firstLetter=="E")|(firstLetter=="I")|(firstLetter=="O")|(firstLetter=="U"))
	{
		return "an ";
	}
	else
	{
		return "a ";
	}
}

bool handleMoveCommand(string userInput, map* currentMap)
{
	if ((userInput == "go south") | (userInput == "Go south"))
	{
		return currentMap->move(0,1);
	}
	else if ((userInput == "go north") | (userInput == "Go north"))
	{
		return currentMap->move(0,-1);
	}
	else if ((userInput == "go east") | (userInput == "Go east"))
	{
		return currentMap->move(1,0);
	}
	else if ((userInput == "go west") | (userInput == "Go west"))
	{
		return currentMap->move(-1,0);
	}
	else
	{
		return false;
	}
}

void clearScreen()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

// http://www.glassgiant.com/ascii/
// Choose white on black in order to get best image. Copy the ascii version into a .txt file in the folder ascii_art,
// then change the directory being opened to that of the .txt file.
void printLocationAscii(std::string terrainType)
{
	std::ifstream file;
	if (terrainType == "Plains")
	{
		file.open("ascii_art/Plains.txt");
	}
	else if (terrainType == "Hills")
	{
		file.open("ascii_art/Hills.txt");
	}
	else if (terrainType == "Woodsman's lodge")
	{
		file.open("ascii_art/Woodsman's_lodge.txt");
	}
	else
	{
		file.open("ascii_art/Plains.txt");
	}
	
	std::string buffer = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::string singleLine;
	while(file >> singleLine)
	{
		buffer += singleLine+"\n";
	}

	std::cout << buffer; // prints whole file in format of the file
	file.close();
}

void handleEvent(map* currentMap)
{
	location* currentLocation = currentMap->getCurrentLocation();
	event* currentEvent = currentLocation->getEvent();
	std::string eventType = currentEvent->getEventType();

	if (eventType == "Fight")
	{
		int ch;
		creature** creatures = currentEvent->getCreatureList();
		int numberOfEnemies = currentEvent->getNumberOfEnemies();

		currentLocation->printTileGrid(creatures, numberOfEnemies);
		while(ch != KEY_BACKSPACE) // !( ((fight*)currentEvent)->allDead() )
		{
			initscr();
			keypad(stdscr, TRUE);
			raw();
			noecho();
			ch = getch();
			if (ch == 'w')
			{
				currentLocation->move(0,-1);
			}
			else if (ch == 's')
			{
				currentLocation->move(0,1);
			}
			else if (ch == 'a')
			{
				currentLocation->move(-1,0);
			}
			else if (ch == 'd')
			{
				currentLocation->move(1,0);
			}
			endwin();
			
			for (int i = 0; i < numberOfEnemies; ++i)
			{
				creatures[i]->takeTurn(currentLocation->getLocX(), currentLocation->getLocY(), creatures, numberOfEnemies);
			}

			currentLocation->printTileGrid(creatures, numberOfEnemies);
		}
	}
	else if (eventType == "None")
	{
		cout << "Event type None\n";
	}
	else
	{
		cout << "No matching event type, you done goofed!\n";
	}


	clearScreen();
	// will give event results here
	pressAnykey();

	clearScreen();
	printLocationAscii(currentLocation->getTerrain());
	currentMap->describeCurrentTerrain();
}

void pressAnykey()
{
	std::cout << "\nPress any key to continue...\n";
	initscr();
	keypad(stdscr, TRUE);
	raw();
	noecho();
	getch();
	endwin();
}
