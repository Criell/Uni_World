#include <iostream>
#include <stdlib.h>
#include <new>

using namespace std;

int size_of_variable_star_arr()
{
	int *arr = new int[3];
	int address_arr0 = sizeof(arr);
	
	delete [] arr;
	
	//cout<<*arr<<endl;
	//cout<<arr<<endl;

	return address_arr0;
}