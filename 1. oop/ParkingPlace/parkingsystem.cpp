#include <iostream>
#include <stdlib.h>
#include "parkingplace.h"
#include "onstreetparkingplace.h"
#include "offstreetparkingplace.h"
#include "parkingsystem.h"

using namespace std;

ParkingSystem::ParkingSystem(ParkingPlace **places, int n)
	: lenght(n), pointer_place(places) {}

void ParkingSystem::printFreeOnStreetParkingAddresses() {
	for (int i = 0; i < lenght; i++) {
		//cout << pointer_place[i]->getOwner()  << pointer_place[i]->getPrice() << endl;
		if (pointer_place[i]->getPrice() == 0) {
			cout << pointer_place[i]->getAddress() << endl; 
		}
	}
}

ParkingSystem::~ParkingSystem() {}