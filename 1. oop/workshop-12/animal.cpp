#include <iostream>
#include <stdlib.h>
#include "animal.h"

using namespace std;

int animal::ID = 0;

animal::animal(string n, int v){

	name = n;
	volume = v;
	animalID = ID;
	ID++;
} 
  
int animal::set_name(string n){
	name = n;
}

int animal::get_animalID(){
	return animalID;
}

int animal::set_volume(int v){
	volume = v;
}

int animal::get_volume(){
	return volume;
}

animal::~animal(){}