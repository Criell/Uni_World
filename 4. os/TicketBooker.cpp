#ifndef TICKETBOOKER_H
#define TICKETBOOKER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

class TicketBooker
{
  public:
    
    struct customer {
       char Customer_ID[256]; 
       int Arrival_Time;
       int Priority;
       int Age;
       int Customer_Run;

       int Max_Tickets;
       int Tickets_Required;
       
       int Ready_Time;
       int Time_Quantum_Units;
       int End_Time;

       int New_Flag;
       int Waiting_Time; 
    };

    struct node {
      customer element;
      struct node *next;
    };

    struct queue {
      int length;
      node *head;
      node *tail;
    };

    struct pointer_node {
      struct node *next;
      struct node *p_tail;
      struct node *p_last;

    };

    TicketBooker(char *av){
      q1.length = 0;
      q1.tail = NULL;
      q1.head = NULL;
        
      q2.length = 0;
      q2.tail = NULL;
      q2.head = NULL;

      q1_pointer.next = NULL;
      q1_pointer.p_tail = NULL;
      q1_pointer.p_last = NULL;

      Output.length = 0;
      Output.tail = NULL;
      Output.head = NULL;
      Quantum_Time = -1;
      Quantum_Time_Q1 = 0;
      Quantum_Time_Q2 = 0;
      filename = av;
      std::ifstream file (filename);
      std::string line;
      Number_Customers = 0;
      while( getline(file, line)){   
        Number_Customers++;
      } 
      Read_Input();
      check = new int [Number_Customers];
      for (int i = 0; i < Number_Customers; i++){
        check[i] = 1;  
      }
    }
    ~TicketBooker(){}

    /********************* QUEUE *********************************/  
    void enqueuePriority(queue *q, customer *p);
    void enqueue(queue *q, customer *p);
    void enqueueOUT(customer *p);
    void circularQueue(queue *q);
    int circularValidation();
    void circularQueueHead();
    void circularQ1DemotedHeadQueue();
    void circularQueuePriority();
    void dequeue(queue *q);
    void dequeuePosQueue(queue *q,customer *p);

    /********************* INPUT *********************************/  
    void QuotaN_Tickets(customer *process);
    void Read_Input();
    void Add_Customer_Q1();
    void Control_Add_Customer_Q1();
    void Add_Customer_Q2();
    void Control_Add_Customer_Q2();
    void Add_Priority(customer *p);
    void Add_Age(node *current);
    int Checking_Process();
    void First_Run(customer *p);
    void Add_Wait(node *current);
    void Last_Run(queue *q,customer *p);
    void Run_Red(customer *p);
    void Run_NonRed(customer *p);
    void One_Ticket(customer *p);
    void One_Run_Q1(customer *p);
    void Run_Output(queue *q);
    void Promoted(node *current);
    /********************* PRINT *********************************/
    void PrintArray();
    void PrintProcess(customer p);
    void printIDqueue1();
    void printIDqueue2();
    void PrintTrack();
    void PrintOutput();
    
    int Quantum_Time;
    int Number_Customers;
    int *check;
    int Quantum_Time_Q1;
    int Quantum_Time_Q2;
    std::vector<customer> all_customers;
    queue q1;
    queue q2;
    queue Output;
    pointer_node q1_pointer;
    char* filename;
};

#endif // TICKETBOOKER_H

//1 = false. 0 = true

/********************* INPUT *********************************/  

void TicketBooker::QuotaN_Tickets(customer *p){
  int time = 0;
  if (p->Priority > 3) {
      time = 100;
  } else {
      time = (8 - p->Priority) * 10;
  }
  p->Max_Tickets = time/5;
}

void TicketBooker::Read_Input(){
  std::ifstream file (filename);
  std::string line;

  char *ID;
  char sbuf[256];
  char buf[4][256];
  
  for (int i = 0; i < Number_Customers; i++){
    getline(file, line);
    char *ID;
    ID = strtok( &line[0], " ");
    strcpy(sbuf, ID);
    int n = 0;
    while( (ID = strtok (NULL, " ")) != NULL ){
        strcpy(buf[n], ID);
        n++;
    }
    customer temp;
    strcpy(temp.Customer_ID, sbuf);
    temp.Arrival_Time = atoi(buf[0]);
    temp.Priority = atoi(buf[1]);
    temp.Customer_Run = 0;
    temp.Age = atoi(buf[2]);

    QuotaN_Tickets(&temp);
    temp.Tickets_Required = atoi(buf[3]); 
    
    temp.Ready_Time = -1;
    temp.Time_Quantum_Units = 0;  
    temp.End_Time = 0;

    temp.New_Flag = 1;    
    temp.Waiting_Time = 0;
    
    all_customers.push_back(temp);
  }
}

/********************* PRINT *********************************/  
void TicketBooker::printIDqueue1(){
  if (q1.head != NULL){ 
    printf("ID\t\tP\tAT\t\tTick  MaxT  Quantum\t  CR   New\tWait\n");
    node *p = q1.head;
    while(p != NULL) {
      printf("%s", p->element.Customer_ID);
      printf("\t\t%i", p->element.Priority);
      printf("\t%i", p->element.Arrival_Time);
      printf("   \t%i", p->element.Tickets_Required);
      printf("\t\t%i", p->element.Max_Tickets);
      printf("\t\t%i", p->element.Time_Quantum_Units);
      printf("\t\t%i", p->element.Customer_Run);
      //printf("\t\t%i", p->element.New_Flag);
      //printf("\t%i", p->element.Waiting_Time);
      printf("\n");
      p = p->next;
    }
  }
}

void TicketBooker::printIDqueue2() {
  if (q2.head != NULL){ 
    printf("ID\t\tP\tAT\t\tTick  MaxT  Quantum\t  Age   New\tWait\n");
    node *p = q2.head;
    while(p != NULL) {
      printf("%s", p->element.Customer_ID);
      printf("\t\t%i", p->element.Priority);
      printf("\t%i", p->element.Arrival_Time);
      printf("   \t%i", p->element.Tickets_Required);
      printf("\t\t%i", p->element.Max_Tickets);
      printf("\t\t%i", p->element.Time_Quantum_Units);
      printf("\t\t%i", p->element.Age);
      //printf("\t\t%i", p->element.New_Flag);
      //printf("\t%i", p->element.Waiting_Time);
      printf("\n");
      p = p->next;
    }
  }
}

void TicketBooker::PrintTrack(){
    printf(" ************************* TIME: %i **********\n", Quantum_Time);
    printIDqueue1();
    printIDqueue2();
}

void TicketBooker::PrintOutput(){
  if (Output.head != NULL){ 
    printf("name   arrival   end   ready   running   waiting\n");  
    node *p = Output.head;
    while(p != NULL) {
      printf("%s", p->element.Customer_ID);
      printf("   \t%i", p->element.Arrival_Time);
      printf("   \t%i", p->element.End_Time);
      printf("   \t%i", p->element.Ready_Time);
      printf("   \t%i", p->element.Time_Quantum_Units);
      printf("   \t%i\n", p->element.Waiting_Time);
      p = p->next;
    }
  }
}

void TicketBooker::PrintArray(){
  for (int i = 0; i < all_customers.size(); i++){
    std::cout << all_customers.at(i).Customer_ID << " - ";
    std::cout << all_customers.at(i).Arrival_Time << " - ";
    std::cout << all_customers.at(i).Priority << std::endl;  
  }
  std::cout << std::endl; 
}

/********************* ENQUEUE *********************************/  
void TicketBooker::enqueuePriority(queue *q, customer *p){
  node *temp = new node;
  temp->element = *p;
  temp->next = NULL;
  
  //if (q1.head != NULL)
    //std::cout <<"HEAD "<< q1.head->element.Customer_ID<<" - "<< q1.head->element.Priority<<std::endl;
  //std::cout <<"ADD  "<< p->Customer_ID<<" - "<< p->Priority<<std::endl;

  if (q->head == NULL){
    q->head = temp;
    q->tail = temp;
    //std::cout <<" ** Q1 ADD NULL "<< std::endl;
  }
  else if (q->head == q->tail) 
  {
        if (q->head->element.Priority <= temp->element.Priority)
        {
          q->tail->next = temp;
          q->tail = temp;
          //std::cout <<" ** Q1 ADD to tail +++++ "<< std::endl;
        } 
        else {
          temp->next = q->head;
          q->head = temp;
          //std::cout <<" ** Q1 ADD to head ------"<< std::endl;
        }
  } else if (temp->element.Priority < q->head->element.Priority) 
  {
      temp->next = q->head;
      q->head = temp;
      //std::cout <<" ** Q1 ADD HEAD "<< std::endl;
  }  
  else {
    node* current = q->head;
    node* prev = q->head;

    while(current != NULL && current->element.Priority <= p->Priority){
      prev = current;
      current = current->next;
    }

    if (prev != NULL)
      //std::cout <<" prev "<< prev->element.Customer_ID<< std::endl;
    
    if (prev == q->tail){
      q->tail->next = temp;
      q->tail = temp;
      //std::cout <<" ** Q1 ADD 1111 "<< std::endl;
    } 
    else { 
      prev->next = temp;
      temp->next = current;
      //std::cout <<" ** Q1 ADD 2222 "<< std::endl;
    }
    
    prev = NULL;
    current = NULL;
    delete prev;
    delete current;                  
  } 

  q->length ++;
  temp = NULL;
  delete temp;
}

int TicketBooker::circularValidation(){
    int flag = 0;
    if (q1_pointer.next != NULL &&  q1_pointer.next->next != NULL){
      if (q1_pointer.next->element.Priority == q1_pointer.next->next->element.Priority){  
        flag = 1;
      } 
      else {
        node* prev = q1_pointer.next;
        node* current = q1_pointer.next->next;
        
        while(current != NULL){
          if (prev->element.Priority > current->element.Priority){
            flag = 2;
          }   
          prev = current;
          current = current->next;
        }
      }
    }
    return flag;
}

void TicketBooker::circularQ1DemotedHeadQueue(){
  if (q1_pointer.next->element.Priority > q1_pointer.next->next->element.Priority) { 
    node *temp = new node;
    temp->element = q1_pointer.next->element;
    temp->next = NULL;

    q1.head = q1_pointer.next->next;
    q1.tail->next = temp;
    q1.tail = temp;

    temp = NULL;
    delete temp;
  }
}

void TicketBooker::circularQueueHead(){
  node *temp = new node;
  temp->element = q1_pointer.next->element;
  temp->next = NULL;

  node* prev = q1_pointer.next;
  node* current = q1_pointer.next->next;
        
  while(current != NULL && current->element.Priority <= q1_pointer.next->element.Priority){   
      prev = current;
      current = current->next;
  }

    //if (q1.head != NULL)
      //std::cout <<"head             : "<< q1.head->element.Customer_ID<<std::endl;
    //if (q1_pointer.next != NULL)
      //std::cout <<"q1_pointer.next  : "<< q1_pointer.next->element.Customer_ID<<std::endl;
    //if (prev != NULL)
      //std::cout <<"prev             : "<< prev->element.Customer_ID<<std::endl;
    //if (current != NULL)
      //std::cout <<"current          : "<< current->element.Customer_ID<<std::endl;
    //if (q1_pointer.p_tail != NULL)
      //std::cout <<"q1_pointer.p_tail: "<< q1_pointer.p_tail->element.Customer_ID<<std::endl;
    //if (q1.tail != NULL)
      //std::cout <<"tail             : "<< q1.tail->element.Customer_ID<<std::endl;
 
  if (q1_pointer.next == q1_pointer.p_tail && prev->element.Priority != q1_pointer.next->element.Priority){
  }
  else if (q1.head->next == q1.tail && q1.head != q1_pointer.next){
  }
  else if (q1.head->next == q1.tail && q1.head->element.Priority == q1.tail->element.Priority) { 
    q1.tail->next = temp;
    q1.tail = temp;
    q1.head = q1.head->next;
    //std::cout <<" ** Q1 Head 1111 "<< std::endl;
  } else {
    if (q1.head == q1_pointer.next){
      q1.head = q1.head->next; 
      //std::cout <<" ** Q1 Head 2222 "<< std::endl; 
      //std::cout <<q1.head->element.Customer_ID<< std::endl;
    }
    else {
      q1.head->next = q1.head->next->next;
      //std::cout <<" ** Q1 Head 3333 "<< std::endl;
      //std::cout <<q1.head->element.Customer_ID<< std::endl;
    }

    if (prev == q1.tail){
        q1.tail->next = temp;
        q1.tail = temp;
        //std::cout <<" ** Q1 tail 2222 "<< std::endl;
        //std::cout <<q1.tail->element.Customer_ID<< std::endl;
    } 
    else { 
        prev->next = temp;
        temp->next = current;
        //std::cout <<" ** Q1 tail 3333 "<< std::endl;
        //std::cout <<q1.tail->element.Customer_ID<< std::endl;
    } 
    prev = NULL;
    current = NULL;
    delete prev;
    delete current;
  }
  temp = NULL;
  delete temp; 
}

void TicketBooker::circularQueuePriority(){
  if (q1.head == NULL) { 
  }
  else{
    int flag;
    if (flag = circularValidation()){
      //std::cout <<"Flag: "<< flag << std::endl;
      if (flag == 2){
          //std::cout <<" ** Q1 DEMOTED HEAD PRIORITY 3 "<< std::endl;
          circularQ1DemotedHeadQueue();
      } else { 
          //std::cout <<" ** Q1 CIRCULAR HEAD  "<< std::endl;
          circularQueueHead();
      }
    }
  }
  //PrintTrack();
}

void TicketBooker::Add_Customer_Q2() {
  for (int i = 0; i < all_customers.size(); i++){
    if (all_customers.at(i).Priority > 3 && check[i] == 1) {
      if (all_customers.at(i).Arrival_Time == Quantum_Time_Q2 ){
        check[i] = 0;
        enqueue(&q2, &all_customers.at(i));
      }
    }
  }
}

void TicketBooker::Control_Add_Customer_Q2() {
  int counter = Quantum_Time - Quantum_Time_Q2+1;
  for (int i = 0; i < counter; i++){
    Add_Customer_Q2();
    Quantum_Time_Q2++;
  }
}

void TicketBooker::Add_Customer_Q1() {
  for (int i = 0; i < all_customers.size(); i++){
    if (all_customers.at(i).Priority < 4  && check[i] == 1) {
      if (all_customers.at(i).Arrival_Time == Quantum_Time_Q1){
        check[i] = 0;
        enqueuePriority(&q1, &all_customers.at(i));
      } 
    }
  }
}

void TicketBooker::Control_Add_Customer_Q1() {
  int counter = Quantum_Time - Quantum_Time_Q1 +1;
  for (int i = 0; i < counter; i++){
    Add_Customer_Q1();
    Quantum_Time_Q1++;
  }
}

/********************* QUEUE *********************************/ 

void TicketBooker::enqueue(queue *q, customer *p){  
  
  node *temp = new node;
  temp->element = *p;
  temp->next = NULL;
  if (q->head == NULL){
    q->head = temp;
    q->tail = temp;
    //std::cout <<" ** Q2 NULL "<< std::endl;
  } else{
    //std::cout <<p->Customer_ID<< std::endl;
    q->tail->next = temp;
    q->tail = temp;
    //std::cout <<" ** Q2 +++++ "<< std::endl;
  }
  q->length ++;
  temp = NULL;
  delete temp;

  //PrintTrack();
}

void TicketBooker::enqueueOUT(customer *p){  
  p->End_Time = Quantum_Time;

  node *temp = new node;
  temp->element = *p;
  temp->next = NULL;
  if (Output.head == NULL){
    Output.head = temp;
    Output.tail = temp;
  } else{
    Output.tail->next = temp;
    Output.tail = temp;
  }
  Output.length ++;
  temp = NULL;
  delete temp;
}
  
void TicketBooker::dequeue(queue *q){
  if (q->head == NULL){
  }
  else if (q->head == q->tail){
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
  } 
  else { 
    node *temp = q->head->next;
    q->head = temp;
    temp = NULL;
    delete temp;
    q->length--;
  }
}

void TicketBooker::dequeuePosQueue(queue *q, customer *p){
  if (q->head == NULL){ } else if (q->head == q->tail){
    dequeue(q);
  } 
  else if (p->Customer_ID == q->head->element.Customer_ID){
    dequeue(q);
  }
  else if (q->head->next->next == q->tail && p->Customer_ID == q->head->next->element.Customer_ID){
      q->head->next = q->tail;
  }
  else {
    node* current = q->head;
    node* prev;
    while(current != NULL && p->Customer_ID != current->element.Customer_ID){   
          prev = current;
          current = current->next;
    }
    if (current == q->tail){
        prev->next = NULL;
        q->tail = prev;
    } else{ 
      prev->next = current->next;                   
    }
    current = NULL;
    delete current;
  }
}

void TicketBooker::circularQueue(queue *q){
  if (q->head == NULL) { 
  }
  else {
    node *temp = new node;
    temp->element = q->head->element;
    temp->next = NULL;

    node *newtail = temp;
    q->tail->next = newtail;
    q->tail = newtail;
    q->head = q->head->next;

    temp = NULL;
    delete temp;
  } 
}

/********************* ADD PROCESS *********************************/  
int TicketBooker::Checking_Process(){
  int sum = 0;
  for (int i = 0; i < Number_Customers; i++){
    sum = sum + check[i];  
  }

  int end_run = 1;
  if (sum == 0 && q1.head == NULL && q2.head == NULL){
    end_run = 0;
  }
  return end_run;
}

void TicketBooker::First_Run(customer *p){         
    if (p->New_Flag == 1){
      p->New_Flag = 0;
      p->Ready_Time = Quantum_Time;
    } 
}

void TicketBooker::Add_Wait(node *current){
    while(current != NULL){
      if (current->element.New_Flag == 0)
        current->element.Waiting_Time++;
      current = current->next;
    }
}

void TicketBooker::Add_Priority(customer *p){
  if (p->Customer_Run < 2){
      p->Customer_Run++;
    }
    else if (p->Customer_Run == 2){
      p->Priority++;
      p->Customer_Run = 0;
    }
}

void TicketBooker::Add_Age(node *current){
  if (current == NULL){ }
  else {
    while(current != NULL) {
      if (current->element.Age < 7){
          current->element.Age++;
      }
      else if (current->element.Age == 7){
          current->element.Priority--;
          current->element.Age = 0;
        
      }
      current = current->next;
    }
  }
}

void TicketBooker::Promoted(node *current){
  if (current == NULL){ 
  } 
  else {
    while(current != NULL) {
      if (current->element.Priority == 3){
          QuotaN_Tickets(&current->element);
          enqueuePriority(&q1, &current->element);
          dequeuePosQueue(&q2, &current->element);
      }
      current = current->next;
    }
  }
}

void TicketBooker::Last_Run(queue *q, customer *p){  
  if (p->Tickets_Required == 0){  
    enqueueOUT(p);
    dequeue(q);
  }
}

void TicketBooker::One_Ticket(customer *p){     
  for (int i=0; i<5; i++){
    Quantum_Time++; 
    p->Time_Quantum_Units++;

    if (q1.head == NULL){
      Add_Wait(q2.head->next);
    } else {
      Add_Wait(q1.head->next);
      Add_Wait(q2.head);
    }
    
    if (i == 4){
      p->Tickets_Required--;
      p->Max_Tickets--;
    }
  }
}

void TicketBooker::One_Run_Q1(customer *p){
  int Max = p->Max_Tickets;
  for (int i=0; i< Max; i++){
    if (p->Tickets_Required > 0)
      One_Ticket(p);
    else
      i = Max;
  }

  Add_Priority(p);
  //std::cout <<" ** ADD PRIORITY RED: "<< std::endl;
  //PrintTrack();

  Add_Age(q2.head);
  //std::cout <<" ** ADD AGE RED BY Q1: "<< std::endl;
  //PrintTrack();
}

void TicketBooker::Run_Red(customer *p){         
    //std::cout <<" ** RUN_RED : "<<q1.head->element.Customer_ID << " - "<<q1.tail->element.Customer_ID << std::endl;
    One_Run_Q1(p);

    if (p->Tickets_Required == 0){
      Last_Run(&q1, &q1.head->element);
      //std::cout <<" ** RUN OUT RED: "<< std::endl;
      //PrintOutput(); 
    } else {
      q1_pointer.next = q1.head;
      q1_pointer.p_tail = q1.head;
      q1_pointer.p_last = q1.head;
        
      while(q1_pointer.p_last != NULL && q1_pointer.p_last->element.Priority <= q1_pointer.next->element.Priority ){   
        q1_pointer.p_tail = q1_pointer.p_last;
        q1_pointer.p_last = q1_pointer.p_last->next;
      }

      //std::cout <<"q1_pointer.p_tail: "<< q1_pointer.p_tail->element.Customer_ID<<std::endl;
      //if (q1_pointer.p_last != NULL)
        //std::cout <<"q1_pointer.p_last:  "<< q1_pointer.p_last->element.Customer_ID<<std::endl;  
    }

    Control_Add_Customer_Q1();
    //std::cout <<" ** ADD CUSTOMER RED Q1: "<< std::endl;
   
    Control_Add_Customer_Q2();
    //std::cout <<" ** ADD CUSTOMER RED Q2: "<< std::endl;
    //PrintTrack();

    if (p->Max_Tickets == 0 && p->Tickets_Required > 0) {
      
      if (p->Priority == 4){
        p->Customer_Run = 0;
        QuotaN_Tickets(p);
        enqueue(&q2, p);
        dequeuePosQueue(&q1, p);
        //std::cout <<" ** DEMOTED 4 RED: "<< std::endl;
        //PrintTrack();
      } 
      else {
        QuotaN_Tickets(p);
        circularQueuePriority();
        //std::cout <<" ** CIRCULAR PRIORITY RED: "<< std::endl;
        //PrintTrack();
      }

      Promoted(q2.head);
      //std::cout <<" ** PROMOTED RED: "<< std::endl;
      //PrintTrack();
    }
}

void TicketBooker::Run_NonRed(customer *p){      
    //std::cout << " ** RUN_NON_RED: "<<q2.head->element.Customer_ID << " - "<<q2.tail->element.Customer_ID << std::endl;
    if (p->Tickets_Required > 0 && p->Max_Tickets > 0){
      One_Ticket(p);
    }

    Control_Add_Customer_Q1();
    //std::cout <<" ** ADD CUSTOMER RN Q1: "<< std::endl;
    //PrintTrack();

    Promoted(q2.head);
    //std::cout <<" ** PROMOTED RN: "<< std::endl;
    //PrintTrack();

    if (p->Tickets_Required == 0){
      p->Age = 0;
      Add_Age(q2.head->next);
      //std::cout <<" ** ADD AGE RN BY Q2 RUN OUT: "<< std::endl;
      //PrintTrack();

      Last_Run(&q2, &q2.head->element);
      //std::cout <<" ** RUN OUT RN: "<< std::endl;
      //PrintOutput();
    } 
    else if (q1.head != NULL){
      p->Age = 0;
      Add_Age(q2.head->next);
      //std::cout <<" ** ADD AGE RN BY Q2 INTERRUPT: "<< std::endl;
      //PrintTrack();

      QuotaN_Tickets(p);
      circularQueue(&q2);
      //std::cout <<" ** CIRCULAR RN Q2 INTERRUPT: "<< std::endl;
      //PrintTrack(); 
    }
    else if (p->Max_Tickets == 0 && p->Tickets_Required > 0) {
      p->Age = 0;
      Add_Age(q2.head->next);
      //std::cout <<" ** ADD AGE RN BY Q2: "<< std::endl;
      //PrintTrack();

      if (q2.head->next != NULL){
        QuotaN_Tickets(p);
        circularQueue(&q2);
        //std::cout <<" ** CIRCULAR RN Q2: "<< std::endl;
        //PrintTrack();
      } else {
        QuotaN_Tickets(p);
      }
    }

    Control_Add_Customer_Q2();
    //std::cout <<" ** ADD CUSTOMER RN Q2: "<< std::endl;
    //PrintTrack();
} 

int main(int ac, char **av)
{
  TicketBooker system(av[1]);
  int running;
  while(running = system.Checking_Process()){
    if (system.q1.head !=NULL){
        system.First_Run(&system.q1.head->element);
        system.Run_Red(&system.q1.head->element);
    } 
    else if (system.q2.head !=NULL){
        system.First_Run(&system.q2.head->element);        
        system.Run_NonRed(&system.q2.head->element);
    } 
    else {
      system.Quantum_Time++;
      system.Control_Add_Customer_Q1();
      system.Control_Add_Customer_Q2();
      //if (system.Quantum_Time == 0)
        //system.PrintArray();
    }
    //system.PrintTrack();
  }
  system.PrintOutput();
  
  return 0;
}