#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"
#include "Avalanche.h"

Avalanche::Avalanche(std::string t) : computer(t){}

void Avalanche::MatchMoves(){

	moves.clear();

	for (int i = 0; i < 5; i++)
	{
			moves[i] = 'R';
	}
}
	
Avalanche::~Avalanche(){}

