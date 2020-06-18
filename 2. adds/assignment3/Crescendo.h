#ifndef _CRESCENDO_H
#define _CRESCENDO_H

#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"

class Crescendo : public computer{

public:
	Crescendo(std::string t);
	void MatchMoves();
	~Crescendo();
};

#endif //_CRESCENDO_H