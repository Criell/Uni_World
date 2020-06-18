#include <iostream>
#include <stdlib.h>
int sumtwo(int array[], int secondarray[], int n)
{
  int sum = 0;
  
  if (n<0)
    return 0;
  
  for (int i=0;i<n;++i)
  {
    sum = sum + array[i] + secondarray[i];
    //std::cout << "sum : "<< sum << "\n";
    //std::cout << "secondarray[i]: " << secondarray[i] << "\n";
  }
  
  return sum;
}
