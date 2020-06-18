#ifndef VEGIE_H
#define VEGIE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "animal.h"

using namespace std;

class vegie: public animal
{
	public:
		vegie(string aSpecies);
		void setFavouriteFood(string aVegie);
		string getFavouriteFood();
		~vegie();

	private:
		string favourite_food;
};

#endif //VEGIE_H
