#include <iostream>
#include <stdlib.h>

using namespace std;

extern void printer (int array[10][10]);

int main ()
{
  int array[10][10];
  
  int n = 0;
  
  for (int i=0; i<10; ++i)
  {
    for (int j=0; j<10; ++j)
     {
       array[i][j] = n+1;
       n=n+1;
     }
  }  
  printer (array);
}