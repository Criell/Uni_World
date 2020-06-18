#include <iostream>
#include <string>
#include <cstdlib>

#include "player.h"

player::player(){}

player::player(std::string t){ name = t;}	

int player::getMatches(){return matches;}
	
void player::setMatches(int n){matches = n;}

std::string player::getMoves(){return moves;}

char* player::getiMoves(int i){ 
	char* tmp = &moves[i];
	return tmp; 
}
	
void player::setMoves(std::string n){ moves = n;}

std::string player::getName(){return name;}

player::~player(){}



