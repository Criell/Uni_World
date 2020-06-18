#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>

class Input
{
public:
	Input();
	std::string Taking_Input();
	std::vector<int> Int_Numbers(std::string input);
	std::string Symbols(std::string input);
	std::string Result_to_String(int final_res);
	void printOutput(std::vector<std::string> output);
	~Input();
};

#endif //INPUT_H
