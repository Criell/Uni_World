#include <iostream>
#include "Person.h"
#include <string>

using namespace std;

// implementation of the default Person constructor
Person::Person()
{
	name = "?";
	job = "unemployed";
}

// implementation of a Person constructor taking a name and job
Person::Person (string pname, string pjob)
{
	name = pname;
	job = pjob;
	
}

// implementation of the default Person destructor
Person::~Person()
{
}
