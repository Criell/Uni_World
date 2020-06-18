#include <iostream>
#include <stdlib.h>
#include "animal.h"

using namespace std;

int main () 
{
	animal El("Elephant"), Ch("Cheetah");

	El.setName("Dumbo");

	cout << El.getSpecies() << ", " << El.getName()<< ", " << El.getID()<<endl;
	cout << Ch.getSpecies() << ", " << Ch.getName()<< ", " << Ch.getID()<<endl;

	return 0;
}