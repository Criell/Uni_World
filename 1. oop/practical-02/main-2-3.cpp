#include <iostream>
#include <stdlib.h>

extern int sum_if_a_palindrome (int integers[], int lengh);
extern bool is_a_palindrome(int integers[], int lengh);
extern int sum_elements(int integers[], int lengh);

int main( )
{
  int integers[9]={1, 2, 3, 4, 5, 4, 3, 2, 1};
  int lengh = 9;
  
  std::cout<<sum_if_a_palindrome(integers, lengh)<<'\n';
   
  return 0;
}