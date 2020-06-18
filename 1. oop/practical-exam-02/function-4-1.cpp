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

void printSubArrays(int *numbers, int length)
{
  int sum = 0;
  int new_sum = 0;
  
  for (int i = 0; i < length; i++)
  {
    for (int j = i; j < length; j++)
    {
      for (int k = i; k <= j; i++)
      {
        new_sum = new_sum + numbers[i];
      
        
      }
    }
  }
}