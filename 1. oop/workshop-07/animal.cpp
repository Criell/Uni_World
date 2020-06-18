#include <iostream>
#include <stdlib.h>
#include "animal.h"

using namespace std;


int animal::uniqueID = 0; 

animal::animal(string aSpecies){
	
	name = aSpecies;
	species = aSpecies;
	ID = uniqueID;

	uniqueID++;
}

string animal::getSpecies(){
	return species;
}

void animal::setName(string aName){
	name = aName;
}

string animal::getName(){
	return name;
}	

int animal::getID(){
	return ID;
}		

animal::~animal(){}