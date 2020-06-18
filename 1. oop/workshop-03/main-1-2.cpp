#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

extern void print_class(string courses[], string students[], int report_card[][4], int nstudents);

int main ()
{
  int nstudents;
  
  cout<<"Please enter the number of students in the report card: ";
  cin>>nstudents;
  
  std::string courses[4];
  
  for (int i=0; i<4; ++i)
  {
    cout<<"Please enter the name of the subject " << i << ": ";
    cin>>courses[i];
  }
  
  std::string students[nstudents]; 
  
  int report_card[nstudents][4];
  
  for (int i=0; i<nstudents; ++i)
  {
    cout<<"Please enter the name of the student " << i << ": ";
    cin>>students[i];
    
    for (int j=0; j<4; ++j)
    {
      cout<<"Please enter the grade of " << courses[j] << ": ";
      cin>>report_card[i][j];
    }
  }
  
  print_class(courses, students, report_card, nstudents);
}
