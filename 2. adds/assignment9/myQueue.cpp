#include "myQueue.h"

myQueue::myQueue(){}

//push in the back position of the queue a new element
void myQueue::push(int number){
	if (List.size()==0){
		List.push_back(number);
	}
	else{
		List.insert(List.begin(), 1, number);
	}
}

//pop out of the queue the first element
int myQueue::pop(){
	if ((int)List.size() > 0) {
		int temp = List.back();
		List.pop_back();
		return temp;
	}
	else{
		exit(0);
	}
}

//return true when the queue is empty
bool myQueue::empty(){
	bool no_elemets = false;

	if ((int)List.size() == 0){
		no_elemets = true;
	}

	return no_elemets;
}

myQueue::~myQueue(){}







