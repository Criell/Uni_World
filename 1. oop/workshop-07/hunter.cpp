#include <iostream>
#include <stdlib.h>
#include <string>
#include "animal.h"
#include "hunter.h"

using namespace std;

hunter::hunter(string aSpecies)
	: animal(aSpecies)
{
	n_kills = 0;
}

void hunter::recordKills(string kill){
	array_kills[n_kills]=kill;
	n_kills++;
}

string* hunter::theKills(){
	return array_kills;
}

int hunter::numberOfKills(){
	return n_kills;
}

hunter::~hunter(){}