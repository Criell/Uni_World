#include <iostream>
#include <stdlib.h>

using namespace std; 

int *readNumbers(int n)
{
  int *readNumbers = new int [n];
  
  // **************************  fill array using pointer and input from terminal
  for (int i = 0; i < n; i++)
  {
    cin>> *(readNumbers+i);
  }
  
  // **************************  return pointer to array
  return readNumbers;
}

void printNumbers(int *numbers, int length)
{
  for (int i = 0; i < length; i++)
  {
    // **************************  print i and value of array input using cin
    cout<<i<<" "<<*(numbers+i)<<endl;
  }
}