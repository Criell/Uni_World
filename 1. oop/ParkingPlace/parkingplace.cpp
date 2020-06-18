#include <iostream>
#include <stdlib.h>
#include <string>
#include "parkingplace.h"

using namespace std;

//implementation of a static bool
bool ParkingPlace::nextFree = false;

ParkingPlace::ParkingPlace(string o, string a, string t, string v)
: owner (o), address (a), type (t), vehicle_type (v){

	if ((type != "on-street") && (type != "off-street"))
	{
		cout<<"Illegal type of parking place."<<endl;
		exit(1);
	}

	if ((vehicle_type != "car") && (vehicle_type != "motorcycle"))
	{
		cout<<"Illegal vehicule's type."<<endl;
		exit(1);
	}

	if (type == "off-street")
		price=15;

	else if (type == "on-street" && vehicle_type == "car")

		if (nextFree == true)
		{
			price=0;
			nextFree = false;
		}
		else if (nextFree == false)
		{
			price=10;
			nextFree = true;
		}

	else if (type == "on-street" && vehicle_type == "motorcycle")
		price=0;
}


void ParkingPlace::setOwner(string o){
	owner = o;
}

string ParkingPlace::getOwner(){
	return owner;
}

string ParkingPlace::getAddress(){
	return address;
}

string ParkingPlace::getType(){
	return type;
}

string ParkingPlace::getVehicleType(){
	return vehicle_type;
}

void ParkingPlace::setPrice(int p){
	if (p >= 0){ 
		price = p;
	}
}
		
int ParkingPlace::getPrice(){
	return price;
}

ParkingPlace::~ParkingPlace(){}
