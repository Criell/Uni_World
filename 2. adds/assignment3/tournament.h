#ifndef _TOURNAMENT_H
#define _TOURNAMENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "human.h"
#include "computer.h"
#include "RandomComputer.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "PaperDoll.h"
#include "FistfullODollars.h"
#include "player.h"
#include "referee.h"

class tournament{

public:
	tournament();
	void getInput();
	void driver(referee r1);
	~tournament();

private:
	referee Ref;
	
	//store input, every play and the output.
	std::string input[8];
	std::string play;
	std::string output;

	int m;	//Store the number of the winner in semi and finals
	int n;  //Store the number of the winner in semi and finals
	int w1; //Store the player1's number of wins
	int w2; //Store the player2's number of wins
	
	computer *players[8]; //store the players

	//Computer pointers that store the winner of the matches
	computer* winners[4];
	computer* semi[2];
	computer* final;
};

#endif //_TOURNAMENT_H
