#include "stack.h"

using namespace std;

Stack::Stack()
{

}

Stack::~Stack()
{
	list.~SingleLinkList();
}

void Stack::push(char value)
{
	list.newEndNode(value);
}

void Stack::pop()
{
	list.delEndNode();
}

char Stack::top()
{
	list.showEndNode();
}

int Stack::size()
{
	return list.getSize();
}