#include <iostream>
#include <stdlib.h>

#include "person.h"

using namespace std;


int Person::ID = 0;

Person::Person(string n, string o, int sl){
	name = n;                         
	occupation = o;
	salary = 0;                          
	serviceLength = sl;                   
	personID = ID;
	ID++;
}

string Person::get_name(){
	return name;
}

string Person::get_occupation(){
	return occupation;
}

int Person::get_personID(){
	return personID;
}  

void Person::set_name(string n){
	name = n;
}

void Person::set_occupation(int o){
	occupation = o;
}

void Person::set_salary(int s){
	if (s >= 0)
		salary = s;
}


	
Person::~Person(){}