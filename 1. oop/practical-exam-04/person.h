#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Person
{
public:
	Person(string n, string o, int sl);
	string get_name();                         
	void set_name(string n);                       
	string get_occupation();                   
	void set_occupation(int o);                   
	virtual int get_salary() = 0;            // the salary of a person; takes only non-negative values		
	void set_salary(int s);                 
	int get_personID();     
	~Person();   

protected:
	static int ID;
	string name;                         
	string occupation;                   
	int salary;                          
	int serviceLength;                   
	int personID;                        
};

#endif //PERSON_H