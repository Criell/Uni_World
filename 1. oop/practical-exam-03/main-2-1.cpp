#include <iostream>
#include <stdlib.h>
#include <string>
#include "person.h"
#include "player.h"

using namespace std;

int main ()
{

	int n = 3;
	string games1 [3] = {"Syndey, 12 April 2013", "Brisbane, 10 March 2014", "Bogota, 5 March 2015"};

	Player p1("Lina", 30);
	Player p2("Eduardo", 32);

	p1.setGames(games1,n);
	p1.printInfo();

	p2.printInfo();
	
	
	return 0;
}