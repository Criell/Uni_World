#include <iostream>
#include <stdlib.h>

extern int sumtwo(int*,int*,int);

int main(int argc,char **argv)
{
	int n = (argc-1)/2;
  
  int array[n];
  
  int secondarray[n];
  
  for (int i=0, j=n; i<n; ++i, ++j)
    
  {
    array[i] = atoi(argv[i+1]);
    secondarray[i] = atoi(argv[j]);
  }  
  
  std::cout << "The sum is: " <<sumtwo(array,secondarray,n)<< std::endl;
  
  return 0;
}
