#ifndef _RANDOMCOMPUTER_H
#define _RANDOMCOMPUTER_H

#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"

class RandomComputer : public computer{

public:
	RandomComputer(std::string t);
	void MatchMoves();
	~RandomComputer();
};

#endif //_RANDOMCOMPUTER_H