#include <iostream>
#include <string>

#include "player.h"
#include "computer.h"
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(std::string t) : computer(t){}

void Bureaucrat::MatchMoves(){

	moves.clear();

	for (int i = 0; i < 5; i++)
	{
		moves[i] = 'P'; 
	}
}
	
Bureaucrat::~Bureaucrat(){}