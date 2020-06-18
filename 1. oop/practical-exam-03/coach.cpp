#include <iostream>
#include <stdlib.h>
#include <string>
#include "person.h"
#include "coach.h"

using namespace std;

//Implementacion of the defauld constructor with the name, age, id and occupation coach of the object coach
Coach::Coach(string s, int n) 
	: Person(s, n, "Coach") {
}

//Implementacion of the constructor with the name, age, id and occupation coach of the object coach
//add the array of past teams and the lenght of the array en m.
Coach::Coach(string s, int n, string *exTeams, int m) 
	: Person (s, n, "Coach") {

		numer_tems = m;
		PastTeams = exTeams;
}

//Implementation of the funtion that print the array that was input in the constructor
void Coach::printExTeams(){

	for (int i = 0; i < numer_tems; i++){
		
		cout << PastTeams[i] << endl;
	}
}

//Implementation of the funtion that print the array that was input in the constructor
void Coach::swapTeams(int index1, int index2){
	 position_1 = index1;
	 position_2 = index2;

	 string temp = PastTeams[position_1];
 	 PastTeams[position_1] = PastTeams[position_2];
	 PastTeams[position_2]= temp;                                   		
}

//Implementacion of the destructor
Coach::~Coach(){}

