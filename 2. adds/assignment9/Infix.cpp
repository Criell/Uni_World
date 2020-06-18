#include "Infix.h"

/*** Use Input obj to ask for cin, created a vector with the operands
 *	 and a String with the signs.
 */
Infix::Infix(){
	Input ip;
	Str_Infix = ip.Taking_Input();
	Infix_Numbers = ip.Int_Numbers(Str_Infix);
	Str_Symbols = ip.Symbols(Str_Infix);
}

// Depending of the sign, return the result of a math operation.
int Infix::Result(std::string sign, int a, int b){
	int res = 0;

	if (sign == "+"){
		res = a + b;
	}
	else if (sign == "-"){
		res = a - b;
	}
	else if (sign == "*"){
		res = a * b;
	}
	else if (sign == "/"){
		res = a / b;
	}

	return res;
}


void Infix::Prefix_to_Infix(){
	Input ip;

	//Print Error when the Expression is not correct
	if (Str_Symbols.length()+1 != Infix_Numbers.size()){
		output.push_back("Error");
		ip.printOutput(output);
		return;
	}

	for (int i = 0; i < (int)Infix_Numbers.size(); i++){
		if (Infix_Numbers.at(i)<0 || Infix_Numbers.at(i)>99){
			output.push_back("Error");
			ip.printOutput(output);
			return;
		}
	}

	//Created the stack and push all the symbols in
	myStack St;

	for (int i = 0; i < (int)Str_Symbols.length(); i++){
		std::string temp;
		temp = Str_Symbols[i];
		St.push(temp);
	}

	//Created the queue and push all the numbers in
	myQueue Qu;

	for (int i = 0; i < (int)Infix_Numbers.size(); i++){
		Qu.push(Infix_Numbers.at(i));
	}

	/*** Pop from the stack a symbol and pop from the queue 2 numbers, push
	 *   them on a vector output in the format asked.
	 */
	std::string sign;
	int a=0, b=0, res=0;

	a = Qu.pop();
	b = Qu.pop();
	sign = St.pop();

	if ((sign == "-")||(sign == "+")){
		output.push_back(ip.Result_to_String(a));
		output.push_back(" ");
	}
	else{
		output.push_back(ip.Result_to_String(a));
		output.push_back(" ");
	}

	res = Result(sign, a, b);

	while (!(St.empty())){

		output.push_back(" ");
		output.push_back(sign);
		output.push_back(" ");
		output.push_back(ip.Result_to_String(b));

		if ((sign == "-")||(sign == "+")){
			output.insert (output.begin(), 1, "(");
			output.push_back(")");
		}
		else{
			output.push_back(" ");
		}
		b = Qu.pop();
		sign = St.pop();
		res = Result(sign, res, b);

	}

	output.push_back(" ");
	output.push_back(sign);
	output.push_back(" ");
	output.push_back(ip.Result_to_String(b));

	if ((sign == "-")||(sign == "+")){
		output.insert (output.begin(), 1, "(");
		output.push_back(")");
	}
	else{
		output.push_back(" ");
	}
	output.push_back(" = ");

	//push into output vector final result of math operations and print it
	output.push_back(ip.Result_to_String(res));
	ip.printOutput(output);
}

Infix::~Infix(){}


