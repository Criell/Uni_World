#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

using namespace std;

float add_op(float left, float right)
{
  float sum;
  sum = left + right;
  
  return sum;
}
  
float subtract_op(float left, float right)
{
  float sub;
  sub = left - right;
  
  return sub;
}
  
float arithmetic_ops(float left, float right, std::string op)
{
  
  float arit; 
  
  if (op=="+")
  {
    arit = add_op(left, right);
    
  }
  
  else if (op=="-")
  {
    arit = subtract_op(left, right);
  }
  
  return arit;
}
  