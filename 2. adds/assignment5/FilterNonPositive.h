#ifndef FILTERNONPOSITIVE_H
#define FILTERNONPOSITIVE_H

#include <iostream>
#include <stdlib.h>
#include "FilterGeneric.h"

class FilterNonPositive : public FilterGeneric
{
public:
	FilterNonPositive();
	~FilterNonPositive();

private:
	bool g(int x);
};

#endif //FILTERNONPOSITIVE_H
