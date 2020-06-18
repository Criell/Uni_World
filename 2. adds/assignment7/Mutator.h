#ifndef MUTATOR_H
#define MUTATOR_H

#include <iostream>
#include <stdlib.h>

#include "Individual.h"

class Mutator
{
public:
	Mutator();
	virtual std::string mutate (Individual ADN, int k) = 0;
	int circles (int k, int l);
	~Mutator();
};

#endif //MUTATOR_H
