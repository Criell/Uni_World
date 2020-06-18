#include <iostream>
#include <stdlib.h>

using namespace std; 

int *readNumbers(int length);
bool sortedArray(int *numbers, int length);

int main ()
{
  int length = 5;
  int *numbers = new int [length];
  
  // **************************  call the funtion and copy in a pointer the array input by user
  numbers = readNumbers(length);
  
  // **************************  call the funtion and print 0 if the array is no sorter or 1 if it is.
  cout<<sortedArray(numbers, length)<<endl;
  
  // **************************  delete the pointer and the array after print
  delete [] numbers;
  
  return 0;
}