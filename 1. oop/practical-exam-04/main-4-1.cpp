#include <iostream>
#include <stdlib.h>

#include "person.h"
#include "coach.h"
#include "player.h"
#include "sortperson.h"

using namespace std;

int main()
{
	string names[5] = {"Lina","Aurora", "Diana", "Nestor", "Jorge"};
	
	Person** people;

	for (int i = 0; i < 5; i++){
		people[i] = new Coach(names[i],3);
	}

	SortPerson::sort(people, 5);

	return 0;	
}