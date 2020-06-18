#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void print_class(string courses[], string students[], int report_card[][4], int nstudents)

{
  cout<<"Report Card ";
  
  for (int i=0; i<4; ++i)
  {
    cout<<courses[i];

    if (i<3)
      cout <<" "; 
    
    
  }
  
  cout<<"\n";
  
  for (int i=0; i<nstudents; ++i)
  {
    cout<<students[i]<<" ";
      
    
    for (int j=0; j<4; ++j)
    {
      cout<<report_card[i][j]; 
      
      if (j<3)
        cout <<" ";
    }
    
    cout<<"\n";
  }
  
}