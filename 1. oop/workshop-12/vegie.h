#ifndef VEGIE_H
#define VEGIE_H

#include <iostream>
#include <stdlib.h>

#include "animal.h"

using namespace std;

class vegie : public animal
{
public:	
	vegie(string n, int v);  
	void set_favourite_food(string f);
	string get_favourite_food();
	string get_name();
	~vegie();
	
private:
	string favourite_food;              
	static int nextID;
};

#endif //VEGIE_H