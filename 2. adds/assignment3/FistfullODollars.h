#ifndef _FISTFULLODOLLARS_H
#define _FISTFULLODOLLARS_H

#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"

class FistfullODollars : public computer{

public:
	FistfullODollars(std::string t);
	void MatchMoves();
	~FistfullODollars();
};

#endif //_FISTFULLODOLLARS_H