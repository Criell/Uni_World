#include <iostream>
#include <stdlib.h>

#include "animal.h"
#include "vegie.h"

using namespace std;

int vegie::nextID = 100;

vegie::vegie(string n, int v) : animal (n, v){
	animalID = nextID;
	favourite_food = "grass";
	nextID++;
}

void vegie::set_favourite_food(string f){
	favourite_food = f;
}

string vegie::get_favourite_food(){
	return favourite_food;
}

string vegie::get_name(){
	return "Safe: "+name;
}

vegie::~vegie(){}