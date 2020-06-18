#ifndef MAPABSOLUTEVALUE_H
#define MAPABSOLUTEVALUE_H

#include <iostream>
#include <stdlib.h>
#include "MapGeneric.h"

class MapAbsoluteValue : public MapGeneric
{
public:
	MapAbsoluteValue();
	~MapAbsoluteValue();

private:
	int f(int x);
};

#endif //MAPABSOLUTEVALUE_H
