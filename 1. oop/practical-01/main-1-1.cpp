#include <iostream>

#include <stdlib.h>

extern int sum_array(int array[], int n);

int main(int argc,char **argv)
{ 
    int n = argc-1;

    int array[n];
  
    for (int i=1; i<argc; ++i)
  
    {
      array[i-1] = atoi(argv[i]);      
    }  
       
    std::cout << "The sum is: " <<sum_array(array,n)<<"\n";
    
    return 0;
}
