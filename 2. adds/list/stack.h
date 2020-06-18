#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "singlelinklist.h"

class Stack
{
public:
	Stack();
	~Stack();

	void push(char value);
	void pop();
	char top();
	int size();

private:
	SingleLinkList list;
};

#endif