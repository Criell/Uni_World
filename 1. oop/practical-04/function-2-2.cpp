#include <iostream>
#include <stdlib.h>

using namespace std;

int maximum_sum(int *nums, int length)
{
  int sum = 0;
  int new_sum = 0;
  
  // *********************************** Check maximun sum of 5 elements	  
  
  for (int i = 0; i < length; ++i)
  {
    for (int j = i; j < length; ++j)
    {  
      for (int k = i; k <= j; ++k)
      {
        new_sum = new_sum + *(nums+k);
        //cout<<"new_sum: "<<new_sum<<endl;
      }    
      
      if (new_sum > sum )
      {
        sum = new_sum;
        //cout<<"sum: "<<sum<<endl;
      }
        
      new_sum = 0;
      
    }
  
  }	
  
  //cout<<"sum: "<<sum<<endl;
  return sum;
   
  
}