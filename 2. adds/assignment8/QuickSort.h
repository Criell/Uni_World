#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Sort.h"

class QuickSort : public Sort
{
public:
	QuickSort();
	std::vector<int> Pivot(std::vector<int> List, int left, int right);
	std::vector<int> Sorting(std::vector<int> List);
	~QuickSort();

};

#endif //QUICKSORT_H
