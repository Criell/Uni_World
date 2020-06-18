#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "player.h"
#include "human.h"
#include "computer.h"
#include "referee.h"


referee::referee(){}

//this function match 2 players and return a string with the 5 letter 
//of the results. W is the p1 wind, L id the p1 lose. 
std::string referee::getMatch(player *p1, player *p2)
{	

for (int i = 0; i < 5; i++){

	if ((*p2->getiMoves(i) == 'P') && (*p1->getiMoves(i) == 'S')) {letter[i] = 'W';}
	else if ((*p2->getiMoves(i) == 'S') && (*p1->getiMoves(i) == 'R')) {letter[i] = 'W';}
	else if ((*p1->getiMoves(i) == 'R') && (*p2->getiMoves(i) == 'P')) {letter[i] = 'L';}
	else if ((*p1->getiMoves(i) == 'P') && (*p2->getiMoves(i) == 'S')) {letter[i] = 'L';}
	else if ((*p1->getiMoves(i) == 'S') && (*p2->getiMoves(i) == 'R')) {letter[i] = 'L';}
	else if ((*p2->getiMoves(i) == 'R') && (*p1->getiMoves(i) == 'P')) {letter[i] = 'W';}
	else if (*p2->getiMoves(i) == *p1->getiMoves(i)) {letter[i] = 'T';}
	std::cout << *p2->getiMoves(i) << "  ::  " << *p1->getiMoves(i) << std::endl;

	std::cout << letter[i] << std::endl;
	
	}
	std::string wins(letter);
	std::cout << wins << std::endl;
	return wins;
}
	
referee::~referee(){}
