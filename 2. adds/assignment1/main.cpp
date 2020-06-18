#include <iostream>
#include <string>

#include "Palindrome.h"

using namespace std;

int main()
{	

//Store the input with string
	string phrase;
	//cout << "Input: ";
	getline(cin, phrase);

//Store the input with char*
	/*char phrase[50];
	//cout << "Input: ";
	cin.getline(phrase,50);*/

	Palindrome Pali(phrase); //Create a palindrome object.
	
	Pali.removeNonLetters(); //Call palindrome funtion of Pali obj to remove non alphabetic symbols
	Pali.lowercase();		 //Call palindrome funtion of Pali obj to make every character lowercase


//Print yes if it is a palindrome or print no if is not a Palindrome. 
	if (Pali.isPalindrome() == true){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	
	return 0;
}