#include "Input.h"

	Input::Input(){}						
	
	// Ask for input. It isnt an integer, it will ignore it and store -1
	int Input::numbers(int n){
		
		std::cin >> n;

		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),' ');
			return n = -1;
		}
		
		else if (n < 0)
		{
			return n = -1;
		}

		return n;
	}
	
	//It will print Error if the value of the integer is -1.
	void Input::printNumbers(int n){

		if (n == -1)
		{
			std::cout << "ERROR";
		}
		else
		{
			std::cout << n;
		
		}
	}

	// Ask for input. It isnt an string, it will ignore it and store Error
	std::string Input::words(std::string s){

		std::cin >> s;
		
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),' ');
			return s = "ERROR";
		}

		return s;
	}

	Input::~Input(){}						