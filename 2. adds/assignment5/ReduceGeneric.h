#ifndef REDUCEGENERIC_H
#define REDUCEGENERIC_H

#include <iostream>
#include <stdlib.h>
#include <vector>

class ReduceGeneric
{
public:
	ReduceGeneric();
	std::vector<int> reduce(std::vector<int> Input_list);
	~ReduceGeneric();

private:
	virtual int binaryOperator(int x, int y)= 0;
	std::vector<int> recursive_help(std::vector<int> Input_list, int counter);
	std::vector <int> L;
};

#endif //REDUCEGENERIC_H
