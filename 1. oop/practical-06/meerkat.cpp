#include <iostream>
#include <string>
#include "meerkat.h"

using namespace std;

// implementation of the default meerkat constructor
meerkat::meerkat() {
}

// implementation of the default meerkat destructor
meerkat::~meerkat() {
}

// implementation of the meerkat meerName function
void meerkat::setName(string meerName) 
{
  name = meerName; 
} 

// implementation of the meerkat meerName function
void meerkat::setAge(int meerAge) 
{
  age = meerAge; 
} 


int meerkat::getAge() 
{
  return age;
}


string meerkat::getName() 
{
  return name;
}