#include "MapGeneric.h"

MapGeneric::MapGeneric(){}

// return the L vector after called help function with the size of the input vector
std::vector<int> MapGeneric::map(std::vector<int> Input_list)
{
	int counter = Input_list.size();
	return L = recursive_help (Input_list, counter);
}

// call private function f with the every element of the Input_list vector(using recursion)
std::vector<int> MapGeneric::recursive_help(std::vector<int> Input_list, int counter)
{
	if (counter == 0)
	{
		return L;
	}

	else
	{
		int element;
		element = f(Input_list.at(Input_list.size() - counter));
		L.push_back(element);
		recursive_help(Input_list, counter-1);
	}

	return L;
}

MapGeneric::~MapGeneric(){}
