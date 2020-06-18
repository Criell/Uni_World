#include <iostream>
#include <stdlib.h>

int diagonal(int array[4][4])

{
   int n=4;
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
        
   
   for (int i=0;i<n;++i)
   {
      sum = sum + array[i][i];      
   }
 
   return sum;
}
