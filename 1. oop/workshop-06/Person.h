#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

// Class definition for a Person
class Person
{
  std::string name;
  std::string job;  
public:

  Person();
	Person(std::string pname, std::string pjob);
	~Person();
	void print(){
	  std::cout<<name<<" "<<job<<std::endl;
	}
};
#endif //PERSON_H
