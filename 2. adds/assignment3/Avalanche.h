#ifndef _AVALANCHE_H
#define _AVALANCHE_H

#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"

class Avalanche : public computer{

public:
	Avalanche(std::string t);
	void MatchMoves();
	~Avalanche();
};

#endif //_AVALANCHE_H