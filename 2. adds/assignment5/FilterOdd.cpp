#include "FilterOdd.h"

FilterOdd::FilterOdd(){}

// Return true when the x is an odd int
bool FilterOdd::g(int x)
{
	if( (x % 2) != 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

FilterOdd::~FilterOdd(){}
