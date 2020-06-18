#include <iostream>
#include <stdlib.h>

using namespace std; 

int *readNumbers(int length);
int *addArrays(int *numbers1,int *numbers2,int length);

int main ()
{
  int length = 4;
  int *numbers1 = new int [length];
  int *numbers2 = new int [length];
  
  // **************************  call the funtion and copy in a pointer the array input by user
  numbers1 = readNumbers(length);
  
  // **************************  call the funtion again to copy in a different pointer a new array input by user
  numbers2 = readNumbers(length);
  
  // **************************  call funtion to print dinamical array that * 2 numbers in every position of arrays input by user
  addArrays(numbers1, numbers2, length);
  
  // **************************  delete the pointers and the arrays after print
  delete [] numbers1;
  delete [] numbers2;
  
  return 0;
}