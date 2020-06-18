#include <iostream>
#include <stdlib.h>
#include <cmath>

int binary_to_number (int binary_digits[], int number_of_digits)

{
    int base = 2;
    int decimal=0;
  	
    if (number_of_digits>1 and number_of_digits<30)
    {
      int n=0;
      
      for (int i=number_of_digits-1; i>=0; i=i-1)  
      {
        
          if (binary_digits[n]==1)
	        {
	          decimal = decimal + pow(base,i);
	        }
          n = n+1;
    	}
     }
     return decimal;   
}
