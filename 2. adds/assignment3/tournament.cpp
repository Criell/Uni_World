#include <iostream>
#include <string>
#include <cstdlib>
#include "human.h"
#include "computer.h"
#include "RandomComputer.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "PaperDoll.h"
#include "FistfullODollars.h"
#include "player.h"
#include "referee.h"
#include "tournament.h"

tournament::tournament(){}

void tournament::getInput(){

	//Request an input for the user and strore it in the string input
	for (int i = 0; i < 8; ++i){ std::cin >> input[i];}
	
	//created a pointer arrey of 8 computer players 
	// Using the string input as the name of the object.
	
	for (int i = 0; i < 8; i++){
		if (input[i] == "RandomComputer") {
			players[i] = new RandomComputer(input[i]); 
		}
		else if (input[i] == "Avalanche") {
			players[i] = new Avalanche(input[i]); 
		}
		else if (input[i] == "Bureaucrat") {
			players[i] = new Bureaucrat(input[i]); 
		}
		else if (input[i] == "Toolbox") {
			players[i] = new Toolbox(input[i]); 
		}
		else if (input[i] == "Crescendo") {
			players[i] = new Crescendo(input[i]); 
		}
		else if (input[i] == "PaperDoll") {
			players[i] = new PaperDoll(input[i]); 
		}
		else if (input[i] == "FistfullODollars") {
			players[i] = new FistfullODollars(input[i]); 
		}
	}	
}

void tournament::driver(referee r1) {

	//store the referee object.
	Ref = r1;

	// Match the 8 playes and store in winners the 4 semifinals 
	m = 0;

	for (int i = 1; i < 8; i=i+2){
		w1=0;
		w2=0;

		//Genere the plays R, P or S of every specific player 
		players[i-1]->MatchMoves();
		players[i]->MatchMoves();
		
		//Match the 8 players and return the string of Wins, Loses and Ties.
		play = Ref.getMatch(players[i-1], players[i]);
		
		//Compare the number of wins and store the 4 winners of the match.
		for(int j = 0; j < 5; j++){
			if (play[j]=='W'){w1 = w1+1;}
			else if(play[j]=='L'){w2 = w2+1;}
		}

		std::cout << play << "," << w1 << "- " << w2 << std::endl;

		if (w2 > w1){
			winners[m] = players[i];
			std::cout << players[i]->getName() << std::endl;
			std::cout << winners[m]->getName() << std::endl;
		}
		else {
			winners[m] = players[i-1];
			std::cout << winners[m]->getName() << std::endl;
		}	 

		m = m + 1;
	}

	// Match the 4 semifinals and store in semi the 2 finals
	m = 0;

	for (int i = 1; i < 4; i=i+2){	
		w1=0;
		w2=0;

		//Genere the plays R, P or S of every specific player
		winners[i-1]->MatchMoves();
		winners[i]->MatchMoves();
		
		//match the 4 winners and return the string of Wins, Loses and Ties.
		play = Ref.getMatch(winners[i-1], winners[i]);

		//Compare the number of wins and store the 2 winners of the match.
		for(int j = 0; j < 5; j++){
			if (play[j]=='W'){w1 = w1+1;}
			else if(play[j]=='L'){w2 = w2+1;}
		}

		std::cout << play << "," << w1 << "- " << w2 << std::endl;

		if (w2 > w1){
			semi[m] = winners[i];
			std::cout << semi[m]->getName() << std::endl;
		}
		else {
			semi[m] = winners[i-1];
			std::cout << semi[m]->getName() << std::endl;
		}	 
		m = m + 1;
	}

	// Match the 2 finals, store grand winner and print his name.
	w1=0;
	w2=0;
	
	//Genere the plays R, P or S of every specific player
	semi[0]->MatchMoves();
	semi[1]->MatchMoves();
	
	//match the 2 semifinales returning the string of Wins, Loses and Ties.
	play = Ref.getMatch(semi[0], semi[1]);
	
	//Compare the number of wins and store the winner of the match.
	for(int j = 0; j < 5; j++){
		if (play[j]=='W'){w1 = w1+1;}
		else if(play[j]=='L'){w2 = w2+1;}
	}

	std::cout << play << "," << w1 << "- " << w2 << std::endl;

	if (w2 > w1){
		final = semi[1];
		std::cout << final->getName() << std::endl;
	}
	else {
		final = semi[0];
		std::cout << final->getName() << std::endl;
	}	 

	//In this last version of the program this print the correct winner
	//Nevertheless, the system found the string "Avalanche". 
	//I couldnt figure it out why or from where this output is taken.
	output = final->getName();
	std::cout << output << std::endl;

}

tournament::~tournament(){}
