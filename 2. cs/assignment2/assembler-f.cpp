// convert Hack assembly into binary
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include "tokeniser.h"
#include "symbols.h"

// to simplify the code
using namespace std ;

string transform(int number)
{
	int digit = 0, temp = number;

	do{
	    temp = temp/2;
	    digit = digit+1;
	}
	while (temp>1);

	string binary, ceros;

	for (int i=digit; i>=0; i--)
	{
		if (number/pow(2,i) >= 1){
		   binary = binary + '1';
		   number=number-pow(2,i);
		}
		else{ binary = binary + '0'; }
	}

	digit = 15 - digit;
	for (int i = 0; i < digit; i++){
		ceros = ceros + '0';
	}

	binary = ceros + binary;

	return binary;
}

// standard input is the contents of a Hack assembly file
void assembler_f()
{
	symbol_table_string tablecomp = create_symbol_table_string() ;
	if ( !tablecomp->insert("0","1110101010") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("1","1110111111") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("-1","1110111010") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("!D","1110001101") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("!A","1110110001") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("-D","1110001111") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("-A","1110110011") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D+1","1110011111") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("A+1","1110110111") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D-1","1110001110") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("A-1","1110110010") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D+A","1110000010") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D-A","1110010011") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("A-D","1110000111") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D&A","1110000000") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D|A","1110010101") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("!M","1111110001") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("-M","1111110011") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("M+1","1111110111") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("M-1","1111110010") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D+M","1111000010") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D-M","1111010011") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("M-D","1111000111") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D&M","1111000000") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D|M","1111010101") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("A","1110110000") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("M","1111110000") ) cout << "Error!" << endl ;
	if ( !tablecomp->insert("D","1110001100") ) cout << "Error!" << endl ;

	symbol_table_string table_dest = create_symbol_table_string() ;
	if ( !table_dest->insert("NULL","000") ) cout << "Error!" << endl ;
	if ( !table_dest->insert("A","100") ) cout << "Error!" << endl ;
	if ( !table_dest->insert("M","001") ) cout << "Error!" << endl ;
	if ( !table_dest->insert("D","010") ) cout << "Error!" << endl ;
	if ( !table_dest->insert("MD","011") ) cout << "Error!" << endl ;
	if ( !table_dest->insert("AM","101") ) cout << "Error!" << endl ;
	if ( !table_dest->insert("AD","110") ) cout << "Error!" << endl ;
	if ( !table_dest->insert("AMD","111") ) cout << "Error!" << endl ;

	symbol_table_string table_jump = create_symbol_table_string();
	if ( !table_jump->insert("NULL","000") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JMP","111") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JLT","100") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JLE","110") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JGT","001") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JGE","011") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JEQ","010") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JNE","101") ) cout << "Error!" << endl ;

	symbol_table_string tablesymbol = create_symbol_table_string();
	if ( !tablesymbol->insert("SP","0000000000000000") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("LCL","0000000000000001") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("ARG","0000000000000010") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("THIS","0000000000000011") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("THAT","0000000000000100") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("SCREEN","0100000000000000") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("KBD","0110000000000000") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R0","0000000000000000") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R1","0000000000000001") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R2","0000000000000010") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R3","0000000000000011") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R4","0000000000000100") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R5","0000000000000101") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R6","0000000000000110") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R7","0000000000000111") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R8","0000000000001000") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R9","0000000000001001") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R10","0000000000001010") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R11","0000000000001011") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R12","0000000000001100") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R13","0000000000001101") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R14","0000000000001110") ) cout << "Error!" << endl ;
	if ( !tablesymbol->insert("R15","0000000000001111") ) cout << "Error!" << endl ;

	symbol_table_string table_address = create_symbol_table_string();
	
	// initialise the tokeniser
	init_tokeniser();
	string token, ad, comp, dest, jump, binary, temp;
	int variable = 16, lines = 0, counter=0;
	vector <string> program;
	

	while ( token != "?" )			// stop at EOF, "?" denotes EOF
	{
		token = next_token();

		if (token == "address")
		{
			temp = token_value();
			int count = 0, lower = 0;

			for (int i = 0; i < temp.length(); i++ ){
					if (isdigit(temp[i])){
						count = count +1;
					}
			}
					/*if (islower(temp[i])){
						lower = lower +1;
					}
			

			if (isdigit(temp[temp.length()-1])){
				lower = lower +1;
			}

			if (temp[temp.length()-2] == '.'){
				lower = lower +1;
			}

			else if(lower == temp.length()){
				ad = transform (variable);
				table_address->insert(token_value(), ad);
				variable++;
				program.push_back(ad); 
				lines++;
			}

			*/

			if (count == temp.length()){
				int number = 0;
				stringstream convert(token_value());
				convert >> number;
				ad = transform (number);
				program.push_back(ad); 
				lines++;
			}

			else if (tablesymbol->lookup(token_value()) != ""){
				ad = tablesymbol->lookup(token_value());
				program.push_back(ad); 
				lines++;
			}

			else if (table_address->lookup(token_value()) != ""){
				ad = table_address->lookup(token_value());
				program.push_back(ad); 
				lines++;
			}

			else {
				program.push_back(token_value())
				table_address->insert(token_value(), "address");
				lines++;
			}*/


			/*else {
				if (!isalpha(token_value()[0]))
				{
					int number = 0;
					stringstream convert(token_value());
					convert >> number;
					program.push_back(transform(number));
				} else
				{
					program.push_back(token_value());
				}
				lines++;
			}*/


		}
		else if (token == "label"){ 
			ad = transform (lines);
			table_address->update(token_value(), ad);
			for (int i = 0; i< program.size(); i++){
				if (program.at(i) == token_value()){
					program.at(i) = ad;
				}
			}
		}

		else if ((token == "comp")||(token == "dest-comp?")){
			if (tablecomp->lookup(token_value()) != ""){
				comp = tablecomp->lookup(token_value());
			}

			token = next_token();

			if (token == "arrow"){
				token = next_token();

				if ((token == "dest")||(token == "dest-comp?")){
					if (table_dest->lookup(token_value()) != ""){
						dest = table_dest->lookup(token_value());
					}
				}
			}
			else{dest = table_dest->lookup("NULL");}

			if (token == "semi")
			{
				token = next_token();

				if (token == "jump"){					
					if (table_jump->lookup(token_value()) != ""){
						jump = table_jump->lookup(token_value());
					}
				}
			}
			else{
				jump = table_jump->lookup("NULL");
			}

			binary = comp + dest + jump;

		 	program.push_back(binary); 
		 	lines++;
		}
	}


	for (int i = 0; i< program.size(); i++)
	{
		if

		else if (program.at(i) == table_address->lookup("address"){
			ad = transform (variable);
			table_address->update(token_value(), ad);
			program.at(i) = ad;
			variable++;
		}
		
	}

	/*for (int i = 0; i< program.size(); i++)
	{
		if (isalpha(program.lookup(to_string(i))[0]))
		{
			if (table_address.lookup(program.lookup(to_string(i))) != "")
			{
				program[i] = table_address->lookup(program[i])));
			}  else
			{
				table_address->insert(program->lookup(to_string(i)), dec_to_bin(to_string((variable)++)));
				program[i] = table_address->lookup(program[i])));
			}
		}
	}*/



	for (int i = 0; i< program.size(); i++){
		cout << program.at(i) << endl;
	}



}
