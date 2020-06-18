#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class animal
{
	public:
		animal(string aSpecies);
		string getSpecies();
		void setName(string aName); 
		string getName();
		int getID(); 
		~animal();
	
	private:
		string name;
		string species;
		int ID;
		static int uniqueID;
};

#endif // ANIMAL_H
