#include<iostream>
using namespace std;

/* General instructions: Please modify this file and submit the modified one
   via svn and then websubmission (under the entry "pracExam"). No design
   documents or header files are needed. You only need to submit one file, 
   which is this one.

   This exam is marked out of 10 marks and is worth 20% of your overall marks.
   You need at least 4/10 to pass the hurdle requirement.
*/

struct Node {
	int data;
	Node* next;
};


/* Task 1: Implement the following function for adding a new node to the 
   front of the given list.

   input   Nodes* head: a head pointer to a list
		   int val: an integer that represent the value of the new
					node
   return  the head pointer of the new list after the insertion

   Example: add a node of value 9
			before  HEAD->1->2->3->NULL
			after   HEAD->9->1->2->3->NULL

   3 marks(1 for style, 2 for functionality)

*/

Node* add(Node* head, int val){
  Node * temp;
  temp =  new Node;
  temp->data = val;
  temp->next = head;

  head = temp;

  temp = NULL;
  return head;
}

/* Task 2: Implement the following function for printing the even elements
   in the given list.

   input   Nodes* head: a head pointer to a list

   return  void
		  
   output  The even elements in the given list

   Example: input    HEAD->1->2->3->9->12->NULL
			output   HEAD->ODD->2->ODD->ODD->12->NULL

   3 marks(1 for style, 2 for functionality)
*/

void printEven(Node* head){
  Node* current = head;
  cout << "HEAD";

  while ( current != NULL )
  {
		if (current->data % 2 == 0){
			cout << "->" << current -> data;
		}	 else
		{
			cout << "->" << "ODD";
		}
		
		current = current->next;
  }
  cout << "->NULL"<< endl;

}

/* Task 3: Implement the following unction for deleting the node with the
   minimum value between Node n1 and Node n2.

   input   Nodes* n1: a pointer to a node in a list
		   Nodes* n2: a pointer to a node in the same list

   return  the node got removed which has the minimum value between the two
		   given nodes.

   Example: input   n1 points to node 1
					n2 points to node 4

			before  HEAD->1->2->3->9->12->NULL

			after   HEAD->1->3->9->12->NULL

   4 marks(1 for style, 3 for functionality)
*/

Node* removeMin(Node* n1, Node* n2){
  Node* current = n2;
  Node* min = n2;
  Node* previous = n2;
  Node* previousToMin = n2;
  
  while ( current != n1 )
  {
		if (current->data < min->data){
			min = current;
			previousToMin = previous;
		}	
		
		previous = current;
		current = current->next;
  }

  previousToMin->next = min->next;

  return min;
}

// You are not supposed to change the main function
int main() {

	Node* head = NULL;
	Node *p4, *p7;

	for(int i = 1; i < 10; i++) {
		head = add(head, i);
		if (i==4) p4 = head;
		if (i==7) p7 = head;
	}
	// at this point, we have created the following list: HEAD->9->8->7->6->5->4->3->2->1->NULL
	// p4 now points to node 4 (the node containing 4); p7 now points to node 7 (the node containing 7)

	removeMin(p4, p7);
  
	// between p4 and p7, there are 2 nodes. The minimum node is node 5.
	// The resulting list is HEAD->9->8->7->6->4->3->2->1->NULL

	//You can uncomment this line to test.
	//the output should be: HEAD->ODD->8->ODD->6->4->ODD->2->ODD->NULL
	//Please remember to comment this line out before submitting 
	// printEven(head);

	head = add(head, 16);
	head = add(head, 20);
	// at this point, the list is: HEAD->20->16->9->8->7->6->4->3->2->1->NULL


	removeMin(p7, head);
	printEven(head);
	
	/****
	// between p7 and head, there are 3 nodes (16, 9 and 8). The minimum node is node 8
	// the output should be: HEAD->20->16->ODD->ODD->6->4->ODD->2->ODD->NULL
*/

	// free all nodes
	Node* tmp;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
	return 0;
  
}
