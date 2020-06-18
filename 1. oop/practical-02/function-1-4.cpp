#include <iostream>
#include <stdlib.h>

void print_scaled_matrix(int array[3][3], int scale)

{
   int scale_array [3][3];
   
   for (int i=0;i<3;++i)
   {
     for (int j=0;j<3;++j)
     {
       scale_array[i][j] = array[i][j] * scale;      
       std::cout <<scale_array[i][j];
       if (j<2)
         std::cout <<" ";
      }
   
      std::cout <<"\n";
   }
   
}
