#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>


void print_as_binary (std::string decimal_number)

{
    int number = atoi(decimal_number.c_str());
  	int j = number;
  	int digit=0;
  	int base = 2;
  	
  	do
    { 
      j = j/base;
      digit = digit+1;
    } 
    while (j>1);
    
    if (digit>1 and digit<9)
    {
  
      int binary[digit];
      int n=0;
    
      for (int i=digit; i>=0; i=i-1)  
    	{
        
        if (number/pow(base,i)>=1)
        {
          binary[n] = 1;
    	    std::cout<<binary[n];
    	    number=number-pow(base,i);
    	  }
    	  
    	  else
    	  {
    	    binary[n] = 0;
    	    std::cout<<binary[n];
    	  }
    	  n = n + 1;
    	}
 
    }
    std::cout<<"\n";
}



