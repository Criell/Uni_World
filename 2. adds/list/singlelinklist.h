#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H

#include <iostream>

struct singleLinkNode
{
	char data;
	singleLinkNode* next;
};


class SingleLinkList
{
public:
	SingleLinkList();
	~SingleLinkList();

	void newEndNode(char value);
	void delEndNode();
	void delFrontNode();
	char showEndNode();
	char showFrontNode();
	int getSize();

private:
	singleLinkNode *head, *tail;
	int size;
};

#endif