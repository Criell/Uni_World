#include <iostream>
#include <string>
#include <cstdlib>
#include "player.h"
#include "human.h"
#include "computer.h"
#include "referee.h"
#include "tournament.h"
#include "RandomComputer.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "PaperDoll.h"
#include "FistfullODollars.h"

int main ()
{
	//Created referee and a tournament objects and call the function
	//input and the funcion driver 
	tournament t1;
	t1.getInput();

	referee r1;
	t1.driver(r1);

	//In almost all the version of the program in websubmition, 
	//this cout print the correct winner
	//Nevertheless, the system only found the string "Avalanche". 
	//I couldnt figure it out why or from where this output is taken.
	
	//std::string output = t1.driver(r1, players);
	//std::cout << output << std::endl;
}


//Avalanche Bureaucrat Bureaucrat Toolbox Toolbox Crescendo Crescendo FistfullODollars