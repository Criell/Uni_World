#include <iostream>
#include <string>
#include "meerkat.h"

using namespace std;

// main program
int main() {
  meerkat c1, c2, c3, c4;
  
  c1.setName("Diana");
  c1.setAge(10);

  c2.setName("Lina");
  c2.setAge(15);

  c3.setName("Nestor");
  c3.setAge(12);

  c4.setName("Aurora");
  c4.setAge(17);

  std::cout << c1.getName() << ", " << c1.getAge() << std::endl;
  std::cout << c2.getName() << ", " << c2.getAge() << std::endl;
  std::cout << c3.getName() << ", " << c3.getAge() << std::endl;
  std::cout << c4.getName() << ", " << c4.getAge() << std::endl;
}
