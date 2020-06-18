#include <iostream>
#include <stdlib.h>

bool is_a_palindrome(int integers[ ], int lengh)
{
  if (lengh <1)
  {
    return 0;
  }
  
  int middle=lengh/2;
  bool palindrome=0;
  
  for (int i=0; i<middle; i=i+1)
  {
    if (integers[i]==integers[lengh-i-1])
    {
      palindrome=1;
    }
    else
    {
      palindrome=0;
      return 0;
    }
 
  }
  
  return palindrome;
}

int sum_elements(int integers[ ], int lengh)
{
  if (lengh <1)
  {
    return 0;
  }
  
  int n=lengh;
  int sum = 0;

  for (int i=0; i<n; i=i+1)
  {
    sum = sum + integers[i];      
  }
  
  return sum;
}

int sum_if_a_palindrome (int integers[], int lengh)
{
  if (lengh <1)
  {
    return 0;
  }
  
  if (is_a_palindrome(integers, lengh)==0)
  {
    return -2;
  }  
  
  return sum_elements(integers, lengh);
  
}  

