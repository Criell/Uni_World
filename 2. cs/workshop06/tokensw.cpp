// a skeleton of the tokensw class implementation

#include "tokensw.h"
#include <iostream>
#include <ctype.h>
#include <sstream>

// to shorten the code
using namespace std ;

////////////////////////////////////////////////////////////////////////

// the following global pointer and functions exist to keep the tokensw class
// and its implementation completely hidden from the main function

// pointer to tokeniser object
static tokensw *tokeniser ;

// create and initialise the tokensier - must be called first and exactly once
void init_tokeniser()
{
    tokeniser = new tokensw() ;
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

// the following externally defined function must be used to lookup jumps and nulls
// it returns "" if the string passed in is not a jump or null
string lookup_jump_or_null(string) ;


////////////////////////////////////////////////////////////////////////

// the following are the implementations of the tokensw class functions

// construct and initialise a tokensw tokeniser
tokensw::tokensw()
{
    // token value initially ""
    value = "" ;

    // read first character to initialise the tokeniser
    ch = read_char() ;
}

// read next character in the input and record in instance variable ch
void tokensw::nextch()
{
    ch = read_char() ;
}

// return the current token value
string tokensw::token_value()
{
    return value ;
}

// Helper functions can go here - these can simplify writing next_token()
// Some useful builtin helper functions include, isalpha(), isdigit(), isalnum(), etc.

bool findPun(string n)
{
    bool check = false;

    if (n == "JMP") {check = true;}
    else if (n == "JLT") {check = true;}
    else if (n == "JLE") {check = true;}
    else if (n == "JGT") {check = true;}
    else if (n == "JGE") {check = true;}
    else if (n == "JEQ") {check = true;}
    else if (n == "JNE") {check = true;}

    return check;
}


// ****  you must modify the following function *****
// return the next token - return "?" as the token class and token value on error or end of input
string tokensw::next_token()
{
    // you should read input using the nextch() function
    // the last character read is in instance variable ch
    // always read one character past the end of the token being returned

    // this loop reads one character at a time until it reaches end of input
    

    stringstream oldcha;
    oldcha << ch;

    string cha;
    stringstream newcha(cha);

    while ( ch != EOF )
    {
        if (isdigit(ch))
        {
          value = "";
          while (isdigit(ch))
          {
            value += ch;
            nextch();
          }
          return "number";
        }

        else if (isalpha(ch))
        {
          value = "";
          while (isalpha(ch))
          {
            value += ch;
            nextch();
          }
          return "identifier";
        }

        else if (findPun(cha))
        {
          value = "";
          while (findPun(cha))
          {
            value += ch;
            nextch();
          }
          return "jump";
        }
    
        nextch();
    }


    value = "?" ;
    return "?" ;
}

