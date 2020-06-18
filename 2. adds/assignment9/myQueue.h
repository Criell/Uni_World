#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
class myQueue
{
public:
	myQueue();
	void push(int number);
	int pop();
	bool empty();
	~myQueue();

private:
	std::vector<int> List;
};

#endif //QUEUE_H
