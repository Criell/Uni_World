#include <iostream>
#include <stdlib.h>

using namespace std;

extern void printer(int array[10][10]);

int main ()
{
  
  int array[10][10];
  
  for (int i=0; i<10; ++i)
  {
    for (int j=0; j<10; ++j)
    {
      //cout<<"Please enter the name of number " << i << ": ";
      cin>>array[i][j];
    }
  }
  
  printer(array);
}
