#ifndef _TOOLBOX_H
#define _TOOLBOX_H

#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"

class Toolbox : public computer{

public:
	Toolbox(std::string t);
	void MatchMoves();
	~Toolbox();
};

#endif //_TOOLBOX_H



