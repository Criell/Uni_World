#include <iostream>
#include <stdlib.h>
#include <string>
#include "animal.h"
#include "hunter.h"

using namespace std;

int main ()
{
	hunter Ch("Cheetah");
	Ch.setName("Kitty");
	cout << Ch.getSpecies() << ", " << Ch.getName()<< ", " << Ch.getID()<<endl;

	//string *kills = new string[6];
	string kills[] = {"Mouse", "Gazelle", "Gazelle", "Hyena", "Rabbit", "Rabbit"};

	for (int i = 0; i < 6; i++)
	{
		Ch.recordKills(kills[i]);		
	}
	
	cout << Ch.numberOfKills() << endl;

	//delete [] kills;

	return 0;
}