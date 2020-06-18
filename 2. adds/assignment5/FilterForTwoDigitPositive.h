#ifndef FILTERFORTWODIGITPOSITIVE_H
#define FILTERFORTWODIGITPOSITIVE_H

#include <iostream>
#include <stdlib.h>
#include "FilterGeneric.h"

class FilterForTwoDigitPositive : public FilterGeneric
{
public:
	FilterForTwoDigitPositive();
	~FilterForTwoDigitPositive();

private:
	bool g(int x);
};

#endif //FILTERFORTWODIGITPOSITIVE_H
