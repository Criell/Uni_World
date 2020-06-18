#include "BubbleSort.h"

BubbleSort::BubbleSort(){}

std::vector<int> BubbleSort::Sorting(std::vector<int> List){ 

	for(int i = 1; i < (int)List.size(); i++){
		for(int j = 0; j < (int)List.size()-i; j++){
			if(List.at(j) > List.at(j+1)){
				int temp = List.at(j);
	            List.at(j) = List.at(j+1);
	            List.at(j+1) = temp;
	        }
	    }
	}
	return List;
}

BubbleSort::~BubbleSort(){}
