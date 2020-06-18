#ifndef REVERSE_H
#define REVERSE_H

#include <iostream>
#include <string>
#include <sstream>

class Reverse
{
public:
	Reverse();						
	int reverseDigit(int value);
	std::string reverseString(std::string letters); 
	int reverseSwap(int n);
	~Reverse();						

private:
	int dig;	
	std::string ls;
	int n; 
};

#endif //REVERSE_H
