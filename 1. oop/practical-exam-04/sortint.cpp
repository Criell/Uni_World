#include <iostream>
#include <stdlib.h>

#include "person.h"
#include "sortint.h"

using namespace std;

void SortInt::sort (int *numbers, int n) {
	int i, j;
	for (i = 0; i < n; i++){
		j=i;
		while ((j>0) && (numbers[j-1]>numbers[j])){
			int temp = numbers[j-1];
			numbers[j-1] = numbers[j];
			numbers[j] = temp;
			j=j-1;
		}
	}
}