#include <iostream>
#include <stdlib.h>

using namespace std;

extern void copy_2d_strings(string first[][2], string second[][2], int n);

int main ()
{
  int n;
  string first[n][2];     
  
  cout<<"Please write the size of the arrays first dimension: ";
  cin>>n;
  
  for (int i = 0; i<n; i++)
  {
      for (int j = 0; j<2; j++)
      {
          cout<<"Character of the array in "<<"ROW-"<<j<<" COL-"<<i<<":";
          cin>>first[i][j];
      }
  }
  
  
	//= {{"h","e"},{"l","l"},{"o","w"}}; 
	string second[n][2];
	
	
	copy_2d_strings(first, second, n);

}