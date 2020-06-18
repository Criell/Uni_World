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

int *addArrays(int*numbers1,int*numbers2,int length)
{
  int *addArrays = new int [length];
  
  for (int i = 0; i < length; i++)
  {
    // **************************  add the two arrays
    addArrays[i] = numbers1[i] + numbers2[i];
  }
  
  // **************************  add the two arrays
  return addArrays;
}
