#include <iostream>
#include <stdlib.h>

#include "person.h"
#include "player.h"

using namespace std;

int Player::nextID = 1000;

Player::Player(string n, int sl, int *list, int m) : Person (n, "player",sl){
	personID = nextID;
	nextID++;
	number_games = m;

	int i,j;

	for (i = 0; i < number_games; i++){
		list_times[i] = list[i];
	}

	for (i = 0; i < number_games; i++){
		j=i;
		while ((j>0) && (list_times[j-1]>list_times[j])){
			int temp = list_times[j-1];
			list_times[j-1] = list_times[j];
			list_times[j] = temp;
			j=j-1;
		}
	}

}

int Player::searchGame(int x){

	for (int i = 0; i < number_games; i++){
		if (list_times[i] == x)
			return i;
		else
			return 0;
		
	}
}  

int Player::get_salary(){
	if (serviceLength <20)
		return salary;
	else 
		return salary*3;
}

Player::~Player(){}