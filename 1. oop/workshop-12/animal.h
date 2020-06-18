#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class animal
{
public:
	animal(string n, int v);       	
	int set_name(string n);
	int get_animalID() ;             
	int set_volume(int v);
	int get_volume();               
	static int ID;
	virtual string get_name()=0;
	~animal();

protected:
	string name;
	int volume;
	int animalID;
};

#endif //ANIMAL_H