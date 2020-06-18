#include <iostream>
#include <stdlib.h>

extern int sum_min_and_max(int [], int);
extern int max_integer(int [], int);
extern int min_integer(int [], int);

int main()
{ 
  int length=4;
  int integers[4]={1, 2, 3, 4};
  
  std::cout<<sum_min_and_max(integers, length)<<"\n";
 
  return 0;
}