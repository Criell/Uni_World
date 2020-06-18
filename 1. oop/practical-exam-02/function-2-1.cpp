#include <iostream>
#include <stdlib.h>

using namespace std; 

int *readNumbers(int n)
{
  int *readNumbers = new int [n];
  
  // **************************  fill array using pointer and input from terminal
  for (int i = 0; i < n; i++)
  {
    cin>> *(readNumbers+i);
  }
  
  // **************************  return pointer to array
  return readNumbers;
}

void dayNames (int *days, int length)
{
  string *names = new string [length]; 
  
  for (int i = 0; i < length; i++)
  {
    // **************************  store in array print i and value of array input using cin
    switch (days[i])
    {
      case 0: names[i] = "Mon"; break;
      case 1: names[i] = "Tue"; break;
      case 2: names[i] = "Wed"; break;
      case 3: names[i] = "Thu"; break;
      case 4: names[i] = "Fri"; break;
      case 5: names[i] = "Sat"; break;
      case 6: names[i] = "Sun"; break;
      default: names[i] = " "; break;
    }
  }
  
  for (int i = 0; i < length; i++)
  {
    // **************************  print i, days numbers input using cin and the name of the day
    cout<<i<<" "<<*(days+i)<<" "<<*(names+i)<<endl;
  }
}
