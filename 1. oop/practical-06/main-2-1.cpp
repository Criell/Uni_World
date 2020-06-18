#include <iostream>
#include <string>
#include "meerkat.h"
#include "cart.h"

using namespace std;

// main program
int main() 
{
  meerkat mc1, mc2, mc3, mc4, mc5;

  mc1.setName("Diana");
  mc1.setAge(20);

  mc2.setName("Lina");
  mc2.setAge(15);

  mc3.setName("Nestor");
  mc3.setAge(30);

  mc4.setName("Aurora");
  mc4.setAge(28);

  mc5.setName("Eduardo");
  mc5.setAge(19);

  cart c1;

  c1.addMeerkat(mc1);
  c1.addMeerkat(mc2);
  c1.addMeerkat(mc3);
  c1.addMeerkat(mc4);
  c1.addMeerkat(mc5);

  if (c1.getCheck() == false)
  {
    cout << "The meerkat is full. Wait for the next horse drawn cart." << endl;
  }
     
  c1.printMeerkats();
}