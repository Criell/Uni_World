#include <iostream>
#include <stdlib.h>

#include "animal.h"
#include "hunter.h"
#include "vegie.h"
#include "sort_by_name.h"

using namespace std;

void sort_by_name::sort(animal **animals,int n){

	int i,j;

	for (i = 0; i < n; i++){

		j = i;

		while ((j>0) && (animals[j-1]->get_name() > animals[j]->get_name())){
			animal* temp = animals[j-1];
			animals[j-1] = animals[j];
			animals[j] = temp;

			j= j-1;
		}
	}

	//for (i = 0; i < n; i++){
	//	cout << animals[i]->get_name() << endl;
	//}
}