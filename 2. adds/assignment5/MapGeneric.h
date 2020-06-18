#ifndef MAPGENERIC_H
#define MAPGENERIC_H

#include <iostream>
#include <stdlib.h>
#include <vector>

class MapGeneric
{
public:
	MapGeneric();
	std::vector<int> map(std::vector<int> Input_list);
	~MapGeneric();

private:
	virtual int f(int x) = 0;
	std::vector<int> recursive_help(std::vector<int> Input_list, int counter);
	std::vector <int> L;
};

#endif //MAPGENERIC_H
