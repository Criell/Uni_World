#include <iostream>
#include <stdlib.h>

#include "person.h"
#include "coach.h"
#include "player.h"
#include "sortperson.h"

using namespace std;

void SortPerson::sort (Person **people, int n) {
	int i, j;
	for (i = 0; i < n; i++){
		j=i;
		while ((j>0) && (people[j-1]->get_personID() >people[j]->get_personID())){
			Person *temp = people[j-1];
			people[j-1] = people[j];
			people[j] = temp;
			j=j-1;
		}
	}

	for (int i = 0; i < n; i++){
		cout << people[i] <<endl;
	}
}