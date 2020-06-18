#include <iostream>
#include <stdlib.h>
#include "parkingplace.h"
#include "onstreetparkingplace.h"
#include "offstreetparkingplace.h"
#include "parkingsystem.h"

using namespace std;

int main ()
{
	string ob_owners[] = {"Lina", "Maria", "Nestor", "Aurora", "Diana", "Marcela", "Eduardo", "Jorge"};
	string ob_address[] = {"North", "South", "West", "East"};
	string ob_vehicle[] = {"motorcycle", "car", "motorcycle", "car"};

	int vehicle = 0;

	ParkingPlace *pointer_array_parkingplace[8];

	for (int i = 0; i < 4; i++) {
		pointer_array_parkingplace[vehicle] = new OffStreetParkingPlace(ob_owners[vehicle], ob_address[i], ob_vehicle[i]);
		vehicle++;
		pointer_array_parkingplace[vehicle] = new OnStreetParkingPlace(ob_owners[vehicle], ob_address[i], ob_vehicle[i]);
		vehicle++;
	}
		
	for (int i = 0; i < 8; i++) {
		ParkingSystem ps1(pointer_array_parkingplace, 8);
		ps1.printFreeOnStreetParkingAddresses();
	}

	for (int i = 0; i < 8; i++) {
		delete pointer_array_parkingplace[i];
	}

	return 0;	
}