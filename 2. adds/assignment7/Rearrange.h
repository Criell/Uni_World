#ifndef REARRANGE_H
#define REARRANGE_H

#include <iostream>
#include <stdlib.h>
#include "Mutator.h"

class Rearrange : public Mutator
{
public:
	Rearrange();
	std::string mutate (Individual ADN, int k);
	~Rearrange();
};

#endif //REARRANGE_H
