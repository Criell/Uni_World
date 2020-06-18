#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include <iostream>
#include <stdlib.h>
#include "parkingplace.h"
#include "onstreetparkingplace.h"
#include "offstreetparkingplace.h"

using namespace std;

class ParkingSystem
{
	public:
		ParkingSystem(ParkingPlace **places, int n);
		void printFreeOnStreetParkingAddresses();
		~ParkingSystem();

	private:
		int lenght;
		ParkingPlace **pointer_place;
};

#endif //PARKINGSYSTEM_H 