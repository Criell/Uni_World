#include <iostream>
#include <stdlib.h>
#include "tokeniser.h"

using namespace std ;

// the last token read - start with ?
static string token = "?" ;
static string tokenclass = "?" ;
static string tokenvalue = "?" ;

// useful parsing functions
void nextToken()
{
	token = next_token() ;
	tokenclass = token_class() ;
	tokenvalue = token_value() ;
}

// if we have the expected token - move to next token otherwise give up!
void mustbe(string expected)
{
	if ( expected != token )
	{
		cout << "Error: found token \"" << token << "\" but expected \"" << expected << "\"" << endl ;
		exit(-1) ;
	}
	nextToken() ;
}

// if we have the expected token - move to next token and return true
bool have(string expected)
{
	if ( expected != token ) return false ;
	nextToken() ;
	return true ;
}

// the grammar we are recognising
// TERM: DEFINITION
// program: declarations statement
// declarations: ('var' identifier ';')*
// statement:  whileStatement |
//             ifStatement |
//             letStatement |
//             '{' statementSequence '}'
// whileStatement: 'while' '(' condition ')' statement
// ifStatement: 'if' '(' condition ')' statement ('else' statement)?
// letStatement: 'let' identifier '=' expression ';'
// statementSequence: (statement)*
// expression: term (op term)?
// condition: term relop term
// term: identifier | integerConstant
// TOKEN: DEFINITION
// identifier: ('a'-'z'|'A'-'Z')('a'-'z'|'A'-'Z'|'0'-'9')*
// integerConstant:    ('0'-'9')('0'-'9')*
// relop:      '<' | '<=' | '==' | '!=' | '>' | >='
// op:         '+' | '-' | '*' | '/'
// keyword:    'var' | 'while' | 'if' | 'else' | 'let'
// symbol:     '{' | '}' | '(' | ')' | ';' | '='


// since parsing is recursive, forward declare one function to parse each non-terminal:
void parseProgram() ;
void parseDeclarations() ;
void parseStatement() ;
void parseWhileStatement() ;
void parseIfStatement() ;
void parseLetStatement() ;
void parseStatementSequence() ;
void parseExpression() ;
void parseCondition() ;
void parseTerm() ;

// now implement the parsing functions
void parseProgram()
{
	parseDeclarations();
	parseStatement();
}

void parseDeclarations()
{
	while (have("var"))
	{
		mustbe("identifier");
		mustbe(";");
	}
}

void parseStatement()
{
	if ( have("while") ) parseWhileStatement() ; else
	if ( have("if") ) parseIfStatement() ; else
	if ( have("let") ) parseLetStatement() ; else
	{
		mustbe("{") ;
		parseStatementSequence() ;
		mustbe("}") ;
	}
}

void parseWhileStatement()
{
	mustbe("(");
}

void parseIfStatement()
{
	
}

void parseLetStatement()
{
}

void parseStatementSequence()
{
}

void parseExpression()
{
}

void parseCondition()
{
}

void parseTerm()
{
}

// call parseProgram from here
void parser()
{
	// create a tokeniser and read first token to initialise it
	init_tokeniser() ;
	nextToken() ;

	// parse a Program
	parseProgram() ;

	// check for end of file
	mustbe("?") ;
}
