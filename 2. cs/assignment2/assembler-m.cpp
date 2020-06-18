// convert Hack assembly into binary
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "tokeniser.h"
#include "symbols.h"

// to simplify the code
using namespace std ;

void transform(int number)
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
	cout << binary << endl;
}

// standard input is the contents of a Hack assembly file
void assembler_m()
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

	symbol_table_string table_jump = create_symbol_table_string() ;
	if ( !table_jump->insert("NULL","000") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JMP","111") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JLT","100") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JLE","110") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JGT","001") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JGE","011") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JEQ","010") ) cout << "Error!" << endl ;
	if ( !table_jump->insert("JNE","101") ) cout << "Error!" << endl ;


	// initialise the tokeniser
	init_tokeniser() ;
	string token, comp, dest, jump, binary, temp;
	int memory = 16;

	while ( token != "?" )			// stop at EOF, "?" denotes EOF
	{
		token = next_token();
		//cout << token_value() << endl;

		if (token == "address")
		{
			temp = token_value();
			int count = 0;

			for (int i = 0; i < temp.length(); i++ ){
				if (isdigit(temp[i])){count = count +1;}
			}

			if (count == temp.length()){
				int number = 0;
				stringstream convert(token_value());
				convert >> number;
				transform (number);
				temp.clear();
			}
			else {
				transform (memory);
				memory++;
			}
		}
		else if (token == "label")
		{
			transform (memory);
			memory++;
		}

		else if ((token == "comp")||(token == "dest-comp?"))
		{
			if (token_value() == "0"){
				comp = tablecomp->lookup("0");
				//cout << comp << endl;
			}
			else if (token_value() == "1"){
				comp = tablecomp->lookup("1");
				//cout << comp << endl;
			}
			else if (token_value() == "-1"){
				comp = tablecomp->lookup("-1");
				//cout << comp << endl;
			}
			else if (token_value() == "!D"){
				comp = tablecomp->lookup("!D");
				//cout << comp << endl;
			}
			else if (token_value() == "!A"){
				comp = tablecomp->lookup("!A");
				//cout << comp << endl;
			}
			else if (token_value() == "-D"){
				comp = tablecomp->lookup("-D");
				//cout << comp << endl;
			}
			else if (token_value() == "-A"){
				comp = tablecomp->lookup("-A");
				//cout << comp << endl;
			}
			else if (token_value() == "D+1"){
				comp = tablecomp->lookup("D+1");
				//cout << comp << endl;
			}
			else if (token_value() == "A+1"){
				comp = tablecomp->lookup("A+1");
				//cout << comp << endl;
			}
			else if (token_value() == "D-1"){
				comp = tablecomp->lookup("D-1");
				//cout << comp << endl;
			}
			else if (token_value() == "A-1"){
				comp = tablecomp->lookup("A-1");
				//cout << comp << endl;
			}
			else if (token_value() == "D+A"){
				comp = tablecomp->lookup("D+A");
				//cout << comp << endl;
			}
			else if (token_value() == "D-A"){
				comp = tablecomp->lookup("D-A");
				//cout << comp << endl;
			}
			else if (token_value() == "A-D"){
				comp = tablecomp->lookup("A-D");
				//cout << comp << endl;
			}
			else if (token_value() == "D&A"){
				comp = tablecomp->lookup("D&A");
				//cout << comp << endl;
			}
			else if (token_value() == "D|A"){
				comp = tablecomp->lookup("D|A");
				//cout << comp << endl;
			}
			else if (token_value() == "!M"){
				comp = tablecomp->lookup("!M");
				//cout << comp << endl;
			}
			else if (token_value() == "-M"){
				comp = tablecomp->lookup("-M");
				//cout << comp << endl;
			}
			else if (token_value() == "M+1"){
				comp = tablecomp->lookup("M+1");
				//cout << comp << endl;
			}
			else if (token_value() == "M-1"){
				comp = tablecomp->lookup("M-1");
				//cout << comp << endl;
			}
			else if (token_value() == "D+M"){
				comp = tablecomp->lookup("D+M");
				//cout << comp << endl;
			}
			else if (token_value() == "D-M"){
				comp = tablecomp->lookup("D-M");
				//cout << comp << endl;
			}
			else if (token_value() == "M-D"){
				comp = tablecomp->lookup("M-D");
				//cout << comp << endl;
			}
			else if (token_value() == "D&M"){
				comp = tablecomp->lookup("D&M");
				//cout << comp << endl;
			}
			else if (token_value() == "D|M"){
				comp = tablecomp->lookup("D|M");
				//cout << comp << endl;
			}
			else if (token_value() == "A"){
				comp = tablecomp->lookup("A");
				//cout << comp << endl;
			}
			else if (token_value() == "M"){
				comp = tablecomp->lookup("M");
				//cout << comp << endl;
			}
			else if (token_value() == "D"){
				comp = tablecomp->lookup("D");
				//cout << comp << endl;
			}

			token = next_token();

			if (token == "arrow")
			{
				token = next_token();

				if ((token == "dest")||(token == "dest-comp?"))
				{
					if (token_value() == "A"){
						dest = table_dest->lookup("A");
						//cout << dest << endl;
					}
					else if (token_value() == "M"){
						dest =  table_dest->lookup("M");
						//cout << dest << endl;
					}
					else if (token_value() == "D"){
						dest = table_dest->lookup("D");
						//cout << dest << endl;
					}
					else if (token_value() == "MD"){
						dest = dest + table_dest->lookup("MD");
						//cout << dest << endl;
					}
					else if (token_value() == "AM"){
						dest = table_dest->lookup("AM");
						//cout << dest << endl;
					}
					else if (token_value() == "AD"){
						dest = table_dest->lookup("AD");
						//cout << dest << endl;
					}
					else if (token_value() == "AMD"){
						dest = table_dest->lookup("AMD");
						//cout << dest << endl;
					}

				}
			}
			else{
				dest = table_dest->lookup("NULL");
				//cout << dest << endl;
			}


			if (token == "semi")
			{
				token = next_token();

				if (token == "jump")
				{
					if (token_value() == "JMP"){
						jump = table_jump->lookup("JMP");
						//cout << jump << endl;
					}
					else if (token_value() == "JLT"){
						jump = table_jump->lookup("JLT");
						//cout << jump << endl;
					}
					else if (token_value() == "JLE"){
						jump = table_jump->lookup("JLE");
						//cout << jump << endl;
					}
					else if (token_value() == "JGT"){
						jump = table_jump->lookup("JGT");
						//cout << jump << endl;
					}
					else if (token_value() == "JGE"){
						jump = table_jump->lookup("JGE");
						//cout << jump << endl;
					}
					else if (token_value() == "JEQ"){
						jump = table_jump->lookup("JEQ");
						//cout << jump << endl;
					}
					else if (token_value() == "JNE"){
						jump = table_jump->lookup("JNE");
						//cout << jump << endl;
					}
				}
			}
			else{
				jump = table_jump->lookup("NULL");
			}

			binary = comp + dest + jump;
			comp.clear();
			dest.clear();
			jump.clear();
		 	cout << binary << endl;
		 	binary.clear();
		}
	}
}
