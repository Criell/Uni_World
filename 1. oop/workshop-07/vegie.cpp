#include <iostream>
#include <stdlib.h>
#include "animal.h"
#include "vegie.h"

using namespace std;

vegie::vegie(string aSpecies)
	: animal (aSpecies)
{
	favourite_food = "Grass";
}
void vegie::setFavouriteFood(string aVegie){
	favourite_food = aVegie;
}

string vegie::getFavouriteFood(){
	return favourite_food;
}

vegie::~vegie(){}