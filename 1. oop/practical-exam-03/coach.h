#ifndef COACH_H
#define COACH_H

#include <iostream>
#include <stdlib.h>
#include "person.h"

using namespace std;


//Declaration of  the subclass Coach with the attributes of the superclass Person 
class Coach : public Person
{
	//Declaration of the behaviour of the subclass Coach
	public:
		Coach(string s, int n);	                       
		Coach(string s, int n, string *exTeams, int m);                                                                         
		void printExTeams();                           
		void swapTeams(int index1, int index2); 
		~Coach();      
                
     //Declaration of atributtes of the subclass Coach                                         
	private:
		string *PastTeams;
		int numer_tems;
		int position_1;
		int position_2;
};

#endif //COACH_H

