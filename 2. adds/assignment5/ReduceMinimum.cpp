#include "ReduceMinimum.h"

ReduceMinimum::ReduceMinimum(){}

// Return the minimum value between x and y ints
int ReduceMinimum::binaryOperator(int x, int y)
{
	if( x >= y )
	{
		return y;
	}
	else
	{
		return x;
	}
}

ReduceMinimum::~ReduceMinimum(){}
