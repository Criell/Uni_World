#include <iostream>
#include <stdlib.h>
#include <cmath>

int main()
  
{
  int n1 = 11;
  int count1=n1;
  int back1[n1];
 
  int n2 = 1;
  int count2=n2;
  int back2[n2];

  int binary1[] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1};
  int binary2[] = {1, 1};
  
  int back3[n1+n2];
  back3[0]=0;
  int count3=n1+n2;
  int binary3[n1+n2];
  
  for (int i=0; i<n1; ++i)
  {
     back1[i]= binary1[count1];
     count1=count1-1;
  }
  
  for (int i=0; i<n2; ++i)
  {
     back2[i]= binary2 [count2];
     count2=count2-1;
  }
 
 for (int i=0; i<n1 and i<n2; ++i) 
 {
   
   if (back1[i]==1 and back2[i]==1 and back3[i]==0)
   {
     back3[i]= 0;
     back3[i+1]=1;
   }
   else if (back1[i]==1 and back2[i]==1 and back3[i]==1)
   {
     back3[i]= 1;
     back3[i+1]=1;
   }   
   
   
   if (back1[i]==0 and back2[i]==1 and back3[i]==0)
   {
     back3[i]= 1;
   }
   else if (back1[i]==0 and back2[i]==1 and back3[i]==1)
   {
     back3[i]= 0;
     back3[i+1]=1;
   }
   
   
   if (back1[i]==1 and back2[i]==0 and back3[i]==0)
   {
     back3[i]= 1;
   }
   
   else if (back1[i]==0 and back2[i]==1 and back3[i]==1)
   {
     back3[i]= 0;
     back3[i+1]=1;
   }
   
   if (back1[i]==0 and back2[i]==0 and back3[i]==0)
   {
     back3[i]= 0;
   }
   else if (back1[i]==0 and back2[i]==0 and back3[i]==1)
   {
     back3[i]= 1;
   }
 }

 for (int i=0; i<n1 and i<n2; ++i)
 {
   binary3[i]= back3[count3];
   count3=count1-1;
 } 
}