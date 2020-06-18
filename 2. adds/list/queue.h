#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "singlelinklist.h"

class Queue
{
public:
	Queue();
	~Queue();

	void push(char value);
	void pop();
	char front();
	int size();

private:
	SingleLinkList list;
};

#endif