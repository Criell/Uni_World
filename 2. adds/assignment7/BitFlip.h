#ifndef BITFLIP_H
#define BITFLIP_H

#include <iostream>
#include <stdlib.h>
#include "Mutator.h"

class BitFlip : public Mutator
{
public:
	BitFlip();
	std::string mutate (Individual ADN, int k);
	~BitFlip();

};

#endif //BITFLIP_H
