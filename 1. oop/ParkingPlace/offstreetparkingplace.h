#ifndef OFFSTREETPARKINGPLACE_H
#define OFFSTREETPARKINGPLACE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "parkingplace.h"

using namespace std;

class OffStreetParkingPlace: public ParkingPlace
{
	public:
		OffStreetParkingPlace(string o, string a, string v);
		bool isFree();
		bool takePlace(int et);
		int freePlace(int lt) ;
		~OffStreetParkingPlace();

	protected:
		int full_time;
		int time_in;
		int time_out;
		bool Empty_Place;
		bool Full_Place;
};

#endif //OFFSTREETPARKINGPLACE_H
