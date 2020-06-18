#include <iostream>
#include <stdlib.h>

#include "animal.h"
#include "hunter.h"

using namespace std;

int hunter::nextID = 1000;

hunter::hunter(string n, int v) : animal (n, v){
	animalID = nextID;
	nextID++;
	kills=0;
}

void hunter::set_kills(int k){
	kills = k;
}

int hunter::get_kills(){
	return kills;
}

string hunter::get_name(){
	return "Hunter: "+name;
}

hunter::~hunter(){}