#include <iostream>
#include <stdlib.h>
#include <cmath>


void transform (int base, int number)

{
	int j = number;
	int digit=0;
	
  do
  { 
    j = j/base;
    digit = digit+1;
  } 
  while (j>1);
  
  int binary[digit];
  int n=0;
  
  std::cout<<"The binary number is: "<<"\n";
  
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
  std::cout<<" "<<"\n";  
}

int main()

{
  transform (2,73);  
}
