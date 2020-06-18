#ifndef REDUCEMINIMUM_H
#define REDUCEMINIMUM_H

#include <iostream>
#include <stdlib.h>
#include "ReduceGeneric.h"

class ReduceMinimum : public ReduceGeneric
{
public:
	ReduceMinimum();
	~ReduceMinimum();

private:
	int binaryOperator(int x, int y);
};

#endif //REDUCEMINIMUM_H
