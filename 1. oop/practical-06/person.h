#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

// Class definition for a Person
class person
{
  public:

  person(string myName, int Salary);
    
  string getName();
  void setName(string myName);  
  int getSalary(); 
  void setSalary(int mySalary);

  ~person();

  private:
    string name;
    int salary;
	
};

#endif //PERSON_H
