#include "Reverse.h"

Reverse::Reverse(){}					

int Reverse::reverseDigit(int value){

	//Check that negative numbers are not reverse
	if (value < 0)
	{
		return -1;
	}

	// Convert from int to string the parameter and store it in a stringstream.
	ls.clear();
	std::stringstream newstring;
	newstring << value ;
	ls = newstring.str();
	n = ls.length();

	//Call ReverseSwap with the length of the string and store it in a stringstream
	reverseSwap(n);
	std::stringstream newint(ls);

	// Convert from string to int and return
	newint >> value;
	return value;
}


std::string Reverse::reverseString(std::string letters){
	//Check the word "ERROR" is not reverse
	if (letters == "ERROR")
	{
		return letters;
	}

	//Call ReverseSwap with the length of the string.
	ls.clear();
	ls = letters;
	n = letters.length(); 	
	reverseSwap(n);
	return ls;
} 

int Reverse::reverseSwap(int n)
{
	//swap the “n” position and the (length – n) position of the string “ls”
	std::swap(ls[ls.length()- (n+1)],ls[n]);

	//while “n” if bigger than the middle of the length the function called itself.
	if (n > (int)ls.length()/2)
	{
		n = reverseSwap(n-1);
	}
	
	return n;
}

Reverse::~Reverse(){}
