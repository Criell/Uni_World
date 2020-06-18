#ifndef _COMPUTER_H
#define _COMPUTER_H

#include <iostream>
#include <string>
#include "match.h"

using namespace std;

class computer : public match{

public:
	computer();
	void randMoves(int m);
	~computer();
};

#endif //_COMPUTER_H