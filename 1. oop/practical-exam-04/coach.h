#ifndef COACH_H
#define COACH_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Coach : public Person
{
public:
	Coach(string n, int sl);
    int get_salary();
    ~Coach();

private:
	static int nextID;
	            
};


#endif //COACH
