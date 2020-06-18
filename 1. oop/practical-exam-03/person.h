#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <stdlib.h>

using namespace std;

//Declaration of the superclass Person
class Person
{
	//Declaration of the behaviour of the superclass Person
	public:
		Person(string s, int n, string p);
		void setName(string s);               
		string getName();                     
		void setAge(int n);                  
		int getAge();                        
		int getPersonID();                    
		string getOccupation();
		~Person();

	//Declaration of of the superclass Person
	private:
		string name;
		int age;
		string occupation;
		static int ID;
		int person_id;
};

#endif //PERSON_H


