#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"
#include "FistfullODollars.h"

FistfullODollars::FistfullODollars(std::string t) : computer(t){}

void FistfullODollars::MatchMoves(){

	moves.clear();

	moves[0] = 'R';
	moves[1] = 'S';
	moves[2] = 'P';
	moves[3] = 'R';
	moves[4] = 'S';
	
}
	
FistfullODollars::~FistfullODollars(){}