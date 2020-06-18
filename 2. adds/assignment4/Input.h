#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <limits>

class Input
{
public:
	Input();
	int numbers(int n);
	void printNumbers(int n);
	std::string words(std::string s);
	~Input();					
};

#endif //INPUT_H
