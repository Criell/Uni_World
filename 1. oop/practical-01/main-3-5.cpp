#include <iostream>
#include <stdlib.h>

extern double sumeven(double*,int);

int main(int argc,char **argv)
{
  int n = argc-1;
  
  double array[n];
  
  for (int i=1; i<argc; ++i)
    
  {
    array[i-1] = atoi(argv[i]);      
  }  
  
  std::cout << "The sum of even positions is: " <<sumeven(array,n)<<"\n";
  
  return 0;
}
