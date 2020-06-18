#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Sort.h"

class BubbleSort : public Sort
{
public:
	BubbleSort();
	std::vector<int> Sorting(std::vector<int> List);
	~BubbleSort();
};

#endif //BUBBLESORT_H
