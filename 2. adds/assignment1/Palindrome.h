#ifndef PALINDROME_H
#define PALINDROME_H

#include <iostream>
#include <stdlib.h>

#include <cstring>
#include <string>

using namespace std;

class Palindrome
{
public:
	Palindrome(string p);			// Declare - Constructor with parameter string.
	//Palindrome(char* p);			// Declare - Constructor with parameter char*
	void removeNonLetters();		// Declare - Funtion that remove non alphabetic symbols of variable Pali
	void lowercase(); 				// Declare - Funtion that make every character lowercase of variable Pali
	bool isPalindrome();			// Declare - Funtion that check if the variable Pali is a Palindrome 
	~Palindrome();					// Declare - Destructor 

private:
	string Pali;					// string variable that store the string input by user
	//char* Pali;					// char* variable that store the string input by user
	bool check;						// boolean variable that store true if pali is a palindrome or false if it isnot.
};

#endif //PALINDROME_H