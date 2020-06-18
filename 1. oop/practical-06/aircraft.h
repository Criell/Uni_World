#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

// Class definition for an aircraft
class aircraft
{
  public:
    aircraft(string callsign,person thePilot,person theCoPilot);
    void setPilot(person thePilot);  
    person getPilot();
    void setCoPilot(person theCoPilot); 
    person getCoPilot(); 
    void printDetails();
    ~aircraft();

  private:
    string plane;
    person pilot;
    person copilot;
	
};

#endif //AIRCRAFT_H
