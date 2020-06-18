#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

class myStack
{
public:
	myStack();
	void push(std::string symbol);
	std::string pop();
	bool empty();
	~myStack();
private:
	std::vector<std::string> List;
};

#endif //MYSTACK_H
