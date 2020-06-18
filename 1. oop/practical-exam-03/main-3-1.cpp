#include <iostream>
#include <stdlib.h>
#include <string>
#include "person.h"

using namespace std;

int main ()
{

	Person p1("Lina", 30,"coach");
	Person p2("Eduardo", 32,"player");
	cout << p1.getName() << "," << p1.getOccupation()<< ","  << p1.getAge()<< ","  << p1.getPersonID() <<endl; 
	cout << p2.getName() << "," << p2.getOccupation()<< ","  << p2.getAge()<< ","  << p2.getPersonID() <<endl; 


	p1.setAge(20);
	p2.setName(" Mr Perfect");

	return 0;
}