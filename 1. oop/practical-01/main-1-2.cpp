#include <iostream>

#include <stdlib.h>

extern double average(int*,int);

int main(int argc,char **argv)
{
    int n = argc-1;
  
    int array[n];
  
    for (int i=1; i<argc; ++i)
    
    {
      array[i-1] = atoi(argv[i]);      
    }  
  
    std::cout << "The average is: " <<average(array,n)<<"\n";
	
	  return 0 ;
}

