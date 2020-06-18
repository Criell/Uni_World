#include <iostream>
#include <stdlib.h>
#include <string>
#include "person.h"
#include "coach.h"

using namespace std;

int main ()
{

	Coach p1("Lina", 30);
	Coach p2("Eduardo", 32);
	cout << p1.getName() << "," << p1.getOccupation()<< ","  << p1.getAge()<< ","  << p1.getPersonID() <<endl; 
	cout << p2.getName() << "," << p2.getOccupation()<< ","  << p2.getAge()<< ","  << p2.getPersonID() <<endl; 


	return 0;
}