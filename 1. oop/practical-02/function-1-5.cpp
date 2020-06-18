#include <iostream>
#include <stdlib.h>

void print_summed_matrices(int array1[3][3], int array2[3][3])

{
   int sum_array[3][3];
   
   for (int i=0; i<3; ++i)
   {
     for (int j=0; j<3; ++j)
     {  
        sum_array[i][j] = array1[i][j] + array2[i][j];
     }   
   }
   
   for (int i=0; i<3; ++i)
   {
     for (int j=0; j<3; ++j)
     {
       std::cout <<sum_array[i][j];
       if (j<2)
         std::cout <<" ";
     } 
     
     std::cout <<"\n";
   }
}

