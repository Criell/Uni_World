#include <iostream>
#include <sstream>
#include <string>

#include "csdocument.h"
#include "iobuffer.h"
#include "symbols.h"
#include "tokeniser.h"

using namespace std;

// Function declarations
void Program(cs_node root);
void Class(cs_node root);

void SubroutineDecs(cs_node root);

void ClassName(cs_node root);
void SubroutineName(cs_node root);
bool SearchSubroutineName(cs_node root);
void InsertVarName(cs_node root);
void VarName(cs_node root);
bool SearchVarName();

void ArrayIndex(cs_node root);

void Constructor(cs_node root);
void Function(cs_node root);
void Method(cs_node root);
void Type(cs_node root);
void vType(cs_node root, string type_safe);
void ParameterList(cs_node root);
void SubroutineBody(cs_node root);

void ClassVarDecs(cs_node root);
void VarDecs(cs_node root, int* offset);
void VarDec(cs_node root, int* offset);
void type_segment_offset(cs_node root, string Segment_input, int* offset, string type_safe);

void Statements(cs_node root);
void Statements_let(cs_node root);
void Statements_if(cs_node root);
void Statements_while(cs_node root);
void Statements_do(cs_node root);
void Statements_return(cs_node root);

void Expression(cs_node root);
void ExpressionList(cs_node root);
void SubroutineCall(cs_node root);
cs_node Term();
void Infix(cs_node root);
void InfixOp(cs_node root);
void UnaryOp(cs_node root);

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
	//cout << " ----Mueven el token ? " << token << " con value " << tokenvalue<< endl;
	//cout << endl;
}

// if we have the expected token - move to next token otherwise give up!
void mustbe(string expected)
{
	if ( expected != token )
	{
		//cout << "Error: found token \"" << token << "\" but expected \"" << expected << "\"" << endl ;
		//exit(-1) ;
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

bool haveExpression(string expected,cs_node root)
{

	//cout << "***haveExpression - "<< expected << endl;

	if ( expected == "integerConstant") return true ;
	else if ( expected == "stringConstant") return true ;
	else if ((expected == "true") ||(expected == "false") ||(expected == "null") ||(expected == "this"))
		return true ;
	else if ((expected == "+")||(expected == "-")||(expected == "*")||(expected == "/")||(expected == "&")||(token == "|")||(expected == "<")||(expected == ">")||(expected == "="))
		return true ;
	else if (token == "-" || token == "~") return true ;

	else if ( SearchVarName())return true;
	
	else if ( expected == "identifier"){
		InsertVarName(root);
	}
	else return false ;
}

bool haveTerm()
{
	//cout << "***haveExpression - "<< expected << endl;
	if ( token == "integerConstant") return true ;
	else if ( token == "stringConstant") return true ;
	else if ((token_value() == "true") ||(token_value() == "false") ||(token_value() == "null") ||(token_value() == "this"))
		return true ;	
	else if (token_value() == "-" || token_value() == "~") return true ;
	else if ( SearchVarName())return true;
	else return false ;
}

bool FindInfix(){

	if ((token == "+")||(token == "-")||(token == "*")||(token == "/")||(token == "&")||(token == "|")||(token == "<")||(token == ">")||(token == "="))
		return true;
	else return false;
}

symbol_table_string Variables_Table = create_symbol_table_string();

cs_node jack_parser()
{
	// init_tokeniser();  // Initialise tokens
	// nextToken();

	// //cout << "***The Class";
	// cs_node root = cs_new_node("class");

	// Program(root);

	// return root;

	return nullptr;
}


void Program(cs_node root)
{
	while (have("class"))
	{
		Class(root);
	}
}

void Class(cs_node root)
{
	ClassName(root);
	mustbe("{");
	ClassVarDecs(root);
	SubroutineDecs(root);
	mustbe("}");
}

void SubroutineDecs(cs_node root)
{
	//cout << "***SubroutineDecs***";
	cs_node subroutineDecs = cs_new_node("subroutineDecs");
	cs_append_child(root, subroutineDecs);

	while ((token == "constructor") ||(token == "function") ||(token == "method")){

 		if (token == "constructor"){
 			Constructor(subroutineDecs);
 		}

 		else if (token == "function"){
 			Function(subroutineDecs);
 		}

 		else if (token == "method"){
 			Method(subroutineDecs);
 		}
 	}
}

void Constructor(cs_node root){
	//cout << "***Constructor***";
 	cs_node constructor = cs_new_node("constructor");
 	cs_append_child(root, constructor);
 	nextToken();
 	
 	ClassName(constructor);
 	SubroutineName(constructor);
 	mustbe("(");
 	ParameterList(constructor);
 	mustbe(")");
 	SubroutineBody(constructor);
}

void Function(cs_node root){
	//cout << "***Function***";
 	cs_node function = cs_new_node("function");
 	cs_append_child(root, function);
 	nextToken();
 	
 	Type(function);
 	SubroutineName(function);
 	mustbe("(");
 	ParameterList(function);
 	mustbe(")");
 	SubroutineBody(function);
 }

void Method(cs_node root){
 	//cout << "***Method***";	
 	cs_node method = cs_new_node("method");
 	cs_append_child(root, method);
 	nextToken();

 	Type(method);

 	SubroutineName(method);
 	mustbe("(");
 	ParameterList(method);
 	mustbe(")");
 	SubroutineBody(method);
}

void Type(cs_node root){
	if ((token == "identifier")||(token == "void")||(token == "int")||(token == "char")||(token == "boolean")){
		//cout << "Type";	
		cs_node type = cs_new_node_text("type", tokenvalue);
		cs_append_child(root, type);
		nextToken();
	}
}

void ParameterList(cs_node root){
	//cout << "***ParameterList***";
	cs_node parameterList = cs_new_node("parameterList");
	cs_append_child(root, parameterList) ;

	Type(root);
	VarName(root);

	while (have(",")){
		Type(root);
		VarName(root);
	}
}

void SubroutineBody(cs_node root){
	//cout << "***SubroutineBody***";
	cs_node subroutineBody = cs_new_node("subroutineBody");
	cs_append_child(root, subroutineBody) ;

	int offset_local = 0;
	mustbe("{");
	VarDecs(subroutineBody, &offset_local);
	Statements(subroutineBody);
	mustbe("}");
}

void Statements(cs_node root)
{
	//cout << "***Statements***";
	cs_node statements = cs_new_node("statements");
	cs_append_child(root, statements) ;

	while (token == "let" || token == "if" || token == "while" || token == "do" || token == "return")
	{
		cs_node statement = cs_new_node("statement");
		cs_append_child(statements, statement) ;

		if (token == "let"){
			Statements_let(statement);
		}
		else if (token == "if"){
			Statements_if(statement);
		}

		else if ( token == "while"){
			Statements_while(statement);
		}

		else if (token == "do"){
			Statements_do(statement);
		}

		else if (token == "return"){
			Statements_return(statement);
		}
	}
}

void Statements_let(cs_node root){
	//cout << "***Statements_let***";
	cs_node letStatement = cs_new_node("letStatement");
	cs_append_child(root, letStatement) ;
	nextToken();
	VarName(letStatement);
	ArrayIndex(letStatement);
	mustbe("=");
	Expression(letStatement);
	mustbe(";");
}

void Statements_if(cs_node root){
	//cout << "***Statements_if**";
	cs_node ifStatement = cs_new_node("ifStatement");
	cs_append_child(root, ifStatement) ;
	nextToken();

	mustbe("(");
	Expression(ifStatement);
	mustbe(")");

	mustbe("{");
	Statements(ifStatement);
	mustbe("}");

	if (have("else")){
		mustbe("{");
		Statements(ifStatement);
		mustbe("}");
	}
}

void Statements_while(cs_node root){
	//cout << "***Statements_while***";
	cs_node whileStatement = cs_new_node("whileStatement");
	cs_append_child(root, whileStatement) ;
	nextToken();

	mustbe("(");
	Expression(whileStatement);
	mustbe(")");

	mustbe("{");
	Statements(whileStatement);
	mustbe("}");
}

void Statements_do(cs_node root){
	//cout << "***Statements_do***";
	cs_node doStatement = cs_new_node("doStatement");
	cs_append_child(root, doStatement) ;
	nextToken();

	ClassName(doStatement);

	VarName(doStatement);

	mustbe(".");

	
	SubroutineName(doStatement);
	mustbe("(");
	ExpressionList(doStatement);
	mustbe(")");
}

void Statements_return(cs_node root){
	//cout << "***Statements_return***";
	cs_node returnStatement = cs_new_node("returnStatement");
	cs_append_child(root, returnStatement) ;
	nextToken();
	Expression(returnStatement);
	mustbe(";");			
}


void ClassVarDecs(cs_node root)
{
	//cout << "***ClassVarDecs***";
	cs_node classVarDecs = cs_new_node("classVarDecs");
	cs_append_child(root, classVarDecs);

	int offset_static = 0;
	int offset_field = 0;

	while (token == "static" || token == "field")
	{
		if (token == "static"){
			VarDec(classVarDecs,&offset_static);
		}

		if (token == "field"){
			VarDec(classVarDecs, &offset_field);
		}
	}
}

void VarDecs(cs_node root, int* offset)
{
	//cout << "***VarDecs***";
	cs_node VarDecs = cs_new_node("varDecs");
	cs_append_child(root, VarDecs) ;
	VarDec(VarDecs, offset);
}

void VarDec(cs_node root, int* offset)
{
	while (token == "var" || token == "field" || token == "static"){

		string Segment_input;
		if (token == "var") Segment_input = "local";
		else Segment_input = token ;

		nextToken();

		string type_safe = token;
		nextToken();

		//cout << "***VarDec***";
		cs_node varDec = cs_new_node("varDec");
		cs_append_child(root, varDec);
		type_segment_offset(varDec, Segment_input, offset, type_safe);
		
		if (token == (";")){
			mustbe(";");
		}
		else{
			while (have(",")){
				//cout << "***Inside ,***" << token_value();
				cs_node varDec = cs_new_node("varDec");
				cs_append_child(root, varDec);

				type_segment_offset(varDec, Segment_input, offset, type_safe);
			}

			mustbe(";");
		}
	}
}

void vType(cs_node root, string type_safe){
	if ((type_safe == "identifier")||(type_safe == "int")||(type_safe == "char")||(type_safe == "boolean")){
		//cout << "***vType***";
		cs_node type = cs_new_node_text("type", type_safe);
		cs_append_child(root, type);
	}
}

void type_segment_offset(cs_node root, string Segment_input, int* offset,string type_safe){

	//cout << "***Inside segment*** "<< token_value();
	
	InsertVarName(root);
	vType(root, type_safe);

	cs_node Segment = cs_new_node("Segment");
	cs_append_child(Segment, cs_new_text(Segment_input));
	cs_append_child(root, Segment) ;

	std::stringstream temp;
	temp << *offset;
	std::string count;
	count = temp.str();
	cs_node Offset = cs_new_node("Offset");
	cs_append_child(Offset,cs_new_text(count));
	(*offset)++;
	cs_append_child(root, Offset) ;

	//cout << "***End Segment*** "<< token_value();

}

void Expression(cs_node root){
	
	//cout << "***Expression***" << token_value() << endl;
	if (haveExpression(token, root)){

		cs_node expression = cs_new_node("expression");
		cs_append_child(root, expression);

		while (haveTerm()) 
		{
			cs_node temp_temporal = Term();

			if (!FindInfix()){
				cs_append_child(expression, temp_temporal) ;
			}
			else {
				cs_node infix  = cs_new_node("infix");
				cs_append_child(expression, infix);
				cs_append_child(infix, temp_temporal);
				InfixOp(infix);
				cs_append_child(infix, Term());
			}

		}
	}
}


void InfixOp(cs_node root){
	//cout << "***InfixOp***"  << token_value() << endl;
	if (FindInfix()){
		cs_node infixOp  = cs_new_node("infixOp");
		cs_append_child(infixOp,cs_new_text(token_value()));
		cs_append_child(root, infixOp) ;
		nextToken();
	}
}

cs_node Term(){
	//cout << "***Term***" << token_value() << endl;
	cs_node term  = cs_new_node("term");
	
		if (token == "integerConstant"){
			//cout << "***Term number***";
			cs_node integerConstant = cs_new_node("integerConstant");
			cs_append_child(integerConstant,cs_new_text(token_value()));
			cs_append_child(term, integerConstant) ;
			nextToken();
		}

		if (token == "stringConstant"){
			//cout << "***Term letters***";
			cs_node stringConstant = cs_new_node("stringConstant");
			cs_append_child(stringConstant,cs_new_text(token_value()));
			cs_append_child(term, stringConstant) ;
			nextToken();
		}

		if ((token == "true") ||(token == "false") ||(token == "null") ||(token == "this")){
			//cout << "***Term bool***";
			cs_node keywordConstant = cs_new_node("keywordConstant");
			cs_append_child(keywordConstant,cs_new_text(token_value()));
			cs_append_child(term, keywordConstant) ;
			nextToken();
		}

		VarName(term);
		ArrayIndex(term);
		SubroutineCall(term);

		if (have("("))
		{
			Expression(term);
			mustbe(")");
		}

		if ((token == "-") || (token == "~")){
			//cout << "***Term unary***";
			cs_node unary = cs_new_node("unary");
			cs_append_child(unary,cs_new_text(token_value()));
			cs_append_child(term, unary) ;
			nextToken();
		}

	return term;
}

void ArrayIndex(cs_node root){

	if ( token == "["){
		//cout << "***ArrayIndex***";
		cs_node arrayIndex = cs_new_node("arrayIndex");
		cs_append_child(root, arrayIndex) ;
		mustbe("[");
		Expression(arrayIndex);
		mustbe("]");
	}
}

void SubroutineCall(cs_node root){
	if ( SearchVarName()){
		//cout << "***SubroutineCall***";
		cs_node subroutineCall  = cs_new_node("subroutineCall");
		cs_append_child(root, subroutineCall) ;
		nextToken();

		VarName(subroutineCall);
		ClassName(subroutineCall);

		mustbe(".");
		SubroutineName(subroutineCall);
		mustbe("(");
		ExpressionList(subroutineCall);
		mustbe(")");
	}
}

void ExpressionList(cs_node root){
	//cout << "***ExpressionList***";
	cs_node expressionList = cs_new_node("expressionList");
	cs_append_child(root, expressionList) ;

	Expression(root);

	while (have(",")){
		Expression(root);
	}
	mustbe(",");
}

void InsertVarName(cs_node root)
{
	Variables_Table->insert(token_value(), token_value());
	//cout <<"Now is in the table = " << Variables_Table->lookup(token_value()) << endl;
	VarName(root);
}

void VarName(cs_node root)
{
	if (SearchVarName()){
		//cout << "***VarName  - " << token_value() << endl;
		cs_node varName = cs_new_node_text("varName", tokenvalue);
		cs_append_child(root, varName);
		nextToken();
	}
}

bool SearchVarName()
{	//cout <<"SearchVarName"<< endl;
	if (Variables_Table->lookup(token_value()) == token_value()){
		//cout <<"True. in the table = " << Variables_Table->lookup(token_value()) << endl;
		return true;
	}
	else{
		//cout <<"False. No in the table." << endl;
		return false;
	}
}

void SubroutineName(cs_node root)
{
	if (token == "identifier"){
		//cout << "***SubroutineName - " << token_value() << endl;
		cs_node subroutineName = cs_new_node_text("subroutineName", tokenvalue);
		cs_append_child(root, subroutineName);
		nextToken();
	}

	if (!SearchVarName()){
		Variables_Table->insert(token_value(), "SubroutineName");
		//cout <<"Now is in the table = " << Variables_Table->lookup(token_value()) << endl;
	}
}

void ClassName(cs_node root)
{
	if (token == "identifier"){
		//cout << "***className*** - " << token_value() << endl;
		cs_node className = cs_new_node_text("className", tokenvalue);
		cs_append_child(root, className);
		nextToken();
	}

	if (!SearchVarName()){
		Variables_Table->insert(token_value(), "ClassName");
		//cout <<"Now is in the table = " << Variables_Table->lookup(token_value()) << endl;
	}
}