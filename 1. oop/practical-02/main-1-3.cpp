#include <iostream>
#include <stdlib.h>

extern int count_numbers(int array[4][4]);

int main()
{ 
    int n = 4;
    int array[4][4];
    //int number=0;
    
    for (int i=0; i<n; ++i)
    {
      //number = 0;
      
      for (int j=0; j<n; ++j)
      {
        //array [i][j]=number;
        
        if (i==j)
        {  
          array [i][j]=1;
        }
        else 
        {
          array [i][j]=0;  
        }
        
        //number = number+1;
      }
    }
    //std::cout << "The count of the numbers from 0 to 9 is: "<<"\n";
    count_numbers(array);
}
