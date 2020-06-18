#include "myStack.h"

myStack::myStack(){}

//push in the back position of the stack a new element
void myStack::push(std::string symbol){
	List.push_back(symbol);
}

//pop out of the stack the last element
std::string myStack::pop(){
	if ((int)List.size() > 0) {
		std::string temp = List.back();
		List.pop_back();
		return temp;
	}
	else{
		return " ";
	}
}

//return true when the stack is empty
bool myStack::empty(){
	bool no_elemets = false;

	if ((int)List.size() == 0){
		no_elemets = true;
	}

	return no_elemets;
}

myStack::~myStack(){}
