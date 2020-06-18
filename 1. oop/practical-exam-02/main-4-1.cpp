#include <iostream>
#include <stdlib.h>

using namespace std; 

int *readNumbers(int length);
void printSubArrays(int *numbers, int length);

int main ()
{
  int length = 5;
  int *numbers = new int [length];
  
  // **************************  call the funtion and copy in a pointer the array input by user
  numbers = readNumbers(length);
  
  // **************************  call the funtion that print i and value of array input by user
  printSubArrays(numbers, length);
  
  // **************************  delete the pointer and the array after print
  delete [] numbers;
  
  return 0;
}