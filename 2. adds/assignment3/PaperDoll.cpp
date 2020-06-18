#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"
#include "PaperDoll.h"

PaperDoll::PaperDoll(std::string t) : computer(t){}

void PaperDoll::MatchMoves(){

	moves.clear();

	moves[0] = 'P';
	moves[1] = 'S';
	moves[2] = 'S';
	moves[3] = 'P';
	moves[4] = 'S';
}
	
PaperDoll::~PaperDoll(){}