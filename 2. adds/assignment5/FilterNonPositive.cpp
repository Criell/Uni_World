#include "FilterNonPositive.h"

FilterNonPositive::FilterNonPositive(){}

// Return true when the x is a positive int
bool FilterNonPositive::g(int x)
{
	if( x >= 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

FilterNonPositive::~FilterNonPositive(){}
