#ifndef HUNTER_H
#define HUNTER_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "animal.h"

using namespace std;

class hunter: public animal
{
	public:
		hunter(string aSpecies);
		~hunter();
		
		void recordKills(string kill);
		string *theKills();
		int numberOfKills();
		~hunter();

	private:
		int n_kills;
		string array_kills[6];
};

#endif //HUNTER_H