#include "Input.h"

Input::Input(){}

//Take the input list of symbols and numbers as a string
std::string Input::Taking_Input(){
	std::string input;
	std::getline(std::cin, input);
	return input;
}

//Return the operands as integers into a vector
std::vector<int> Input::Int_Numbers(std::string input){
	std::string temp;
	std::vector<int> int_temp;
	int tempint = 0;
	input = input + " ";
}

	for (int i = 0; i < (int)input.length(); i++){
		if (isdigit(input[i])){
			temp = temp + input[i];	
		}
		else if (input[i]==' '){
			std::stringstream intinput(temp);
			temp.clear();
			intinput >> tempint;
			int_temp.push_back(tempint);
		}
	}

	return int_temp;
}

//Change the integer into strings.
std::string Input::Result_to_String(int final_res){
	std::stringstream string_finalres;
	std::string temp;
	string_finalres << final_res;
	temp = string_finalres.str();
	return temp;
}

//Return the symbols as a string
std::string Input::Symbols(std::string input){
	std::string temp;

	for (int i = 0; i < (int)input.length(); i++){
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
			temp = temp + input[i];
		}
	}
	return temp;
}

//It will print the vector with the output.
void Input::printOutput(std::vector<std::string> output){
	for (int i = 0; i < (int)output.size(); i++){
		std::cout << output.at(i);
	}
	std::cout << std::endl;
}

Input::~Input(){}
