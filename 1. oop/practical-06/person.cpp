#include <iostream>
#include <string>
#include "person.h"

using namespace std;

// implementation of the default person constructor
person::person(string myName, int Salary)
{
  name = myName;
  salary = Salary;
}

// implementation of the person meerName function
void person::setName(string myName)
{
  name=myName; 
} 	

// implementation of the person meerName function
void person::setSalary(int mySalary)
{
  salary=mySalary;
}	

int person::getSalary() {
  return salary;
}

std::string person::getName() {
  return name;
}

// implementation of the default person destructor
person::~person()
{
}
