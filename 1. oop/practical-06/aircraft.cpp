#include <iostream>
#include <string>
#include "person.h"
#include "aircraft.h"

using namespace std;

// implementation of the aircraft constructor
aircraft::aircraft(string callsign, person thePilot, person theCoPilot) 
: plane(callsign), pilot(thePilot), copilot(theCoPilot)
{
	
}


void aircraft::setPilot(person thePilot)
{
	pilot = thePilot;
}


person aircraft::getPilot()
{
	return pilot;
}


void aircraft::setCoPilot(person theCoPilot)
{
	copilot = theCoPilot;
}


person aircraft::getCoPilot()
{
	return copilot;
}


void aircraft::printDetails()
{
	cout << plane << endl << pilot.getName() << endl << copilot.getName() << endl;
}

// implementation of the default aircraft destructor
aircraft::~aircraft(){
}
