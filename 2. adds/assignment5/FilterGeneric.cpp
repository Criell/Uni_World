#include "FilterGeneric.h"

FilterGeneric::FilterGeneric(){}

// return the L vector after called help function with the size of the input vector
std::vector<int> FilterGeneric::filter(std::vector<int> Input_list)
{
	int size = Input_list.size();
	return L = recursive_help (Input_list, size);
}

//call private function g with the every element of the Input_list vector(using recursion)
std::vector<int> FilterGeneric::recursive_help(std::vector<int> Input_list, int counter)
{
	if (counter == 0)
	{
		return L;
	}

	else
	{
		bool valid_element;
		valid_element = g(Input_list.at(Input_list.size() - counter));

		if (valid_element == true){
			L.push_back(Input_list.at(Input_list.size() - counter));
		}

		recursive_help(Input_list, counter-1);
	}

	return L;
}

FilterGeneric::~FilterGeneric(){}

