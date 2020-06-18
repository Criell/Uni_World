#include <iostream>
#include <stdlib.h>

using namespace std;

extern int sum_min_and_max(int integers[], int lenght);
extern int max_integer(int integers[], int lenght);
extern int min_integer(int integers[], int lenght);

int main ()
{
  int lenght = 10;
  int integers[10];
  
  int n = 10;
  
  for (int i=0; i<10; ++i)
  {
    integers[i]= n*2;
    n=n+1;
    //cout<<integers[i]<<" "; 
  }  
  cout<<endl;
  
  //cout<<min_integer(integers, lenght)<<endl; 
  //cout<<max_integer(integers, lenght)<<endl;
  
  cout<<sum_min_and_max(integers, lenght)<<endl;
}