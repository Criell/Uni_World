#include <iostream>
#include <stdlib.h>

extern int count_even(int);

int main(int argc, char **argv)
{
  int number = atoi(argv[1]);
  
  std::cout<<"The sum of even positions is: "<<count_even(number)<<"\n";
  
  return 0;
}
