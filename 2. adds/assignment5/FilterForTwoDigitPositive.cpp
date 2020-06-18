#include "FilterForTwoDigitPositive.h"

FilterForTwoDigitPositive::FilterForTwoDigitPositive(){}

// Return true when the x is a 2digits int
bool FilterForTwoDigitPositive::g(int x)
{
	if( x >= 10 && x <= 99)
	{
		return true;
	}
	else
	{
		return false;
	}
}

FilterForTwoDigitPositive::~FilterForTwoDigitPositive(){}

