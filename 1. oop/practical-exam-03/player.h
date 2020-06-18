#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include "person.h"

using namespace std;

//Declaration of subclass Player with the attributes of the superclass Person
class Player : public Person
{
	//Declaration of the behaviour of the subclass Player
	public:
		Player(string s, int n);                                                       
		void setGames(string *listOfGames, int n);   
		void printInfo();                            
		~Player();

	//Declaration of atributtes of the subclass Player
	private:
		int num_games;
		string* game_names;
};

#endif //PLAYER_H


