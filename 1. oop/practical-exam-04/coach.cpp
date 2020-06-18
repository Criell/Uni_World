#include <iostream>
#include <stdlib.h>

#include "person.h"
#include "coach.h"

using namespace std;

int Coach::nextID = 0;

Coach::Coach(string n, int sl) : Person (n, "coach",sl){
	personID = nextID;
	nextID++;
}

int Coach::get_salary(){
	if (serviceLength <10)
		return salary;
	else 
		return salary*2;
}

Coach::~Coach(){}