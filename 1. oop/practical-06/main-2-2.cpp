#include <iostream>
#include <string>
#include "person.h"
#include "aircraft.h"

using namespace std;

// main program
int main()
{
 	person p1("Lina", 150), p2("Nestor", 120), p3("Aurora", 170);

	aircraft a1("AV026", p1, p2);

	a1.setPilot(p3);
	a1.setCoPilot(p1);

	a1.printDetails();
}
