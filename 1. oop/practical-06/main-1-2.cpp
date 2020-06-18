#include <iostream>
#include <string>
#include "person.h"

using namespace std;

// main program
int main()
{
  person p1("Diana", 100), p2("Lina", 150), p3("Nestor", 120), p4("Aurora", 170);

  std::cout << p1.getName() << ", " << p1.getSalary() << std::endl;
  std::cout << p2.getName() << ", " << p2.getSalary() << std::endl;
  std::cout << p3.getName() << ", " << p3.getSalary() << std::endl;
  std::cout << p4.getName() << ", " << p4.getSalary() << std::endl;
}
