#include <iostream>

#include <stdlib.h>

extern int count(int*,int,int);

int main(int argc,char **argv)

{
    int n = argc - 2;
    int num = atoi(argv[1]);
    
    int array[n];
    
    for (int i=2; i<argc; ++i)
      
    {
      array[i-2] = atoi(argv[i]);      
    }  
    
    std::cout << "The count is: " << count(array,n,num)<<"\n";
    return 0 ;
}

