#include "ReduceGeneric.h"

ReduceGeneric::ReduceGeneric(){}

// return the L vector after called help function with the size of the input vector
std::vector<int> ReduceGeneric::reduce(std::vector<int> Input_list){

	L.push_back(binaryOperator(Input_list.at(0), Input_list.at(1)));
	int counter = Input_list.size()-2;
	return L = recursive_help (Input_list, counter);
}

/* call private function binaryOperator with the every element of the Input_list vector(using recursion) 
   and the previous value store in the L vector  */ 
std::vector<int> ReduceGeneric::recursive_help(std::vector<int> Input_list, int counter)
{
	if (counter == 0)
	{
		return L;
	}
	else
	{
		int x = Input_list.size() - counter;
		L.at(L.size()-1) = binaryOperator(Input_list.at(x), L.at(L.size()-1));
		recursive_help(Input_list, counter-1);
	}
	return L;
}

ReduceGeneric::~ReduceGeneric(){}

