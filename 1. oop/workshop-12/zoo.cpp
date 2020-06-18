#include <iostream>
#include <stdlib.h>

#include "animal.h"
#include "hunter.h"
#include "vegie.h"
#include "zoo.h"

using namespace std;

zoo::zoo(){
	name = "";
	number_of_animals = 0;
	animals = new animal*[number_of_animals];
}

zoo::zoo(string n,int cows,int lions){
	name = n;
	number_of_animals = cows+lions;

	animals = new animal*[number_of_animals];

	for (int i = 0; i < number_of_animals; i++){
		if (i < cows)
			animals[i] = new vegie("Daisy",100);	
		else 
			animals[i] = new hunter("Clarence",50);
	}
}

string zoo::get_name(){
	return name;
}

int zoo::get_number_of_animals(){
	return number_of_animals;
}

animal** zoo::get_animals(){
	return animals;
}

zoo::~zoo(){
	delete[] animals;
	animals = NULL;
}

