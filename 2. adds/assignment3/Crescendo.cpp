#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"
#include "Crescendo.h"

Crescendo::Crescendo(std::string t) : computer(t){}

void Crescendo::MatchMoves(){

	moves.clear();

	moves[0] = 'P';
	moves[1] = 'S';
	moves[2] = 'R';
	moves[3] = 'P';
	moves[4] = 'S';
}
	
Crescendo::~Crescendo(){}