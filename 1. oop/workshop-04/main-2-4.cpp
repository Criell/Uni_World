#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

using namespace std;

extern float add_op(float left, float right); 
extern float subtract_op(float left, float right);
extern float multiply_op(float left, float right);
extern float arithmetic_ops(float left, float right, float (*op)(float,float));

int main()
  
{
  float left = 12.2;
  float right = 5.2;
  char operation; 
  
  cout<<"What operation do you want to do (+ or + or *)?";
  cin>>operation;
  
  if (operation == '+')
    cout<<arithmetic_ops(left, right, &add_op)<<endl;
  else if (operation == '-')
    cout<<arithmetic_ops(left, right, &subtract_op)<<endl;
  else if (operation == '*')
    cout<<arithmetic_ops(left, right, &multiply_op)<<endl;
}