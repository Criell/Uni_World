#ifndef _HUMAN_H
#define _HUMAN_H

#include <iostream>
#include <string>
#include "player.h"

class human : public player{

private:
	std::string plays;

public:
	human(std::string t);
	void getInput( );
	~human();
};

#endif //_HUMAN_H
