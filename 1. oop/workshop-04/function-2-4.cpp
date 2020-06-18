#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

using namespace std;

float add_op(float left, float right)
{
  float sum = left + right;
  return sum;
}

float subtract_op(float left, float right)
{
  float sub = left - right;
  return sub;
}

float multiply_op(float left, float right)
{
  
  float multi = left * right;
  return multi;
  
}

float arithmetic_ops(float left, float right, float (*op)(float,float))
{
  
  return op(left,right);

}
