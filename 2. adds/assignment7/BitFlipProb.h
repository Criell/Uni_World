#ifndef BITFLIPPROB_H
#define BITFLIPPROB_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Mutator.h"

class BitFlipProb : public Mutator
{
public:
	BitFlipProb();
	std::string mutate (Individual ADN, int k);
	~BitFlipProb();

private:
	double p;

};

#endif //BITFLIPPROB_H
