#include <iostream>
#include <string>
#include "player.h"
#include "human.h"

human::human(std::string t) : player(t){}
	
void human::getInput(){

	//cout << "Write the number of matches and the moves" << endl; 
	//cout << "Only use (R=Rock S=Scissors P=Paper) separated by spaces" << endl;
	
	int numbers;
	std::cin >> numbers;
	getline(std::cin,plays);
	
	/*if ((plays[0] <= (char)57) & (plays[0] >= (char)48)) 
	{
		char* num = &plays[0];
		matches = (atoi(num)*2)-1;
	}
	else {matches = -1;}*/
	
	matches = (numbers*2)-1;

	plays.erase(0,1);

	int n = plays.length();

	for (int i = 0; i < n; i++){
		if (plays[i] == 'p') {plays[i] = 'P';}
		if (plays[i] == 's') {plays[i] = 'S';}
		if (plays[i] == 'r') {plays[i] = 'R';}
	}

	for (int i = 1; i < n; i=i+2)
	{
		if (plays[i] != ' ') {matches = -1;}
		if ((plays[i+1] != 'P') & (plays[i+1] != 'S') & (plays[i+1] != 'R'))
		{matches = -1;}
	}
	
	if (n == matches){moves = plays;};

}

human::~human(){}

	
