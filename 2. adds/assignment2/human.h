#ifndef _HUMAN_H
#define _HUMAN_H

#include <iostream>
#include <string>
#include "match.h"

using namespace std;

class human : public match{

private:
	string plays;

public:
	human();
	void getInput( );
	~human();
};

#endif //_HUMAN_H
