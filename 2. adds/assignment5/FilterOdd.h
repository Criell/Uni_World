#ifndef FILTERODD_H
#define FILTERODD_H

#include <iostream>
#include <stdlib.h>
#include "FilterGeneric.h"

class FilterOdd : public FilterGeneric
{
public:
	FilterOdd();
	~FilterOdd();

private:
	bool g(int x);
};

#endif //FILTERODD_H
