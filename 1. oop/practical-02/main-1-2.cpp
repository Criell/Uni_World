#include <iostream>
#include <stdlib.h>

extern int identity(int array[10][10]);

int main()
{ 
    int array[10][10];
    int n = 10;
    //int number=0;
  
    for (int i=0; i<n; ++i)
    {
      for (int j=0; j<n; ++j)
      {
        //number = number+1;
        //array [i][j]=number;
        if (i==j)
        {  
          array [i][j]=1;
        }
        else 
        {
          array [i][j]=0;  
        }
      }
    }
    
    if  (identity(array)==1)
       std::cout << "The array is an identity matrix"<<"\n";
    
    return 0;
}
