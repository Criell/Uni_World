#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>

#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main()
{	
	char type_sort;
	std::cin >> type_sort;

	std::string list;
	getline(std::cin, list);
	list = list + ' ';

	std::vector <int> Unsort_List;
	std::vector <int> Sort_List;

	std::string temp;

	for (int i = 0; i < (int)list.length(); i++){
		if (!isspace(list[i])){
			temp = temp + list[i];
		}
		else{
			std::stringstream buffer(temp);
			int number;
			buffer >> number;
			Unsort_List.push_back(number);
			temp.clear();
		}
	}
	
	Unsort_List.erase(Unsort_List.begin());

	if (type_sort == 'Q'){
		QuickSort sort_q;
		Sort_List = sort_q.Sorting(Unsort_List);
	}

	else if (type_sort == 'B'){
		BubbleSort sort_b;
		Sort_List = sort_b.Sorting(Unsort_List);
	}

	bool find_a_six = false;
	RecursiveBinarySearch six;

	find_a_six = six.binary_search (Sort_List);

	if (find_a_six){
		std::cout << "true" << " ";
	}
	else{
		std::cout << "false" << " ";
		}

	for (int i = 0; i < (int)Sort_List.size(); i++){
		std::cout << Sort_List.at(i) << " ";
	}

	std::cout << std::endl;

	return 0;
}
