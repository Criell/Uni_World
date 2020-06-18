#ifndef _REFEREE_H
#define _REFEREE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "player.h"
#include "human.h"
#include "computer.h"

class referee{

public:
	referee();
	std::string getMatch(player* p1, player *p2);
	~referee();
 
private: 
	char letter[5]; 
};

#endif //_REFEREE_H
