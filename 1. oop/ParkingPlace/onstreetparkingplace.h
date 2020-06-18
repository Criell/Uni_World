#ifndef ONSTREETPARKINGPLACE_H
#define ONSTREETPARKINGPLACE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "parkingplace.h"

using namespace std;

class OnStreetParkingPlace: public ParkingPlace
{
	public:
		OnStreetParkingPlace(string o, string a, string v);
		OnStreetParkingPlace(string o, string a, string v, string *conditions, int n);
		void setConditions(string *conditions, int n);
		void printConditions();
		~OnStreetParkingPlace();

	protected:
		string *array_conditions;
		int length;
		int ncondition;
};

#endif //ONSTREETPARKINGPLACE_H
