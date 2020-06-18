#include <iostream>
#include <stdlib.h>
#include <string>

extern void print_as_binary (std::string decimal_number);

int main()
{
  std::string decimal_number = "255";
  
  //std::cout<<"The binary number is: ";
  print_as_binary(decimal_number);
  
  return 0;
}