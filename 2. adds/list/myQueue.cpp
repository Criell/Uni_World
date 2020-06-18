#include <iostream> 


struct node{
	int data;
	node *next;
};

node* ReverseList(node *head)   
{
	if (!head)
	{
		return NULL;
	}
	node* temp = ReverseList(head->next);
	if (!temp)
	{
		return head;
	}
	head->next->next = head;
	head->next = NULL;
		return temp;
}

int list_size(node* head){

	int sizeL = 0;
	node* temp = head;

	while (temp != NULL){
		sizeL = sizeL +1;
		temp = temp->next;
	}

	temp=NULL;
	delete temp;

	return sizeL;
}

bool empty(node* head){
	bool no_elemets = false;
	if(head == NULL){
		return no_elemets = true;
	}
	return no_elemets;
}


void print(node* head){

	if (empty(head)==true){
		std::cout << "List is empty"<< std::endl;
	}else
	{
		node *temp = head;

		while (temp!=NULL){
			std::cout << temp->data <<", ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
}


node* InsertHead(node* head, node** tail, int number){

	node *newNode = new node;
	newNode -> data = number;
	newNode -> next = head;
	
	if(empty(head)==true){
		*tail = newNode;
	}else{
		//std::cout << "New 2 " << newNode->data << std::endl;
		//std::cout << "Head 2 " << head->data << std::endl;
		//std::cout << "Tail 2 " << tail->data << std::endl;
	}
	head = newNode;

	std::cout << "Push " << head->data << std::endl;
	//std::cout << "Head " << head->data << std::endl;
	//std::cout << "Tail " << tail->data << std::endl;
	//std::cout << std::endl;
	newNode = NULL;
	delete newNode;

	return head;
}

node* InsertTail(node** head, node* tail, int number){
	node *newNode = new node;
	newNode->data = number;
	newNode->next = NULL;

	if (empty(*head)==true){
		*head = newNode;
		tail = newNode;

		//std::cout << "1New " << newNode->data << std::endl;
		//std::cout << "1Head " << head->data << std::endl;
		//std::cout << "1Tail " << tail->data << std::endl;
	}else{ 
		tail->next = newNode;
		tail = newNode;
		
		//std::cout << "2New " << newNode->data << std::endl;
		//std::cout << "2Head " << head->data << std::endl;
		//std::cout << "2Tail " << tail->data << std::endl;
	}

	std::cout << "Enqueue " << tail->data << std::endl;
	//std::cout << "Head " << head->data << std::endl;
	//std::cout << "Tail " << tail->data << std::endl;
	//std::cout << std::endl;
	newNode = NULL;
	delete newNode;


	return tail;
}

node* DeleteHead(node* head, node** tail){

	//int x;
	//std::cout << "Head " << head->data << std::endl;
	//std::cout << "Tail " << tail->data << std::endl;
	if (empty(head)==true){
		std::cout << "List is empty"<< std::endl;
		//return -1;
		return head;
	}

	//std::cout << "Tail before " << tail << std::endl;
	//std::cout << "Head before " << head << std::endl;

	if (head == *tail){
		//x = head->data;
		std::cout << "Dequeue or Pop " << head->data << std::endl;
		head = NULL;
		*tail = NULL;
		//return x;
		return head;
	}  

	//x = head->data;

	//std::cout << "Value off head " << x << std::endl;
	std::cout << "Dequeue or Pop " << head->data << std::endl;
	//std::cout << "Head Before " << head->data << std::endl;

	head = head->next;

	return head;
}

node* DeleteTail(node** head, node* tail){

	//int x;
	
	if (empty(*head)==true){
		std::cout << "List is empty"<< std::endl;
		//return -1;
		return tail;
	}
	//std::cout << "Tail before " << tail << std::endl;
	//std::cout << "Head before " << head << std::endl;

	if (*head == tail){
		//x = tail->data;
		std::cout << "Off Tail " << tail->data << std::endl;
		head = NULL;
		tail = NULL;
		//return x;
		return tail;
	}  

	node *PrevNode = *head;
	node *delNode = tail;

	//x = tail->data;
	//std::cout << "Value off tail " << x << std::endl;

	while(PrevNode->next != tail){
		PrevNode = PrevNode->next;
	}

	//std::cout << "Prev " << PrevNode->data << std::endl;
	std::cout << "Off Tail " << tail->data << std::endl;

	PrevNode->next = NULL;
	tail = PrevNode;
	//std::cout << "Tail after " << tail->data << std::endl;
	//std::cout << "Head after " << head->data << std::endl;
	//std::cout << std::endl;
	PrevNode = NULL;
	delete PrevNode;
	delNode = NULL;
	delete delNode;
	
	//return x;

	return tail;
}

//Max between max and min
node* removeMaxValue(node* head, node** tail, node* Min, node* Max){
	if (empty(head)==true){
		std::cout << "List is empty"<< std::endl;
		//return -1;
		return head;
	}
	//std::cout << "Tail before " << tail << std::endl;
	//std::cout << "Head before " << head << std::endl;


	int x = 0;
	int posMin = 0;
	int posMax = 0;

	node *temp = head;
	while (temp != NULL){
		x = x + 1;
		if (temp == Min){
			posMin = x;
		}
		if (temp == Max){
			posMax = x;
		}
		temp = temp ->next;
	}

	node* start;
	node* end;

	if (posMax == posMin){
		x = Min->data;
		head = NULL;
		*tail = NULL;
		//return x;
		return head;
	}
	else if (posMax < posMin){
		start = Max;
		end = Min;
	} else {
		start = Min;
		end = Max;
	}

	x = 0;
	node *Prev = start;
	node *maxValue = start->next;
	node *tempPrevMax = start;
	temp = start->next;
	
	while (temp != end){
			
		if (temp->data > maxValue->data){
			maxValue = temp;
			//std::cout << "maxValue " << maxValue->data << std::endl;
			tempPrevMax = Prev;
			//std::cout << "tempPrevMax " << tempPrevMax->data << std::endl;
		}
		Prev = temp;
		//std::cout << "tempPrev " << tempPrev->data << std::endl;
		temp = temp ->next;
		//std::cout << "temp " << temp->data << std::endl;
	}

	tempPrevMax->next = maxValue->next;

	//std::cout << "tempPrevMax " << tempPrevMax->data << std::endl;
	//std::cout << "maxValue " << tempPrevMax->data << std::endl;

	//x = maxValue->data;
	//return x;

	std::cout << "head->data: "<< head->data << std::endl;
	std::cout << "tail->data: "<< (*tail)->data << std::endl;

	return head;
}

//Min between max and min
node* removeMinValue(node* head, node** tail, node* Min, node* Max){
	if (empty(head)==true){
		std::cout << "List is empty"<< std::endl;
		//return -1;
		return head;
	}
	//std::cout << "Tail before " << tail << std::endl;
	//std::cout << "Head before " << head << std::endl;

	int x = 0;
	int posMin = 0;
	int posMax = 0;

	node *temp = head;
	while (temp !=NULL){
		x = x + 1;
		if (temp == Min){
			posMin = x;
		}
		if (temp == Max){
			posMax = x;
		}
		temp = temp ->next;
	}
	//std::cout << "posMin " << posMin << std::endl;
	//std::cout << "posMax " << posMax << std::endl;

	node* start;
	node* end;

	if (posMax == posMin){
		//x = Min->data;
		head = NULL;
		tail = NULL;
		//return x;
		return head;
	}
	else if (posMax < posMin){
		start = Max;
		end = Min;
	} else {
		start = Min;
		end = Max;
	}

	x = 0;

	node *Prev = start;
	node *minValue = start->next;
	node *tempPrevMin = start;
	temp = start->next;
	
	while (temp != end){
			
		if (temp->data < minValue->data){
			minValue = temp;
			//std::cout << "minValue " << minValue->data << std::endl;
			tempPrevMin = Prev;
			//std::cout << "tempPrevMin " << tempPrevMin->data << std::endl;
		}
		Prev = temp;
		//std::cout << "tempPrev " << tempPrev->data << std::endl;
		temp = temp ->next;
		//std::cout << "temp " << temp->data << std::endl;
	}

	tempPrevMin->next = minValue->next;

	//std::cout << "tempPrevMax " << tempPrevMax->data << std::endl;
	//std::cout << "maxValue " << tempPrevMax->data << std::endl;

	//x = minValue->data;
	//return x;

	std::cout << "head->data: "<< head->data << std::endl;
	std::cout << "tail->data: "<< (*tail)->data << std::endl;
	return head;
}

//Middle inside the list between head and tail
node* removeMinMaxValue(node* head, node** tail){

	if (empty(head)==true){
		std::cout << "List is empty"<< std::endl;
	}
	//std::cout << "Tail before " << tail << std::endl;
	//std::cout << "Head before " << head << std::endl;

	if (head == *tail){
		head = NULL;
		tail = NULL;
	}  
	node *minValue = head;
	node *maxValue = head;
	node *temp = head;

	node *Prev = head;
	node *tempPrevMin = head;	
	node *tempPrevMax = head;
	
	while (temp != NULL){

		if (temp->data < minValue->data){
			minValue = temp;
			tempPrevMin = Prev;
			//std::cout << "minValue " << minValue->data << std::endl;
			//std::cout << "tempPrevMin " << tempPrevMin->data << std::endl;
		}
		else if (temp->data > maxValue->data){
			maxValue = temp;
			tempPrevMax = Prev;
			//std::cout << "maxValue " << maxValue->data << std::endl;
			//std::cout << "tempPrevMax " << tempPrevMax->data << std::endl;
		}
		Prev = temp;
		//std::cout << "tempPrev " << tempPrev->data << std::endl;
		temp = temp ->next;
		//std::cout << "temp " << temp->data << std::endl;
	}

	if (minValue == head){
		head = head->next; 
	}
	else if (minValue == *tail){
		tempPrevMin->next = NULL;
		*tail = tempPrevMin;
	}
	else{
		tempPrevMin->next = minValue->next;
	}
	
	if (maxValue == head){
		head = head->next; 
	}else if (maxValue == *tail){
		tempPrevMax->next = NULL;
		*tail = tempPrevMax;
	}else{
		tempPrevMax->next = maxValue->next;
	}
	//std::cout << "tempPrevMax " << tempPrevMax->data << std::endl;
	//std::cout << "maxValue " << tempPrevMax->data << std::endl;
	
	std::cout << "head->data: "<< head->data << std::endl;
	std::cout << "tail->data: "<< (*tail)->data << std::endl;
	return head;
}

node* InsertMiddle(node *head, int val){
	
	node * current = head;
	int counter = 0;
	
	while (current != NULL){
		counter = counter + 1;
		current = current->next;
	}
	
	current = head;
	node * prev;

	for (int i = 0; i <(counter/2); i++){
		prev=current;
		current=current->next;
	}
	
	node * temp = new node;
	temp->data = val;
	temp->next = current;
	prev->next = temp;

	current = NULL, prev= NULL, temp = NULL;

	std::cout << "head->data: "<< head->data << std::endl;

	return head;

}

node* InsertPosition(node* head, int number, int value){
	
	if (list_size(head) < value){
		std::cout << "List is too small" << std::endl;
	}
	else{
		node* temp = head;
		node* prev;

		for (int i = 1; i< value; i++){
			prev = temp;
			temp = temp->next;
		}

		node* newNode =new node;
		newNode->data = number;
		newNode->next = temp;
		prev->next = newNode;
	}

	std::cout << "head->data: "<< head->data << std::endl;

	return head;

}

node* DelPosition(node* head, int value){
	if (empty(head)){
		std::cout << "List is empty" << std::endl;
	}

	else if (list_size(head) < value){
		std::cout << "List is too small" << std::endl;
	}
	else {
		node* temp = head;
		node* prev;

		for (int i = 1; i< value; i++){
			prev = temp;
			temp = temp->next;
		}

		prev->next = temp->next;
	}

	std::cout << "head->data: "<< head->data << std::endl;
	
	return head;
}

node* swapValues (node* head, node** tail, node* a, node* b){
	
	node* temp = head;
	node* prev = head;
	node* PrevA = head;
	node* PrevB = head;

	while (temp != NULL){
		
		if (temp == a){	
			PrevA = prev;
		}
		else if (temp == b){	
			PrevB = prev;
		}
		prev = temp;
		temp = temp->next;
	}

	node* AfterA;
	node* newA = new node;

	node* AfterB;
	node* newB = new node;

	if (head == a && *tail == b){
		//std::cout << "a: "<< a->data << std::endl;	
		//std::cout << "b: "<< b->data << std::endl;
		//std::cout << "PrevB->data: "<< PrevB->data << std::endl;

		head = head->next;
		newA->data = b->data;
		newA->next = head;
		head = newA;
		std::cout << "1. head->data: "<< head->data << std::endl;

		newB->data = a->data;
		newB->next = NULL;
		PrevB->next = newB;
		*tail = newB;
		print(head);
		//std::cout << "tail->data: "<< (*tail)->data << std::endl; 
	}

	
	else if (head == a && !(*tail == b) ){
		AfterB = b->next;
		//std::cout << "a: "<< a->data << std::endl;
		//std::cout << "b: "<< b->data << std::endl;
		//std::cout << "PrevB->data: "<< PrevB->data << std::endl;
		//std::cout << "AfterB->data: "<< AfterB->data << std::endl;

		newB->data = a->data;
		newB->next = AfterB;
		PrevB->next = newB;

		head = head->next;
		newA->data = b->data;
		newA->next = head;
		head = newA;
		
		std::cout << "2. head->data: "<< head->data << std::endl;
		print(head);
	}

	else if (*tail == b && !(head == a)){
		AfterA = a->next;

		//std::cout << "a: "<< a->data << std::endl;
		//std::cout << "PrevA->data: "<< PrevA->data << std::endl;
		//std::cout << "AfterA->data: "<< AfterA->data << std::endl;
	
		//std::cout << "b: "<< b->data << std::endl;
		//std::cout << "PrevB->data: "<< PrevB->data << std::endl;
		
		newA->data = b->data;
		newA->next = AfterA;
		PrevA->next = newA;

		newB->data = a->data;
		newB->next = NULL;
		PrevB->next = newB;
		*tail = newB;
		std::cout << "3. tail->data: "<< (*tail)->data << std::endl; 
		print(head);	
	}

	else {

		AfterA = a->next;
		AfterB = b->next;

		//std::cout << "a: "<< a->data << std::endl;
		//std::cout << "PrevA->data: "<< PrevA->data << std::endl;
		//std::cout << "AfterA->data: "<< AfterA->data << std::endl;
	
		//std::cout << "b: "<< b->data << std::endl;
		//std::cout << "PrevB->data: "<< PrevB->data << std::endl;
		//std::cout << "AfterB->data: "<< AfterB->data << std::endl;

		newA->data = b->data;
		newA->next = AfterA;
		PrevA->next = newA;
		std::cout << "Last.4"<< std::endl;
	
		newB->data = a->data;
		newB->next = AfterB;
		PrevB->next = newB;
		print(head);

	}
	
	//std::cout << "newA->data: "<< newA->data << std::endl;	
	//std::cout << "newB->data: "<< newB->data << std::endl;
	//std::cout << "head->data: "<< head->data << std::endl;
	//std::cout << "tail->data: "<< (*tail)->data << std::endl;

	return head;
}

int main ()
{
	node *head = NULL;
	node *tail = NULL;
	//int x;
	head = InsertHead(head, &tail, 44);
	tail = InsertTail(&head, tail, 51);
	head = InsertHead(head, &tail, 13);
	tail = InsertTail(&head, tail, 62);
	head = InsertHead(head, &tail, 2);
	tail = InsertTail(&head, tail, 27);
	head = InsertHead(head, &tail, 19);
	tail = InsertTail(&head, tail, 8);
	
	print(head);

	tail = DeleteTail(&head, tail);
	print(head);

	head = DeleteHead(head, &tail);
	print(head);

	tail = DeleteTail(&head, tail);
	print(head);

	head = DeleteHead(head, &tail);
	print(head);

	node *p4, *p7;

	for(int i = 1; i < 10; i++) {
		head = InsertHead(head, &tail,i);
		if (i==4) p4 = head;
		if (i==7) p7 = head;
	}
	print(head);

	removeMinValue(head, &tail,p4, p7);
	std::cout << "Remove Min val head p4 to p7: "<< head->data << std::endl;
	print(head);

	std::cout << "Remove Max and Min."<< std::endl;
	removeMinMaxValue(head, &tail);
	print(head);

	for(int i = 9; i > 0; i--) {
		tail = InsertTail(&head, tail,i);
		if (i==1) p4 = tail;
		if (i==9) p7 = tail;
	}
	print(head);

	p4 =head->next;
	p7 =p4->next;
	p7 =p7->next;
	p7 =p7->next;

	removeMaxValue(head, &tail, p4, p7);
	std::cout << "Remove Max val tail p4 to p7: "<< head->data << std::endl;
	print(head);

	std::cout << "Remove Max and Min."<< std::endl;
	removeMinMaxValue(head, &tail);
	print(head);

	std::cout << "Insert 200 the middle"<< std::endl;
	head = InsertMiddle(head, 200);
	print(head);

	std::cout << "Insert 100 Pos 9 Count from 1"<< std::endl;
	head = InsertPosition(head, 100, 9);
	print(head);

	std::cout << "Remove Pos 12 Count from 1"<< std::endl;
	head = DelPosition(head, 12);
	print(head);

	/*std::cout << "Swap head and tail"<< std::endl;
	head = swapValues(head, &tail, head, tail);
	
	std::cout << "Swap head+1 and head+3"<< std::endl;
	head = swapValues(head, &tail, p4, p7);

	std::cout << "Swap head and p7"<< std::endl;
	head = swapValues(head, &tail, head, p7);

	std::cout << "Swap p4 and tail"<< std::endl;
	head = swapValues(head, &tail, p4, tail);*/

	head = ReverseList(head);
	print(head);

	return 0;
}

