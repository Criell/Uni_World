#ifndef _REFEREE_H
#define _REFEREE_H

#include <iostream>
#include <string>
#include "match.h"

using namespace std;

class referee : public match{

private:
	string wins;

public:
	referee();
	string getMatch (human p1);
	~referee();
};

#endif //_REFEREE_H
