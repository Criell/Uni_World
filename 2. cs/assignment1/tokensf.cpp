// a skeleton of the tokensf class implementation

#include "tokensf.h"
#include <iostream>
#include <ctype.h>

// to shorten the code
using namespace std ;

////////////////////////////////////////////////////////////////////////

// the following global pointer and functions exist to keep the tokensf class
// and its implementation completely hidden from the main function

// pointer to tokeniser object
static tokensf *tokeniser ;

// create and initialise the tokensier - must be called first and exactly once
void init_tokeniser()
{
    tokeniser = new tokensf() ;
}

// next token - calls matching function in tokeniser object
// init_tokeniser() must have been previously called
string next_token()
{
    return tokeniser->next_token() ;
}

// token value - calls matching function in tokeniser object
// init_tokeniser() must have been previously called
string token_value()
{
    return tokeniser->token_value() ;
}


////////////////////////////////////////////////////////////////////////

// the following externally defined function must be used for all input
extern int read_char() ;

// the following externally defined function must be used to lookup keywords
// it returns "" if the string passed in is not a keyword
string lookup_keyword(string) ;


////////////////////////////////////////////////////////////////////////

// the following are the implementations of the tokensf class functions

// construct and initialise a tokensf tokeniser
tokensf::tokensf()
{
    // token value initially ""
    value = "" ;

     StopMistake = true;

    // read first character to initialise the tokeniser
    ch = read_char() ;
}

// read next character in the input and record in instance variable ch
void tokensf::nextch()
{
    ch = read_char() ;
}

// return the current token value
string tokensf::token_value()
{
    return value ;
}

// Helper functions can go here - these can simplify writing next_token()
// Some useful builtin helper functions include, isalpha(), isdigit(), isalnum(), etc.

//return true when the parameter is alpha character
bool findLetter (int letter)
{
    bool check = false;
    switch(letter)
    {
        case 'A': check = true; break;
        case 'B': check = true; break;
        case 'C': check = true; break;
        case 'D': check = true; break;
        case 'E': check = true; break;
        case 'F': check = true; break;
        case 'G': check = true; break;
        case 'H': check = true; break;
        case 'I': check = true; break;
        case 'J': check = true; break;
        case 'K': check = true; break;
        case 'L': check = true; break;
        case 'M': check = true; break;
        case 'N': check = true; break;
        case 'O': check = true; break;
        case 'P': check = true; break;
        case 'Q': check = true; break;
        case 'R': check = true; break;
        case 'S': check = true; break;
        case 'T': check = true; break;
        case 'U': check = true; break;
        case 'V': check = true; break;
        case 'W': check = true; break;
        case 'X': check = true; break;
        case 'Y': check = true; break;
        case 'Z': check = true; break;
        case '_': check = true; break;
        case 'a': check = true; break;
        case 'b': check = true; break;
        case 'c': check = true; break;
        case 'd': check = true; break;
        case 'e': check = true; break;
        case 'f': check = true; break;
        case 'g': check = true; break;
        case 'h': check = true; break;
        case 'i': check = true; break;
        case 'j': check = true; break;
        case 'k': check = true; break;
        case 'l': check = true; break;
        case 'm': check = true; break;
        case 'n': check = true; break;
        case 'o': check = true; break;
        case 'p': check = true; break;
        case 'q': check = true; break;
        case 'r': check = true; break;
        case 's': check = true; break;
        case 't': check = true; break;
        case 'u': check = true; break;
        case 'v': check = true; break;
        case 'w': check = true; break;
        case 'x': check = true; break;
        case 'y': check = true; break;
        case 'z': check = true; break;
    }
    return check;
}

//return true when function lookup_keyword indicated that parameter is a keyword
bool findKey(string n)
{
    bool check = false;
    string key;
    key = lookup_keyword(n);

    if (key != ""){ check = true;}
    return check;
}

//return true when the parameter is a number (0-9)
bool findDigit (int n)
{
    bool check = false;
    if (n == '.') {check=true;}
    return check;
}

//return true when the parameter is alpha character
bool findPun(int n)
{
    bool check = false;

    if (n == ';') {check = true;}
    else if (n == ':') {check = true;}
    else if (n == '!') {check = true;}
    else if (n == ',') {check = true;}
    else if (n == '.') {check = true;}
    else if (n == '=') {check = true;}
    else if (n == '{') {check = true;}
    else if (n == '}') {check = true;}
    else if (n == '(') {check = true;}
    else if (n == ')') {check = true;}
    else if (n == '[') {check = true;}
    else if (n == ']') {check = true;}
    else if (n == '@') {check = true;}

    return check;
}

// ****  you must modify the following function *****
// return the next token - return "?" as the token class and token value on error or end of input
string tokensf::next_token()
{
    // you should read input using the nextch() function
    // the last character read is in instance variable ch
    // always read one character past the end of the token being returned

    // this loop reads one character at a time until it reaches end of input
    while ( StopMistake || ch != EOF)
    {

      //return classtoken string checking with help functions if number, keyword, letter or puntuation.
      if (findLetter(ch))
      {
          value = "";
          while (findLetter(ch) || isdigit(ch))
          {
            value += ch;
            nextch();
          }
          if (findKey(value))
          {
            return "keyword";
          }
          else
          {
        	 return "identifier";
          }
      }

      else if (isdigit(ch))
      {
        value = "";

        if (ch == '0')
        {
            value += ch;
            nextch();

            if(findDigit(ch))
            {
            	value += ch;
            	nextch();

            	while (isdigit(ch))
            	{
            		value += ch;
            	    nextch();
            	}
            }
            return "number";
        }

        else
        {
            while (isdigit(ch))
            {
              value += ch;
              nextch();
            }

            if(findDigit(ch))
            {
                value += ch;
                nextch();

                while (isdigit(ch))
                {
                    value += ch;
                    nextch();
              	}
            }
            return "number";
        }  
      }
      
      else if (findPun(ch))
      {
          value = "";
          value += ch;
          nextch();
          return "punctuation";
      }

      //return nothing if it is a comment, and ignore all the character in between.

      else if (ch == '/')
      {   
        nextch();
          
        if (ch == '/')
        {
         	while (isprint(ch))
            {
              nextch();
            }
        }

        else if (ch == '*')
        {
            while (true || ch != EOF)
			{
            	nextch();
            	if (ch == '*')
            	{
            		nextch();
					if (ch == '/')
					{
						nextch();
						break;
					}
				 }
             }
          }
      }            

      // Do anything if it is an empty space
      else if (isspace(ch))
      {

      }
      // Break the main loop if there is a mistake with the input
      else
      {
          StopMistake = false;
          break;
      }
      nextch();
    }
    value = "?" ;
    return "?" ;
}

