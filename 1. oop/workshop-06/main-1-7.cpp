#include <iostream>
#include "Person.h"
#include <string>

using namespace std;

// main program
int main()
{
	Person *p1, *p2, *p3;
  
  p1 = new Person("Nick", "Lecture");
  p1->print();
  
  p2 = new Person("Markus", "Lecture");
  p3 = new Person("Claudia", "Lecture");

}
