#include <iostream>
#include <stdlib.h>
#include <string>
#include "animal.h"
#include "vegie.h"

using namespace std;

int main ()
{
	vegie G("Goat");
	cout << G.getSpecies() << ", " << G.getFavouriteFood()<<endl;
	G.setFavouriteFood("Hats");
	cout << G.getSpecies() << ", " << G.getFavouriteFood()<<endl;	

	return 0;
}