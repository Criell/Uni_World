#include <iostream>
#include <stdlib.h>
#include <string>
#include "person.h"

using namespace std;

//Implementation of the static variable that keep track of the number of ID of every new person object
int Person::ID = 0 ;

//Implementacion of the constructor with the name, age, accupation and id of the object person
Person::Person(string s, int n, string p)
{
	name = s;
	age = n;
	occupation = p;
	person_id = ID;

	ID++;
}

//Implementation of the method to change the value of the private variable age
void Person::setName(string s){
 	name = s;
}               

//Implementation of the method to access the private variable name
string Person::getName(){
	return name;
}                     

//Implementation of the method to change the value of the private variable age
void Person::setAge(int n){
	age = n;
}                  

//Implementation of the method to access the private variable age
int Person::getAge(){

	return age;
}                        

//Implementation of the method to access the private variable id
int Person::getPersonID(){
	return person_id;
}

//Implementation of the method to access the private variable occupation
string Person::getOccupation(){
	return occupation;
}

//Implementacion of the destructor
Person::~Person(){}
