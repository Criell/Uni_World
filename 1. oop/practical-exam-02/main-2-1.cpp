#include <iostream>
#include <stdlib.h>

using namespace std; 

int *readNumbers(int length);
void dayNames (int *days, int length);

int main ()
{
  int length=5;
  int *numbers = new int [length];
 
  // **************************  call the funtion and copy in a pointer the array input by user
  numbers = readNumbers(length);
  
  // **************************  call the funtion that print i, days numbers input by user and name of day
  dayNames (numbers, length);
  
  // **************************  delete the pointers and the arrays after print
  delete [] numbers;
  
  return 0;
}