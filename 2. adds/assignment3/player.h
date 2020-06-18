#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <cstdlib>

class player{

protected:
	int matches;
	std::string moves;
	std::string name;

public:

	player();
	player(std::string t);

	int getMatches();
	void setMatches(int n);
	std::string getMoves();
	
	char* getiMoves(int i);
	void setMoves(std::string n);
	
	std::string getName();
	~player();
};

#endif //_PLAYER_H



