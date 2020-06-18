#include<iostream>
using namespace std;

/* General instructions: Please modify this file and submit the modified one
   via svn and then websubmission (under the entry "pracExam"). No design
   documents or header files are needed. You only need to submit one file, 
   which is this one.

   This exam is marked out of 10 marks and is worth 20% of your overall marks.
*/

struct Node {
    int data;
    Node* next;
};

int list_size(Node* head){

  int sizeL = 0;
  Node* temp = head;

  while (temp != NULL){
    sizeL = sizeL +1;
    temp = temp->next;
  }

  temp=NULL;
  delete temp;

  return sizeL;
}

void printNode(Node* head){
  Node* temp = head;

  while (temp != NULL){
    std::cout << temp->data << ", ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

/* Task 1: Implement the following function for adding a new node to the 
   front of the given list with double the given value.

   input   Nodes* head: a head pointer to a list
           int val: an integer that represent a value. 

   return  the head pointer of the new list after the insertion

   Example: add a node with given value 9
            before  HEAD->1->2->3->NULL
            after   HEAD->18->1->2->3->NULL

   3 marks(1 for style, 2 for functionality)

*/

Node* addDouble(Node* head, int val){

  int valdouble = val*2;

  Node *newNode = new Node;
  newNode->data = valdouble;
  newNode->next = head;
  head = newNode;
  return head;

}

/* Task 2: Implement the following function for deleting the elements in
   the even position of the given list. Assume the head node is in position 1.

   input   Nodes* head: a head pointer to a list

   return  void
          
   output  The list after the deletion

   Example: input    HEAD->1->2->3->9->12->NULL
            output   HEAD->1->3->12->NULL

   3 marks(1 for style, 2 for functionality)
*/

void clearEven(Node* head){

  Node* temp = head->next;
  Node* prev = head;

  int size = list_size(head);

  for (int i = 1; i< size; i++){
    
    if (i % 2 != 0){
       prev->next = temp->next;
    }

    prev = temp;
    temp = temp->next;
  }

}

/* Task 3: Implement the following function for printing the node with value
   greater than the threshold between Node n1 and Node n2.

   input   Nodes* n1: a pointer to a node in a list
           Nodes* n2: a pointer to a node in the same list
	   int threshold: a given value as threshold

   return  void

   Example: input   n1 points to the 1st node 
                    n2 points to the 5th node
		    val = 2

            before  HEAD->1->2->3->9->12->NULL

            output  F->3->9
	    (1 is smaller than 2)
           ------------------------------------ 
	    input   n1 points to the 7th node
                    n2 points to the 2nd node
		    val = 4

            before  HEAD->2->8->9->1->4->7->12->NULL

            output  9->F->F->7
	    (1 and 4 are not greater than 4)

   4 marks(1 for style, 3 for functionality)
*/

void printSeg(Node* n1, Node* n2, int val){

  Node* current = n1->next;
  
    while ( current != n2 )
  {
    if (current->data > val){
        std::cout << current -> data;
    }  
    else
    {
      std::cout << "F";
    }
    
    if (current->next != n2) std::cout << "->" ;
    current = current->next;
  }
  std::cout << std::endl ;
}

// You are not supposed to change the main function
int main() {

    Node* head = NULL;
    Node *p3, *p7;

    for(int i = 1; i < 10; i++) {
        head = addDouble(head, i);
        if (i==3) p3 = head;
        if (i==7) p7 = head;
    }

    // at this point, we have created the following list: HEAD->18->16->14->12->10->8->6->4->2->NULL
    // p3 now points to the node containing 6); p7 now points to the node containing 14)

    clearEven(head);
    // The resulting list is HEAD->18->14->10->6->2->NULL

    //You can uncomment this line to test.
    //the output should be: 10 
    //Please remember to comment this line out before submitting 
    //printSeg(p3, p7, 0);

    head = addDouble(head, 16);
    head = addDouble(head, 20);
    // at this point, the list is: HEAD->40->32->18->14->10->6->2->NULL

    clearEven(p7);
    //In the list starting for p7, there are 4 nodes.
    //remove nodes 10 and 2.
    //The list after the function call is: HEAD->20->16->18->14->6->NULL
    
    


    printSeg(head, p3, 15);
    // the output should be: 16->18->F


    // free all nodes
    Node* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
  
}