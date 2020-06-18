#ifndef _BUREAUCRAT_H
#define _BUREAUCRAT_H

#include <iostream>
#include <string>
#include "player.h"
#include "computer.h"

class Bureaucrat : public computer{

public:
	Bureaucrat(std::string t);
	void MatchMoves();
	~Bureaucrat();
};

#endif //_BUREAUCRAT_H