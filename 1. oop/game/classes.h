#ifndef FUNCTION_H // This header file is to enable functions declared here to be used anywhere, including classes
#define FUNCTION_H

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



#ifndef MAP_H
#define MAP_H

class map
{
public:
	map(int area);
	void printMap();
	std::string getCurrentTerrain();
	void describeCurrentTerrain();
	int getXcoord();
	int getYcoord();
	bool move(int xChange, int yChange);
	void setLocation(int newX, int newY);
	location* getCurrentLocation();
	~map();
private:
	location mapGrid[8][8];
	int xCoord, yCoord; // these are map array indeces, hence range from 0-7
};


#endif // MAP_H


#ifndef LOCATION_H
#define LOCATION_H

class location
{
public:
	location();
	location(int area, std::string specification);
	void setTerrain(std::string terType);
	std::string getTerrain();
	bool getVisited();
	void makeVisited();
	bool move(int xChange, int yChange);
	void printTileGrid(creature** creatures, int numberOfCreatures);
	event* getEvent();
	bool isEvent();
	int getLocX();
	int getLocY();
	~location();
protected:
	std::string terrain;
	bool visited, isEventHere;
	tile tileGrid[12][7];
	int xCoord, yCoord; // player coords
	event* eventHere;
};


#endif // LOCATION_H

#ifndef  TILE_H
#define TILE_H

class tile
{
public:
	tile();
	tile(std::string givenType);
	void setType(std::string givenType);
	std::string getType();
	~tile();
private:
	std::string type;
};

#endif // TILE_H