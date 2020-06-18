#ifndef _PAPERDOLL_H
#define _PAPERDOLL_H

#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"

class PaperDoll : public computer{

public:
	PaperDoll(std::string t);
	void MatchMoves();
	~PaperDoll();
};

#endif //_PAPERDOLL_H