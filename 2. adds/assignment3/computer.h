#ifndef _COMPUTER_H
#define _COMPUTER_H

#include <iostream>
#include <string>
#include "player.h"

class computer : public player{

public:
	computer(std::string t);

	// virtual function that every child redefine with their own way to play.
	virtual void MatchMoves() = 0;
	~computer();
};

#endif //_COMPUTER_H