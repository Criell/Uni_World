#ifndef TOKENS_W_H
#define TOKENS_W_H

// tokeniser for the tokeniser-m program

#include <string>

// DO NOT MODIFY THE NEXT 3 LINES
extern void init_tokeniser() ;          // initialise the tokensier
extern std::string next_token() ;       // next token
extern std::string token_value() ;      // token value

// the tokens class reads tokens using the input function read_char()
// you can change this as much as you like
class tokensw
{
public:
    tokensw() ;                         // default constructor
    void init_tokeniser() ;             // initialise this tokeniser
    std::string next_token() ;          // read the next token from the input and return its token class
    std::string token_value() ;         // return the current token as a string
private:
    void nextch() ;                     // read the next character
    int ch ;                            // next character to read
    std::string value ;                 // value of last token read
};
#endif //TOKENS_W_H
