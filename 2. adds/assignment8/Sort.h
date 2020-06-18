#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <stdlib.h>
#include <vector>

class Sort
{
public:
	Sort();
	virtual std::vector<int> Sorting(std::vector<int> List) = 0; 
	~Sort();
protected:
	std::vector<int> SortList;
};

#endif //SORT_H
