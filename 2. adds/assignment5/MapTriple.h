#ifndef MAPTRIPLE_H
#define MAPTRIPLE_H

#include <iostream>
#include <stdlib.h>
#include "MapGeneric.h"

class MapTriple : public MapGeneric
{
public:
	MapTriple();
	~MapTriple();

private:
	int f(int x);
};

#endif //MAPTRIPLE_H
