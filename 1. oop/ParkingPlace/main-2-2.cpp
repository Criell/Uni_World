#include <iostream>
#include <stdlib.h>
#include <string>
#include "parkingplace.h"
#include "offstreetparkingplace.h"

using namespace std;

int main ()
{
	OffStreetParkingPlace ofpp1 ("Lina Guevara", "87 tower street", "motorcycle");
	OffStreetParkingPlace ofpp2 ("Nestor Guevara", "23 king william" , "car");
	OffStreetParkingPlace ofpp3 ("Diana Guevara", "87 tower street" , "car");
	OffStreetParkingPlace ofpp4 ("Aurora Cortes", "23 king william" , "car");
	OffStreetParkingPlace ofpp5 ("Dary", "87 tower street" , "car");
	OffStreetParkingPlace ofpp6 ("Rafael", "87 tower street", "motorcycle");

	ofpp1.takePlace(9);
	ofpp2.takePlace(10);
	ofpp1.freePlace(22);
	ofpp3.takePlace(23);
	ofpp4.freePlace(24);
	ofpp5.freePlace(24);
	ofpp6.freePlace(24);

	return 0;
}
