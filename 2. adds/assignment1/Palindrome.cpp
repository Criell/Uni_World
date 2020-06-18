#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;


// Implement constructor with parameter string.	
	Palindrome::Palindrome(string p){
		Pali = p;
	}

//Implement constructor with parameter char*.
   /* Palindrome::Palindrome(char* p){
		Pali = p;
	}*/

// Implement the funtion that remove non alphabetic symbols of variable Pali
	void Palindrome::removeNonLetters(){

		int i = 0, j = 0; 

		//cout << Pali << Pali.length() << endl;    //testing when using string
		//cout << Pali << strlen(Pali) << endl;		//testing when using char*

	//copy back to the variable only the alphabetic characters (uppercase or lowercase) and reside the array of characters. 
		while (Pali[i] != '\0')
		{
			if (((Pali[i] < (char)123) & (Pali[i] > (char)96)) |  (((Pali[i] < (char)91) & (Pali[i] > (char)64))))
			{
				Pali[j] = Pali[i];
				j++;
			}	
			i++;
		}
		Pali[j] = '\0';								//add NULL character at the end of the new array of characters. 
		Pali.resize(j);								//change the size of string

	
	//use the isalpha funtion and erase the non alphabetic characters.
		/*while (Pali[i] != '\0'){
			if (!isalpha(Pali[i])){
				Pali.erase(Pali.begin()+i);
				i--;
			}
			i++;
		}*/


		//cout << Pali << Pali.length() << endl;   //testing when using string
		//cout << Pali << strlen(Pali) << endl;	   //testing when using char*
	}

// Implement the funtion that make every character lowercase of variable Pali
	void Palindrome::lowercase(){
		
		int i = 0; 

	//change to lowercase the uppercase letters of the array of characters.
		while (Pali[i] != '\0')
		{
			if ((Pali[i] < (char)91) & (Pali[i] > (char)64)) {
				Pali[i] = (char) (Pali[i] + 32);
			}
			else
			{
				Pali[i] = Pali[i]; 
			}
			
			i++;
		}
	//use the tolower function to lowercase the uppercase letters
		/*while (Pali[i] != '\0'){
			Pali[i] = tolower(Pali[i]);
			i++;
		}*/

		//cout << Pali << Pali.length() << endl;   //testing when using string
		//cout << Pali << strlen(Pali) << endl;	   //testing when using char*
	}

// Implement the funtion that check if the variable Pali is a Palindrome
	bool Palindrome::isPalindrome(){
		
		int n = Pali.length();				//Find the size when using string
		//int n =strlen(Pali);				//Find the size when using char*
		
		int j = n-1;

	// compare the first and the last elements of the array the characters, if the are the same return true, and check the second and the character before the last
		for(int i = 0; i < n/2; i++)
		{	
			check = false;

			if (Pali[i] == Pali[j]) {
				check = true;
				j--;
			}
			else 
				return check;
		}
		
		return check;
	}

// Implement destructor	
	Palindrome::~Palindrome(){}