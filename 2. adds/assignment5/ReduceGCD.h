#ifndef REDUCEGCD_H
#define REDUCEGCD_H

#include <iostream>
#include <stdlib.h>
#include "ReduceGeneric.h"

class ReduceGCD : public ReduceGeneric
{
public:
	ReduceGCD();
	~ReduceGCD();

private:
	int binaryOperator(int x, int y);
};

#endif //REDUCEGCD_H
