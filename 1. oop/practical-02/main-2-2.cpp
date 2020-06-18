#include <iostream>
#include <stdlib.h>
#include <string>

extern int binary_to_number(int binary_digits[], int number_of_digits);

int main(int argc,char **argv)
{
  std::string binary = argv[1];
  
  int number_of_digits=0;
  
  do
  {
    number_of_digits = number_of_digits +1;
  } 
  while (binary[number_of_digits]=='1' or binary[number_of_digits]=='0');

  int binary_digits[number_of_digits];
  
  for (int i=0; i<number_of_digits; ++i)
  {
  
      if (binary[i]=='1')
      {
        binary_digits[i]=1;
      }
      
      else
      {
        binary_digits[i]=0;
      }
   }
  std::cout<<binary_to_number(binary_digits, number_of_digits)<<'\n';
  
  return 0;
}
