#include <iostream>
#include <string>
#include <cstdlib>
#include "player.h"
#include "computer.h"
#include "RandomComputer.h"

RandomComputer::RandomComputer(std::string t) : computer(t){}

void RandomComputer::MatchMoves(){

	moves.clear();

	for (int i = 0; i < 5; i++)
	{
		int random = rand() & 9;
		if (random > 6) {moves[i] = 'R';}
		else if (random > 3) {moves[i] = 'S';}
		else {moves[i] = 'P';}
	}
}
	
RandomComputer::~RandomComputer(){}