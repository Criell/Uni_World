#include <iostream>
#include <stdlib.h>

void count_numbers(int array[4][4])

{
   int n=4;
   int n0=0, n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0;
   
   for (int i=0;i<n;++i)
   {
     for (int j=0;j<n;++j)
     {
       if (array[i][j]==0)
          n0=n0+1; 
       else if (array[i][j]==1)
          n1=n1+1;
       else if (array[i][j]==2)
          n2=n2+1;
       else if (array[i][j]==3)
          n3=n3+1;
        else if (array[i][j]==4)
          n4=n4+1;
        else if (array[i][j]==5)
          n5=n5+1;
        else if (array[i][j]==6)
          n6=n6+1;
        else if (array[i][j]==7)
          n7=n7+1;
        else if (array[i][j]==8)
          n8=n8+1;
        else if (array[i][j]==9)
          n9=n9+1;
       }
     }
   
   //for (int i=0; i<n; ++i)
   //{
     //for (int j=0; j<n; ++j)
     //{
       //std::cout <<array[i][j];
       //std::cout <<"   ";
     //} 
     
     //std::cout <<"\n";
    //}
   
    std::cout <<"0"<<":"<<n0<<";";
    std::cout <<"1"<<":"<<n1<<";";
    std::cout <<"2"<<":"<<n2<<";";
    std::cout <<"3"<<":"<<n3<<";";
    std::cout <<"4"<<":"<<n4<<";";
    std::cout <<"5"<<":"<<n5<<";";
    std::cout <<"6"<<":"<<n6<<";";
    std::cout <<"7"<<":"<<n7<<";";
    std::cout <<"8"<<":"<<n8<<";";
    std::cout <<"9"<<":"<<n9<<";";
    std::cout <<"\n";
  }
