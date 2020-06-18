#ifndef FILTERGENERIC_H
#define FILTERGENERIC_H

#include <iostream>
#include <stdlib.h>
#include <vector>

class FilterGeneric
{
public:
	FilterGeneric();
	std::vector<int> filter(std::vector<int> Input_list);
	~FilterGeneric();

private:
	virtual bool g(int x)= 0;
	std::vector<int> recursive_help(std::vector<int> Input_list, int counter);
	std::vector <int> L;
};

#endif //FILTERGENERIC_H
