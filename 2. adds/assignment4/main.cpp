#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <vector>
#include "Reverse.h"
#include "Fibonacci.h"
#include "EfficientFibonacci.h"
#include "Input.h"

int main()
{	

	Input i1;
	Reverse r1;
	Fibonacci f1;
	EfficientFibonacci ef1;

	
	//Call input functions numbers and words to validate type.
	//and then call the recursives functions of every object   
	int digits = 0;
	digits = i1.numbers(digits);
	digits = r1.reverseDigit(digits);

	std::string word;
	word = i1.words(word);
	word = r1.reverseString(word);

	int fiboNum = 0;
	fiboNum = i1.numbers(fiboNum);
	fiboNum = f1.Fibo(fiboNum);

	int fiboEfNum = 0;
	fiboEfNum = i1.numbers(fiboEfNum);
	fiboEfNum = ef1.Eff_Fibo(fiboEfNum);	

	// Prints results or when output dont match print ERROR. 
	i1.printNumbers(digits);
	std::cout << " ";

	std::cout << word << " ";
	
	i1.printNumbers(fiboNum);
	std::cout << " ";
	
	i1.printNumbers(fiboEfNum);
	std::cout << std::endl;

	return 0;
}
