#include "queue.h"

using namespace std;

Queue::Queue()
{

}

Queue::~Queue()
{
	list.~SingleLinkList();
}

void Queue::push(char value)
{
	list.newEndNode(value);
}

void Queue::pop()
{
	list.delFrontNode();
}

char Queue::front()
{
	list.showFrontNode();
}

int Queue::size()
{
	return list.getSize();
}