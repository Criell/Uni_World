#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int binary_to_number(int binary_digits[], int number_of_digits)
{
  int decimal=0;
  int base = 2;
  int n = number_of_digits;
  
  if (number_of_digits<31 and number_of_digits>1)
  {
    for (int i=0; i<number_of_digits; ++i)
    {
      n=n-1;
      if (binary_digits[i]==1)
      {
        //cout<<n<<" "<<pow(base,n)<<endl;
        //cout<<i<<" "<<binary_digits[i]<<endl;
        decimal=decimal+pow(base,n);
        //cout<<decimal<<endl;
      }  
    }
  }
  return decimal;
}