#include <iostream>
#include <stdlib.h>

#include "animal.h"
#include "hunter.h"
#include "vegie.h"
#include "sort_by_name.h"

using namespace std;

int main()
{	
	animal **animals;
	animals = new animal*[5];
	
	int n = 5;

	string name [5] = {"lina", "aurora", "nestor", "eduardo", "jorge"};

	for (int i=0; i <n; i++){
	     animals[i] = new hunter(name[i],20);
	} 

	sort_by_name::sort(animals,5);

	return 0;
}