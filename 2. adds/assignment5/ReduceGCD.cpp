#include "ReduceGCD.h"

ReduceGCD::ReduceGCD(){}

// Return the greatest common divisor of x and y
int ReduceGCD::binaryOperator(int x, int y)
{
	if( x == 0 )
	{
		return y;
	}
	return (binaryOperator(y%x , x));
}

ReduceGCD::~ReduceGCD(){}
