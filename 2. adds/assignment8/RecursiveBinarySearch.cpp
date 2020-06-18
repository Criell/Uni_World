#include "RecursiveBinarySearch.h"

RecursiveBinarySearch::RecursiveBinarySearch(){}

bool RecursiveBinarySearch::binary_search (std::vector<int> Sort_List){

	int left = 0 ;
	int right = Sort_List.size();
	right = right-1;
	bool find_six = false;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		if(Sort_List.at(middle) == 6){
			return find_six = true;
		}

		else if (Sort_List.at(middle) < 6){
			left = middle + 1;
		}
		else if (Sort_List.at(middle) > 6){
			right = middle - 1;
		}
	}
	return  find_six;
}

RecursiveBinarySearch::~RecursiveBinarySearch(){}
