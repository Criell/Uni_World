#include <iostream>
#include <stdlib.h>
#include <new>

using namespace std;

int size_of_variable_star_t()
{
	int a, *p;
	p = &a;
	int *t = new int;
	a = sizeof(t);

	return a;
}
