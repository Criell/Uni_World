#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

extern int binary_to_number(int binary_digits[], int number_of_digits);

int main ()
{
  int number_of_digits = 6;
  int binary_digits[6] = {1, 0, 0, 1, 1, 1};
  
  cout<<binary_to_number(binary_digits, number_of_digits)<<endl;
}