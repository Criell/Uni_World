#include <iostream>
#include <stdlib.h>

using namespace std;


int min_integer(int integers[], int lenght)
{
  int min = integers[0];
  
  for (int i=1; i<lenght; ++i)
  {
    if (integers[i]<min)
    {
      min = integers[i];
    }
    
  }
  
  return min;
}

int max_integer(int integers[], int lenght)
{
  int max = integers[0];
  
  for (int i=1; i<lenght; ++i)
  {
    if (integers[i]>max)
    {
      max = integers[i];
      
    }
          
  }

  return max;
}

int sum_min_and_max(int integers[], int lenght)
{
  int sum = 0;
  
  sum = min_integer(integers, lenght) + max_integer(integers, lenght);
  
  return sum;
}
