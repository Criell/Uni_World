#ifndef INFIX_H
#define INFIX_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

#include "myQueue.h"
#include "myStack.h"
#include "Input.h"

class Infix
{
public:
	Infix();
	int Result(std::string sign, int a, int b);
	std::string Result_to_String(int res);
	void Prefix_to_Infix();
	~Infix();

private:
	std::vector<std::string> output;
	std::string Str_Infix;
	std::vector<int> Infix_Numbers;
	std::string Str_Symbols;
};

#endif //INFIX_H
