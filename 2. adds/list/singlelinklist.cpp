#include "singlelinklist.h"

using namespace std;

SingleLinkList::SingleLinkList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

SingleLinkList::~SingleLinkList()
{
	while (head != NULL)
	{
		delEndNode();
	}

}

void SingleLinkList::newEndNode(char value)
{
	singleLinkNode* temp;

	temp = new singleLinkNode();
	temp->data = value;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	} else
	{
		tail->next = temp;
		tail = tail->next;
	}

	size++;
	temp = NULL;
}

void SingleLinkList::delEndNode()
{
	singleLinkNode *current = head;
	singleLinkNode *previous;

	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}

	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	} else
	{
		tail = previous;
		previous->next = NULL;
	}

	delete current;

	size--;
}

void SingleLinkList::delFrontNode()
{
    singleLinkNode *temp;

    temp = head;

    if (head == tail)
	{
		head = NULL;
		tail = NULL;
	} else
	{
    	head = head->next;
    }

    delete temp;

    size--;
}

char SingleLinkList::showFrontNode()
{
	return head->data;
}

char SingleLinkList::showEndNode()
{
	return tail->data;
}

int SingleLinkList::getSize()
{
	return size;
}