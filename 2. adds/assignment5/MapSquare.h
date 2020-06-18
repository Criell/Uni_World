#ifndef MAPSQUARE_H
#define MAPSQUARE_H

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "MapGeneric.h"

class MapSquare : public MapGeneric
{
public:
	MapSquare();
	~MapSquare();

private:
	int f(int x);
};

#endif //MAPSQUARE_H
