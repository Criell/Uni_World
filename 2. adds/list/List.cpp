#include <iostream>

struct node {
	int data;
	node *next;
}; 

int size = 0;

node *head = NULL;
node *tail = NULL;

bool empty(){
	node *temp = head;
	if (head ==NULL){
		return true;
	}
	temp = NULL;
	delete temp;
	return false;	
}

int list_size(){
	if (head == NULL){
		return -1;
	}
	else
		return size;
}

void enqueue(int value){
 	node *temp = new node;
 	temp -> data = value;
 	temp -> next = NULL;
 	if (head == NULL){
 		head = temp;
 		tail = temp;				
 	}
 	else{
 		tail->next = temp;
 		tail = temp;
 	}
 	size ++;
 	 //std::cout << size << ", " << temp -> data << std::endl;

 	temp = NULL;
 	delete temp;
}

void push (int value){
	node *temp = new node;
	temp -> data = value;
	temp -> next = head;
	if (head == NULL){
		tail = temp;
	} 
	head = temp;
	size ++;
	//std::cout << size << ", " << temp -> data << std::endl;
	temp = NULL;
	delete temp;
}

void pop (){
	node *temp = head->next;

	head = temp;
		
	temp = NULL;
	delete temp;
	size --;
}

void offTail(){
	node *temp = head;
	node *prev;

	while (temp != tail){
		prev = temp;
		temp = temp -> next;
	}

	prev->next = NULL;
	tail = prev;
		
	temp = NULL;
	delete temp;
	size --;
}

void print(){
	node *current = head;
	while(current != NULL)
	{
		std::cout << current->data << ", ";
		current = current->next;
	}
	std::cout << std::endl;
}

void AddPos(int input, int val){
	
	node* current = head;
	node* prev;

	for (int i = 0; i < val; i++){
		prev = current;
		current = current->next;
	}

	node* temp =new node;
	temp->data = input;
	temp->next = current;
	prev->next = temp;
	
}

void DelPos(int val){
	node* temp = head;
	node* prev;

	for (int i = 0; i< val; i++){
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;
}

int main(){

	push(245);
	push(54);
	push(2);
	print();

	enqueue(89);
	enqueue(12);
	enqueue(5);
	print();

	pop();
	print();

	offTail();
	print();
	
	AddPos(100, 3);
	print();

	DelPos(2);
	print();
	
	return 0;
}

