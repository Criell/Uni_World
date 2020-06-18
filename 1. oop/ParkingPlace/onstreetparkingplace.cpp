
#include <iostream>
#include <stdlib.h>
#include <string>
#include "parkingplace.h"
#include "onstreetparkingplace.h"

using namespace std;

OnStreetParkingPlace::OnStreetParkingPlace(string o, string a, string v)
: ParkingPlace(o, a, "on-street", v){
	length = 0;
	ncondition = 0;
	setPrice(0); 
}

OnStreetParkingPlace::OnStreetParkingPlace(string o, string a, string v, string *conditions, int n)
: ParkingPlace(o, a, "on-street", v){
	length = n;
	array_conditions = new string [length];

	for (int i = 0; i < length; i++){
		array_conditions[i] = conditions[i];
	}
}

void OnStreetParkingPlace::setConditions(string *conditions, int n)
{
	length = n;
	array_conditions = new string[length];

	for (int i = 0; i < length; i++){
		 array_conditions[i] = conditions[i];
	}
}

void OnStreetParkingPlace::printConditions(){

	if (length == 0)
		cout << ncondition << endl;
	else;
	{	
		for (int i = 0; i < length; i++){
			cout << array_conditions[i] << endl;
		}

	}
	cout << getPrice()<< endl;
}

OnStreetParkingPlace::~OnStreetParkingPlace(){}
