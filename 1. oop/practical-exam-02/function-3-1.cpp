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

bool sortedArray(int *numbers, int length)
{
  bool sortedArray = 0;
  int min = 0;
  int max = 0;
  
  if (length<1)
  {
    return sortedArray;  
  }
  
  for (int i = 1; i < length; i++)
  {
    if (numbers[i]<numbers[i+1])
    {
      min = min + 1;
    }
    else if (numbers[i]>numbers[i+1])
    {
      max = max + 1;
    }
  }
  
  if (min == length)
  {
    sortedArray = 1;
  }
  else if (min == length)
  {
    sortedArray = 1;
  }
  else
  {
    sortedArray = 0;
  }
  
  return sortedArray;  
}