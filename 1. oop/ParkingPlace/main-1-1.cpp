#include <iostream>
#include <stdlib.h>
#include <string>
#include "parkingplace.h"

using namespace std;

int main ()
{
	ParkingPlace p0("Eduardo", "87 tower street" ,"off-street" , "car");
	p0.setOwner("Jorge Munar");

	ParkingPlace p1("Lina Guevara", "87 tower street" ,"on-street" , "motorcycle");

	ParkingPlace p2 ("Nestor Guevara", "23 king william" ,"on-street" , "car");
	
	ParkingPlace p3("Diana Guevara", "87 tower street" ,"on-street" , "car");
	
	return 0;
}
