#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <stdlib.h>
#include "person.h"
#include "player.h"
#include "coach.h"

using namespace std;

//Declaration of superclass Team that use composition with the superclass Person
class Team
{
	//Declaration of the behaviour of the superclass Team
	public:
		Team(Person **staff, int n);   
		void printTeamStaff();
		~Team();

	//Declaration of atributtes of the superclass Team
	private:
		int lenght;
		int **Personal;
};

#endif //TEAM_H

