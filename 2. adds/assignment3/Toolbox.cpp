#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"
#include "Toolbox.h"

Toolbox::Toolbox(std::string t) : computer(t){}

void Toolbox::MatchMoves(){

	moves.clear();

	for (int i = 0; i < 5; i++)
	{
			moves[i] = 'S'; 
	
	}
}
	
Toolbox::~Toolbox(){}