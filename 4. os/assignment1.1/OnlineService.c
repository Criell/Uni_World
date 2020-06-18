#include	<stdio.h>
#include  <stdlib.h>
#include	<unistd.h>
#include	<string.h>


//1 = false. 0 = true

typedef struct runprocess
{
   char customerID[256]; 
   int ArrivalT;
   int Priority;
   int Ini_CPU_Time;
   int CPU_Time;
   int MaxQUnits;
   int NumUnits;
   int QUnitsCounter;
   int boolStart;
   int Ready;
   int LastHead;   
   int DustCounter;
   int Waiting; 
   int Age;
   int EndT; 
} RunProcess;

typedef struct Node {
  RunProcess element;
  struct Node *next;
} node; 

typedef struct Queue {
  int length;
  node *head;
  node *tail;
} queue; 

/********************* PRINT *********************************/  

void PrintProcess(RunProcess p){
  printf("    Index Prior ArrivalT EndT Ready CPU_Time Waiting boolStart MaxQUnits NumUnits QUnitsCounter Age DustCounter\n");
  printf("    %s\t\t", p.customerID);
  printf("%i\t\t", p.Priority);
  printf("%i\t\t", p.ArrivalT);
  printf("%i\t", p.EndT);
  printf("%i\t\t", p.Ready);
  printf("%i\t\t", p.CPU_Time);
  printf("%i\t\t", p.Waiting);
  printf("%i\t\t\t", p.boolStart);
  printf("%i\t\t\t", p.MaxQUnits);
  printf("%i\t\t\t", p.NumUnits);
  printf("%i\t", p.QUnitsCounter);
  printf("%i\t", p.Age);
  printf("%i\n", p.DustCounter);
}

void printIDqueue(queue *q) {
  printf("ID Pri Arri Ready CPU Time LHead MaxU Units UCount Age Dust\n");
  node *printqueue = q->head;
  while(printqueue != NULL) {
      printf("%s\t", printqueue->element.customerID);
      printf("%i  ", printqueue->element.Priority);
      printf("%i\t", printqueue->element.ArrivalT);
      printf("%i\t\t", printqueue->element.Ready);
      printf("%i\t", printqueue->element.Ini_CPU_Time);
      printf("%i\t", printqueue->element.CPU_Time);
      printf("%i\t\t", printqueue->element.LastHead);
      printf("%i\t", printqueue->element.MaxQUnits);
      printf("%i\t", printqueue->element.NumUnits);
      printf("%i\t\t", printqueue->element.QUnitsCounter);
      printf("%i\t", printqueue->element.Age);
      printf("%i\n", printqueue->element.DustCounter);
      printqueue = printqueue->next;
  }
}

void printQueue(queue q, FILE *fp) {
  node *current = q.head;
  while(current != NULL) {
    fprintf(fp, "%s\t", current->element.customerID);
    fprintf(fp, "%i\t", current->element.ArrivalT);
    fprintf(fp, "%i\t", current->element.Priority);
    fprintf(fp, "%i\t", current->element.Age);
    fprintf(fp, "%i\t", current->element.CPU_Time);
    fprintf(fp, "%i\t", current->element.MaxQUnits);
    fprintf(fp, "%i\t", current->element.NumUnits);
    fprintf(fp, "%i\n", current->element.QUnitsCounter);
    current = current->next;
  }
  //fprintf(fp, "Head: %s\t\t", q.head->element.customerID);
  //fprintf(fp, "Tail: %s\t\n", q.tail->element.customerID);
}

//Testing
void PrintRunning(int Qtime, queue Q1, queue Q1low, queue Q2, queue Q3, FILE *fp){
  fprintf(fp, "%s\n", "***************************");
  fprintf(fp, "The last moment of Time(%i)\n", Qtime);
  fprintf(fp, "%s\n", "This is Queue 1:");
  fprintf(fp, "%s\n", "Ind A Prio Age CPU Max Unit Counter");
  printQueue(Q1, fp);
  printQueue(Q1low, fp);
    
  fprintf(fp, "%s\n", "This is Queue 2:");
  fprintf(fp, "%s\n", "Ind A Prio Age CPU Max Unit Counter");
  printQueue(Q2, fp);
    
  fprintf(fp, "%s\n", "This is Queue 3:");
  fprintf(fp, "%s\n", "Ind A Prio Age CPU Max Unit Counter");
  printQueue(Q3, fp);

  /**
  fprintf(fp, "____________________________\n");
  if (Q1.head != NULL)
    fprintf(fp, " P1  Head Counter: %i\n", Q1.head->element.CPU_Time);
  if (Q1low.head != NULL) 
    fprintf(fp, " P1l Head Counter: %i\n", Q1low.head->element.CPU_Time);
  if (Q2.head != NULL)
    fprintf(fp, " P2  Head Counter: %i\n", Q2.head->element.CPU_Time);
  if (Q3.head != NULL)
    fprintf(fp, " P3  Head Counter: %i\n", Q3.head->element.CPU_Time); 
  **/
}

void PrintOutput(queue q, FILE *fp){  
  printf("Index\tPriority\tArrival\tEnd\tReady\tCPU_Time\tWaiting\n");
  node *current = q.head;
  while(current != NULL) {
    //Output customerID  Priority   ArrivalT   EndT   Ready   CPU_Time   Waitings
    //      1           6      0        35     0        20      15
    printf("%s\t", current->element.customerID);
    printf("%i\t", current->element.Priority);
    printf("%i\t", current->element.ArrivalT);
    printf("%i\t", current->element.EndT);
    printf("%i\t", current->element.Ready);
    printf("%i\t", current->element.Ini_CPU_Time);
    printf("%i\n", current->element.Waiting);
    current = current->next;
  }
}

/********************* QUEUE *********************************/  
void startQueue(queue *q) {
  q->length = 0;
  q->tail = NULL;
  q->head = NULL;
}

int empty(queue q){
  node *temp = q.head;
  if (q.head == NULL){
    return 0;
  }
  temp = NULL;
  free(temp);
  return 1; 
}

int list_size(queue q){
  if (q.head == NULL){
    return 0;
  }
  else
    return q.length;
}
  
void dequeue(queue *q){
  if (q->head == NULL){
  } else if (q->head == q->tail ){
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
  } else{ 
    node *temp = q->head->next;
    q->head = temp;
    temp = NULL;
    free(temp);
    q->length--;
  }
}

void circularqueue(queue *q){
  if (q->head == NULL) {
  } else if (q->head == q->tail) {
  } else { 
    node *newtail = malloc(sizeof(node));
    newtail -> element = q->head->element;
    newtail -> next = NULL;
    q->tail->next = newtail;
    q->tail = newtail;
    newtail = NULL;
    free(newtail);

    node *temp = q->head->next;
    q->head = temp;
    temp = NULL;
    free(temp);
  }
}

void delPosQueue(RunProcess *p, queue* q){
  if (q->head == NULL){
  } 
  else if (q->head == q->tail){
    dequeue(q);
  } 
  else if (p->customerID == q->head->element.customerID){
    dequeue(q);
  }
  else if (q->head->next->next == q->tail && p->customerID == q->head->next->element.customerID){
      q->head->next = q->tail;
  }
  else {
    node* temp = q->head;
    node* prev;
    while(temp != NULL && p->customerID != temp->element.customerID){   
          prev = temp;
          temp = temp->next;
    }
    if (temp == q->tail){
        prev->next = NULL;
        q->tail = prev;
    } else 
      prev->next = temp->next;                   
  }
}

void enqueue(queue *q, RunProcess process){
  node *temp = malloc(sizeof(node));
  temp -> element = process;
  temp -> next = NULL;
  if (q->head == NULL){
    q->head = temp;
    q->tail = temp;
  } else{
    q->tail->next = temp;
    q->tail = temp;
  }
  q->length ++;
  temp = NULL;
  free(temp);
}

/********************* INPUT *********************************/  
void newUnits(RunProcess *process){
  switch(process->Priority) {
      case 6 :  process->MaxQUnits = 5; 
                process->NumUnits = 5;
                break;
      case 5 :  process->MaxQUnits = 5;
                process->NumUnits = 5; 
                break;
      case 4 :  process->MaxQUnits = 10;
                process->NumUnits = 2; 
                break;
      case 3 :  process->MaxQUnits = 10; 
                process->NumUnits = 2;
                break;
      case 2 :  process->MaxQUnits = 20;
                process->NumUnits = process->CPU_Time; 
                break;
      case 1 :  process->MaxQUnits = 20; 
                process->NumUnits = process->CPU_Time;
                break;
  }
}

int SizeInput(char* filename){
  char *nlines = NULL;
  size_t l = 0;
  FILE *inputfp = fopen (filename , "r");
  int counter = 0;
  while( getline(&nlines, &l, inputfp) != EOF ){   
    counter++;
  } 
  fclose(inputfp);
  return counter;
}

void ReadInput(RunProcess temp[], int size, char * filename){
  char *lines[size];
  size_t l = 0;
  FILE *inputfp = fopen (filename,"r");
  char *ID;
  char sbuf[256];
  char buf[4][256];
  
  int i;
  for (i = 0; i < size; i++){
    lines[i] = NULL;
    getline(&lines[i], &l, inputfp);
    ID = strtok (lines[i], " ");
    strcpy(sbuf, ID); 
    int n = 0;
    while( (ID = strtok (NULL, " ")) != NULL ){
        strcpy(buf[n], ID);
        n++;
    }
    strcpy(temp[i].customerID, sbuf);
    temp[i].ArrivalT = atoi(buf[0]);
    temp[i].Priority = atoi(buf[1]);
    temp[i].Ini_CPU_Time = atoi(buf[3]);  
    temp[i].CPU_Time = atoi(buf[3]); 
    newUnits(&temp[i]);
    temp[i].QUnitsCounter = 0;
    temp[i].boolStart = 1;
    temp[i].Ready = -1;
    temp[i].LastHead = 0;   
    temp[i].DustCounter = 0;
    temp[i].Waiting = 0; 
    temp[i].Age = atoi(buf[2]);
    temp[i].EndT = 0; 
  }
}

/********************* ADD PROCESS *********************************/  
void Prior(RunProcess *p, queue* p1, queue* p1l, queue* p2, queue* p3) {
  switch(p->Priority) {
      case 6 :  enqueue(p1, *p); break;
      case 5 :  enqueue(p1l, *p); break;
      case 4 :  enqueue(p2, *p); break;
      case 3 :  enqueue(p2, *p); break;
      case 2 :  enqueue(p3, *p); break;
      case 1 :  enqueue(p3, *p); break;
    } 
}

void addProcess(RunProcess inp[], int Pcounter, int Tcounter, queue* p1, queue* p1l, queue* p2, queue* p3){
  int j;
  for (j = 0; j < Pcounter; j++){
    if (inp[j].ArrivalT == Tcounter){
        Prior(&inp[j], p1, p1l, p2, p3);              
    }
  }
}

/********************* TIME 1 PROCESS *********************************/ 
void GiveUnits(queue* q){
  if (q->head == NULL){
  }
  else if (q->head->element.QUnitsCounter < q->head->element.MaxQUnits){
      q->head->element.QUnitsCounter++;
  }
  else if (q->head->element.QUnitsCounter == q->head->element.MaxQUnits){
    q->head->element.LastHead = 0;
    //When no more Units Reset variables
    q->head->element.QUnitsCounter = 0;

    //Send to the tail of the list
      if (q->head->element.NumUnits > 0){
        q->head->element.NumUnits--;
      }
  }   
}

void ReadyFlag (RunProcess * p, int time){
  if (p->boolStart == 1){
      p->boolStart = 0;
      p->Ready = time;
  }
  
}


void prom(queue* p2, queue* p3){
  node *current2 = p2->head;
  node *current3 = p3->head;

  while(current2 != NULL) {
    if (current2->element.LastHead == 1){
        //Send to the tail of the list
        if (current2->element.NumUnits > 0){
            //When no more Units Reset variables
            current2->element.QUnitsCounter = 0;
            current2->element.LastHead = 0;
            current2->element.NumUnits--;
            printf("prom Circular %s\n", current2->element.customerID);
            circularqueue(p2);
        } 
      }
    current2 = current2->next;
  }

  while(current3 != NULL) {
    if (current3->element.LastHead == 1){
        //Send to the tail of the list
        if (current3->element.NumUnits > 0){
            //When no more Units Reset variables
            current3->element.QUnitsCounter = 0;
            current3->element.LastHead = 0;
            current3->element.NumUnits--;
            printf("prom Circular %s\n", current3->element.customerID);
            circularqueue(p3);
        } 
    }
    current3 = current3->next;
  }
}


void SuddenAge(RunProcess *p, queue* q, int time, queue* o, queue* p1, queue* p1l, queue* p2, queue* p3){
  if (p1->head != NULL){
    prom(p2, p3);
  } 
  else if (p1l->head != NULL){
    prom(p2, p3);
  }

  ReadyFlag(p, time);
  int end = time + 1;
  int run = p->Ready;
  int cpu = p->Ini_CPU_Time;
  p->EndT = end;
  p->Waiting = end - (run + cpu);
  enqueue(o, *p);
  dequeue(q);


  //INCREASE WAITING AND AGE others process in the queues != firts
  node *current2 = p2->head;
  node *current3 = p3->head;

  if (p1->head != NULL){
  } 
  else if (p1l->head != NULL){
  }  
  else if (p2->head != NULL){
    current2 = p2->head->next;
  }
  else if (p3->head != NULL){
    current3 = p3->head->next;
  }
  
  while(current2 != NULL) {
    if (current2->element.Age < 8){
      current2->element.Age = current2->element.Age + 1;
      current2->element.DustCounter = 0;
    }
    current2 = current2->next;
  }

  while(current3 != NULL) {
    if (current3->element.Age < 8){
      current3->element.Age = current3->element.Age + 1;
      current3->element.DustCounter = 0;
    }
    current3 = current3->next;
  }
}

void GiveTime(queue* p1, queue* p1l, queue* p2, queue* p3, int time, queue* o) {
    printf("Give Time %i\n", time);
    node *current = NULL;
    queue *current_queue = NULL;
    if (p1->head != NULL){
     current_queue = p1;
     current = p1->head;
     prom(p2, p3);
    } 
    else if (p1l->head != NULL){
     current_queue = p1l;
     current = p1l->head;
     prom(p2, p3);
    } 
    else if (p2->head != NULL){
     current_queue = p2;
     current = p2->head;
    }
    else if (p3->head != NULL){
      current_queue = p3;
      current = p3->head;
    }

    //Give time and Reset Variables
  
    current->element.CPU_Time--;   
    current->element.Age = 0;
    current->element.DustCounter = 0;
    //printf("If first boolStart = 0 then Ready=i and boolStart = 1!\n" ); //Ready
    ReadyFlag(&current->element, time);
    GiveUnits(current_queue);
}

/********************* INCREASE VARIABLES ALL PROCESS *****************************/
void Dusting(RunProcess *p){   

  //if process not in queue 1, DustCounter++ until 5
  if (p->DustCounter < 4 & p->Priority < 5){
      p->DustCounter++;
  }
  //if DustCounter = 5, Age++ until 7 and reset DustCounter = 0
  else if (p->Age < 8 & p->Priority < 5){    
    p->Age++;
    p->DustCounter = 0;  
  }

}

void Increase(queue* p1, queue* p1l, queue* p2, queue* p3){
  printf("Increase\n");
  if (p1->head == NULL && p1l->head == NULL && p2->head == NULL && p3->head == NULL){
  }
  else { 
    //INCREASE WAITING AND AGE others process in the queues != firts
    node *current2 = p2->head;
    node *current3 = p3->head;

    if (p1->head != NULL){
    } 
    else if (p1l->head != NULL){
    }  
    else if (p2->head != NULL){
      current2 = p2->head->next;
    }
    else if (p3->head != NULL){
      current3 = p3->head->next;
    }
  
    while(current2 != NULL) {
      Dusting(&current2->element);
      current2 = current2->next;
    }

    while(current3 != NULL) {
      Dusting(&current3->element);
      current3 = current3->next;
    }
  }
}

/*************************** DEMOTE *********************************/


void Circular(queue* p1, queue* p1l, queue* p2, queue* p3){
  if (p1->head == NULL && p1l->head == NULL && p2->head == NULL && p3->head == NULL){
  }
  else { 
    node *current = NULL;
    queue *current_queue = NULL;
    if (p1->head != NULL){
      current_queue = p1;
      current = p1->head;
    } 
    else if (p1l->head != NULL){
      current_queue = p1l;
      current = p1l->head;
    } 
    else if (p2->head != NULL){
      current_queue = p2;
      current = p2->head;
    }
    else if (p3->head != NULL){
      current_queue = p3;
      current = p3->head;
    } 
    if (current->element.NumUnits < 0 && current->element.QUnitsCounter == current->element.MaxQUnits){ 
      circularqueue(current_queue);
    }
  }
}

void Demote(queue* p1, queue* p1l, queue* p2, queue* p3){ 
  if (p1->head == NULL && p1l->head == NULL && p2->head == NULL && p3->head == NULL){
  }
  else { 

    node *current = NULL;
    queue *current_queue = NULL;
    if (p1->head != NULL){
        current_queue = p1;
        current = p1->head;
    } 
    else if (p1l->head != NULL){
        current_queue = p1l;
        current = p1l->head;
    } 
    else if (p2->head != NULL){
        current_queue = p2;
        current = p2->head;
    }
    else if (p3->head != NULL){
      current_queue = p3;
      current = p3->head;
    } 
    

    if (current->element.NumUnits == 1 && current->element.QUnitsCounter == current->element.MaxQUnits){   
        printf("Demote %s\n", current->element.customerID);
        printf("Units %i\n", current->element.NumUnits);
        printf("Counter %i\n", current->element.QUnitsCounter);
        //Only decrese process priorities 2,3,4 y 5
        if (current->element.Priority > 2){
            current->element.LastHead = 0;
            //Move process from high queue to lower 
            switch(current->element.Priority) {
              case 6 :  current->element.Priority--;
                        newUnits (&current->element);
                        enqueue(p1l, current->element);
                        dequeue(current_queue); 
                        break;
              case 5 :  current->element.Priority--;
                        newUnits (&current->element);
                        enqueue(p2, current->element);
                        dequeue(current_queue); 
                        break;
              case 4 :  current->element.Priority--;
                        newUnits (&current->element);
                        break;
              case 3 :  current->element.Priority--;
                        newUnits (&current->element);
                        enqueue(p3, current->element);
                        dequeue(current_queue); 
                        break;
            }
        }
    }
  }
}   

/*************************** PROMOTE *********************************/

void MoveQ(RunProcess *p, queue* p1l, queue* p2, queue* p3){
  if (p == NULL){

  } 
  //Age = 7 and not Queue 1, move high Queue"
  else if (p->Age == 8) {
      //p->LastHead = 0;
      p->Age = 0;
      switch(p->Priority) {
          case 4 :  p->Priority++;
                    newUnits(p); enqueue(p1l, *p); 
                    delPosQueue(p, p2); 
                    break;
          case 3 :  p->Priority++;
                    break;
          case 2 :  p->Priority++;
                    newUnits(p); enqueue(p2, *p); 
                    delPosQueue(p, p3);
                    break;
          case 1 :  p->Priority++; 
                    break;
        }
      }
    
}

void Upgrade(queue* q, queue* p1l, queue* p2, queue* p3){
    //INCREASE WAITING AND AGE others process in the queues != firts
    node *current = q->head;

    while(current != NULL) {
    //if (current->element.QUnitsCounter == current->element.MaxQUnits)
      //Degrade(q, p1l, p2, p3);
    //else
      MoveQ(&current->element, p1l, p2, p3);
      current = current->next;
    }    
}

int main(int ac, char **av)
{
  int Pcounter = SizeInput(av[1]);
	RunProcess inp[Pcounter];
  ReadInput (inp, Pcounter, av[1]);
  queue p1;
  startQueue(&p1); 
  queue p1l; 
  startQueue(&p1l); 
  queue p2;
  startQueue(&p2);
  queue p3;
  startQueue(&p3);
  queue OutPut;
  startQueue(&OutPut);

  //MAIN LOOP
  FILE *fp = fopen ("execution.txt","w");

  int Tcounter = 0;
  int running = 1;
  RunProcess* current = NULL;
  RunProcess* initial = NULL;
  RunProcess* later = NULL;
  queue* current_queue = NULL; 

  while (running){

    addProcess(inp, Pcounter,Tcounter, &p1, &p1l, &p2, &p3);
    if (p1.head == NULL && p1l.head == NULL && p2.head == NULL && p3.head == NULL){
        break;
    }

    if (p1.head != NULL){
      initial = &p1.head->element;
    } 
    else if (p1l.head != NULL){
      initial = &p1l.head->element;
    }  
    else if (p2.head != NULL){
      initial = &p2.head->element;
    }
    else if (p3.head != NULL){
      initial = &p3.head->element;
    }

    Demote(&p1, &p1l, &p2, &p3);

    if (p1.head != NULL){
      later = &p1.head->element;
    } 
    else if (p1l.head != NULL){
      later = &p1l.head->element;
    }  
    else if (p2.head != NULL){
      later = &p2.head->element;
    }
    else if (p3.head != NULL){
      later = &p3.head->element;
    }

    if (initial == later){
      printf("Circular %s\n", initial->customerID);

      Circular(&p1, &p1l, &p2, &p3);
    }
    Upgrade(&p2, &p1l, &p2, &p3);
    Upgrade(&p3, &p1l, &p2, &p3);    

    if (p1.head != NULL){
      p1.head->element.LastHead = 1;
      current = &p1.head->element;
      current_queue = &p1;
    } 
    else if (p1l.head != NULL){
      p1l.head->element.LastHead = 1;
      current = &p1l.head->element;
      current_queue = &p1l;
    }  
    else if (p2.head != NULL){
      p2.head->element.LastHead = 1;
      current = &p2.head->element;
      current_queue = &p2;
    }
    else if (p3.head != NULL){
      p3.head->element.LastHead = 1;
      current = &p3.head->element;
      current_queue = &p3;
    }
    
    PrintRunning(Tcounter, p1, p1l, p2, p3, fp);
    
  
    //if (Tcounter > 101){
      printf("************ TIME: %i ************\n", Tcounter);
      printf("P1\n");
      printIDqueue(&p1);
      printf("P1l\n");
      printIDqueue(&p1l);
      printf("P2\n");
      printIDqueue(&p2);
      printf("P3\n");
      printIDqueue(&p3);
    //}
    

    if (current->CPU_Time > 1){
      GiveTime(&p1, &p1l, &p2, &p3, Tcounter, &OutPut); 
      Increase(&p1, &p1l, &p2, &p3); 
    } else {
      SuddenAge(current, current_queue, Tcounter, &OutPut, &p1, &p1l, &p2, &p3);
    } 

    Tcounter++;
  }

  
	PrintOutput(OutPut, fp);
  fclose(fp);

	return 0;
}