#include "QuickSort.h"

QuickSort::QuickSort(){}

std::vector<int> QuickSort::Pivot(std::vector<int> List, int left, int right){

	int i = left;
	int j = right;
	int temp;
	int pivot = List.at(i+1);

	while (i <= j) {
		while (List.at(i) < pivot){
			i++;
		}

		while (List.at(j) > pivot){
			j--;
		}

		if (i <= j) {
			temp = List.at(i);
			List.at(i) = List.at(j);
			List.at(j) = temp;
			i++;
			j--;
		}
	}

	if (left < j){
		List=Pivot(List, left, j);
	}
	if (i < right){
		List=Pivot(List, i, right);
	}
	
	return List;
}

std::vector<int> QuickSort::Sorting(std::vector<int> List){
	int left = 0 ;
	int right = List.size()-1;
	List = Pivot(List, left, right);
	return List;
}
QuickSort::~QuickSort(){}

