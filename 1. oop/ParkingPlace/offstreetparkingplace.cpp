#include <iostream>
#include <stdlib.h>
#include <string>
#include "parkingplace.h"
#include "offstreetparkingplace.h"

using namespace std;

OffStreetParkingPlace::OffStreetParkingPlace(string o, string a, string v)
	: ParkingPlace(o, a, "off-street", v){
	Empty_Place = true;
	Full_Place = false;
}

bool OffStreetParkingPlace::isFree(){
	return Empty_Place;
}

bool OffStreetParkingPlace::takePlace(int et)
{
	if (Empty_Place == true)
	{
		time_in = et;
		Empty_Place = false;
		Full_Place = true;
	} 
	
	else if (Empty_Place == false)
	{
		Full_Place = false;
		exit(1);
	}

	return Full_Place;
}

int OffStreetParkingPlace::freePlace(int lt)
{
	if (Empty_Place == false)
	{
		time_out = lt;
		full_time = time_out - time_in;
		Empty_Place == true;
		return full_time;
	}

	else if (Empty_Place == true)
	{
		return -1;
	}


}

OffStreetParkingPlace::~OffStreetParkingPlace(){}
