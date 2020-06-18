#include <iostream>
#include <stdlib.h>
#include <string>
#include "parkingplace.h"
#include "onstreetparkingplace.h"

using namespace std;

int main ()
{
	

	OnStreetParkingPlace ospp1 ("Lina Guevara", "87 tower street", "motorcycle");
	ospp1.printConditions();

	string conditions[4] = {"Condition 1","Condition 2","Condition 3","Condition 4"};

	OnStreetParkingPlace ospp4 ("Aurora Cortes", "23 king william" , "car", conditions, 4);
	ospp4.printConditions();

	OnStreetParkingPlace ospp5 ("Dary", "87 tower street" , "car", conditions, 4);

	string newconditions[5] = {"Condition 1","Condition 2","Condition 3","Condition 4","Condition 5"};

	ospp5.setConditions(newconditions, 5);
	ospp5.printConditions();

	return 0;
}
