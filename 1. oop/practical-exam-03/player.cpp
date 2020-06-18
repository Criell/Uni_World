#include <iostream>
#include <stdlib.h>
#include <string>
#include "person.h"
#include "player.h"

using namespace std;

//Implementacion of the defauld constructor with the name, age, id and occupation player of the object player
Player::Player (string s, int n) 
	: Person(s, n, "Player") {
	
	num_games = 0;
}                                                       

//implementation of the funtion that take the array and store the value in the pointer
void Player::setGames(string *listOfGames, int n){
	num_games = n;
	game_names = listOfGames;

}

//Implementation of the funtion that print the array that was input in the method setGames (the previous funtion)
void Player::printInfo()
{	
	if (num_games > 0)
    {
		for (int i = 0; i < num_games; i++){
			cout << game_names[i] << endl; 
		}

		cout << num_games <<endl;
	}
	else
		cout << "No Game" <<endl;
}                            

//Implementacion of the destructor
Player::~Player(){}
