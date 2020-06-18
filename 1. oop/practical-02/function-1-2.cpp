#include <iostream>
#include <stdlib.h>

int identity(int array[10][10])

{
   int n=10;
   int positions=n*n;
   int sum = 0;
   
   //for (int i=0; i<n; ++i)
   //{
     //for (int j=0; j<n; ++j)
     //{
       //if (array[i][j]<10)
         //std::cout <<" ";
       
       //std::cout <<array[i][j];
       //std::cout <<"   ";
     //} 
     
     //std::cout <<"\n";
   //}
        
   int counter = 0;
   
   for (int i=0;i<n;++i)
   {
      for (int j=0; j<n; ++j)
      {
        if (i==j and array[i][j]==1)
          counter = counter +1;         
        
        if (i!=j and array[i][j]==0)
          counter = counter +1;
      }
      
   }
  
   if (counter==positions)
   {
        return 1;
   }
   else
   {  
      return 0;
   } 
}
