#ifndef PAGEREPLACEMENT_H
#define PAGEREPLACEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>

int mode_print = 0;

class PageReplacement
{
  public:
    
    
    struct bit {
      int reference;
      struct bit *bit_next;
    };

    struct page {
       std::string Mode;
       int Dirty;
       int Number;
       int Frame_Time;
       int Bit_DecNumber;
       bit *bit_head;
       bit *bit_tail;
       int Counter;
       std::vector <int> Total_Counter;
    };

    struct node {
      int node_ID;
      page frame_page;
      struct node *next;
    };

    struct win {
      int reference;
      page *win_page;
      struct win *win_next;
    };

    struct frame {
      int size;
      int taken_size;
      int time;
      node *head;
      node *tail;
      node *next_victim;
      int bit_size;
      int bit_interval;
      int bit_time;
      win *win_head;
      win *win_tail;
      int win_size;
      int Counter_Index;
    };

    int Events_Trace;
    int Total_Disk_Reads;
    int Total_Disk_Writes;
    int Page_Faults;
    char* filename;
    int Number_pages;
    std::vector<page> all_pages;
    frame f;
    std::string Hit_Miss; 
    int Prev_Victim;


    int Dec_Numbers(char Hex_Number[], int s);
    void Dec_Bit(page *p);
    void Add_Head_Frame();
    void Add_frame();
    void Set_Write(page *p);
    void Set_Miss(page *p);
    void Set_HitMiss(page *p);
    void ReferBit(page *p);
    void CounterBit(page *p);
    void FIFO_Victim();
    int LRU_Victim();
    int ARB_Victim(page *p);
    std::vector<int> WSARB_Victim(page *p);
    void LRU_Fix_Order(page *p);
    void FIFO();
    void LRU();
    void ARB();
    void WSARB();
    /********************* frame *********************************/  
    void enqueueDequeue(page *p);
    void enqueue(page *p);
    void dequeue();
    void bit_enqueue(page *p);
    void bit_set(page *p, int n);
    void bit_circular(page *p, int n);
    void bit_circularFrame();
    void bit_circularWin();
    void counter_DecBit(page *p);
    void counter_clean(page *p); 
    void counter_enqueue(page *p);
    void counter_set(page *p);
    void counter_window(page *p);
    void win_enqueue(page *p);
    void win_enqueueDequeuePos(page *p);
    win* win_findOld(page *p);
    void win_ReferCounterBit(page *p);
    void win_CircularOld(win *old, page *p);
    page* win_getOldPage(page *p);
    void win_CleanPage(int prev_victim);
    /********************* PRINT *********************************/
    void PrintArray();
    void printFrame(page *p);
    void PrintOutput();
    void PrintFrameBit(page *p);
    void PrintPageBit(page *p);
    void PrintFrameWin();
    

/********************* INPUT *********************************/  
    
    void Read_Input(int size){
      std::ifstream file (filename);
      std::string line;
      int counter = 0;
      getline(file, line);
      Number_pages--;
      char *page_info;
      char Number[8];
      char buf_Number[256];

      for (int i = 0; i < Number_pages; i++){
        page temp;
        getline(file, line);
        page_info = strtok( &line[0], " ");
        temp.Mode = page_info;
        if ( (page_info = strtok (NULL, " ")) != NULL) {
          strcpy(buf_Number, page_info); 
        }
        temp.Number = Dec_Numbers(buf_Number, size);
        temp.Dirty = 0;
        temp.Frame_Time = 0;
        temp.Bit_DecNumber = 0;
        temp.Counter = -1;
        temp.bit_head = NULL;
        temp.bit_tail = NULL;

        counter++;
        all_pages.push_back(temp); 
      }
    }

    PageReplacement(char *av, char *av_size, char *av_frame){
      Events_Trace = 0;
      Total_Disk_Reads = 0;
      Total_Disk_Writes = 0;
      Page_Faults = 0;
      Hit_Miss = "OTHER";
      Prev_Victim = -1;
      filename = av;
      std::ifstream file (filename);
      std::string line;
      Number_pages = 0;
      while( getline(file, line)){   
        Number_pages++;
      } 
      int size = atoi(av_size);
      f.taken_size = 0;
      Read_Input(size);
      int frame = atoi(av_frame);
      f.size = frame;
      f.time = 0;
      f.tail = NULL;
      f.head = NULL;
      f.next_victim = NULL;
      f.bit_size = 0;
      f.bit_interval = 0;
      f.bit_time = 0;
      f.win_size = 0;
      f.Counter_Index = 0;
      f.win_head = NULL;
      f.win_tail = NULL;
      
      //PrintArray();
    }
    ~PageReplacement(){}  
};

#endif // PAGEREPLACEMENT_H

/********************* PRINT *********************************/  
void PageReplacement::PrintOutput(){
  printf("events in trace:    %i\n", Events_Trace);
  printf("total disk reads:   %i\n", Total_Disk_Reads);
  printf("total disk writes:  %i\n", Total_Disk_Writes);
  printf("page faults:        %i\n", Page_Faults);
}

void PageReplacement::PrintArray(){
  printf("Mode\tPage#\n");
  for (int i = 0; i < all_pages.size(); i++){
    std::cout << all_pages.at(i).Mode << " - ";
    std::cout << all_pages.at(i).Number << std::endl;
  }
}

void PageReplacement::printFrame(page *page){
  printf("******************TIME %i***************\n", f.time); 
  printf("POINTER FRAME: %i", f.next_victim->frame_page.Number);
  printf("\tHIT/MISS: %s\n", Hit_Miss.c_str());
  printf("REPLACE PAGE: %i", Prev_Victim);
  printf("\t\tADD PAGE#: %i\n", page->Number);
  printf("Mode\tDirty?\tPage#\tTime\n");
  node *p = f.head;
  while(p != NULL) {
    printf("%s", p->frame_page.Mode.c_str());
    printf("\t%i", p->frame_page.Dirty);
    printf("\t%i", p->frame_page.Number);
    printf("\t%i", p->frame_page.Frame_Time);
    printf("\n");
    p = p->next;
  }
  printf("\n");
}

void PageReplacement::PrintPageBit(page *p){
  printf("*********************FRAME TIME %i - Int %i ***********\n", f.time,f.bit_time); 
  printf("Mode\tDirty?\tPage#\tTime\tDEC\tBIT\n");
  printf("%s\t", p->Mode.c_str());
  printf("%i\t", p->Dirty);
  printf("%i\t", p->Number);
  printf("%i\t", p->Frame_Time);
  printf("%i\t", p->Bit_DecNumber);
  bit *current = p->bit_head;
  while (current != NULL){
      std::cout << current->reference << " ";
      current = current->bit_next;
  }
  printf("\n");
}

void PageReplacement::PrintFrameBit(page *page){
  printf("************** TIME %i - Int %i ***************\n", f.time,f.bit_time); 
  printf("HIT/MISS: %s", Hit_Miss.c_str());
  printf("\tADD page#: %i", page->Number);
  printf("\tREPLACE page#: %i\n", Prev_Victim);
  //printf("Mode\tDirty?\tPAGE#\tTIME\tBIT\t\tDEC\tWIN_COUNTER\tCOUNTER\n");
  printf("PAGE#\tTime\tDEC#\tCOUNTER\t\tWIN_COUNTER\n");
  
  node *p = f.head;
  while(p != NULL) {
    //printf("%s\t", p->frame_page.Mode.c_str());
    // (p->frame_page.Mode == "W"){printf("Yeah\t");}
    //else {printf("\t");}

    printf("%i\t", p->frame_page.Number);
    printf("%i\t", p->frame_page.Frame_Time);
    printf("%i\t", p->frame_page.Bit_DecNumber);
    printf("%i\t\t", p->frame_page.Counter);
    /**
    bit *current = p->frame_page.bit_head;
    while (current != NULL){
      std::cout << current->reference << " ";
      current = current->bit_next;
    }
    **/
    for (int i = 0; i < p->frame_page.Total_Counter.size(); i++){
        printf("%i ", p->frame_page.Total_Counter.at(i));
    }
    
    printf("\n");
    p = p->next;
  }
  printf("\n");
}

void PageReplacement::PrintFrameWin(){
  
  printf("******* WINDOW (%i) TIME %i - Int %i/%i *********\n", f.win_size , f.time,f.bit_time, f.bit_size); 
  //printf("Mode\tREF\tPAGE#:\tTIME\tBIT\t\tDEC\tWIN_COUNTER\tCOUNTER\n");
  printf("PAGE#\tTime\tDEC\tCOUNTER\t\tWIN_COUNTER\n");
  
  win *current = f.win_head;
  while (current != NULL){
    if (current->win_page != NULL){
      //printf("%s\t", current->win_page->Mode.c_str());
      //printf("%i\t", current->reference);
      printf("%i\t", current->win_page->Number);
      printf("%i\t", current->win_page->Frame_Time);
      //bit *current_bit = current->win_page->bit_head;
      //while (current_bit != NULL){
      //  std::cout << current_bit->reference << " ";
      //  current_bit = current_bit->bit_next;
      //}
      printf("%i\t", current->win_page->Bit_DecNumber);
      printf("%i\t\t", current->win_page->Counter);
      for (int i = 0; i < current->win_page->Total_Counter.size(); i++){
        printf("%i ", current->win_page->Total_Counter.at(i));
      }
      
      std::cout << std::endl;
    }
    current = current->win_next;
  }
}

/********************* INPUT *********************************/  
int PageReplacement::Dec_Numbers(char Hex_Number[], int s){
  int Dec_Number = 0;
  int Base = 1; 
  for (int i = 7; i >= 0; i--) {    
    if (Hex_Number[i]>='0' && Hex_Number[i]<='9') { 
        Dec_Number = Dec_Number + (Hex_Number[i] - 48) * Base; 
        Base = Base * 16; 
    } else if (Hex_Number[i]>='a' && Hex_Number[i]<='f'){ 
        Dec_Number += (Hex_Number[i] - 87)*Base; 
        Base = Base*16; 
    }
  } 
  Dec_Number = Dec_Number / s; 
  return Dec_Number;
} 

void PageReplacement::Add_Head_Frame(){
  all_pages.at(0).Frame_Time = f.time;
  if ((std::string(all_pages.at(0).Mode) == "W")){
      all_pages.at(0).Dirty = 1;  
  }
  enqueue(&all_pages.at(0));
  Events_Trace++;
  Page_Faults++;
  Total_Disk_Reads++;
  f.next_victim = f.head;
}

void PageReplacement::Set_Miss(page *p){
    Page_Faults++;
    Total_Disk_Reads++;
}

void PageReplacement::Set_Write(page *p){
  if ((std::string(p->Mode) == "W")){
      p->Dirty = 1;
  }
  
  if (p->Dirty == 1){
      Total_Disk_Writes++;
      p->Dirty = 0;
      if (mode_print > 1){
        printf("Victim: %i - Total Disk Writes: %i\n", p->Number, Total_Disk_Writes);
      }
  }
}

void PageReplacement::Set_HitMiss(page *p){
    int flag = 0;
    node* current = f.head;
    page* hit_page;
    while(current != NULL){
      if (p->Number == current->frame_page.Number){
        if ((std::string(p->Mode) == "W")){
          current->frame_page.Mode = "W";
        }
        Prev_Victim = -1;
        Hit_Miss = "HIT";
        flag = 1;    
      }
      current = current->next;
    }

    if (flag != 1){
      Hit_Miss = "MISS";
    } 
}

/********************* MOVE PAGES ON FRAME *********************************/  
void PageReplacement::Add_frame(){
  //printf("f.size: %i - f.taken_size: %i\n", f.size, f.taken_size); 
  if (f.taken_size < f.size){
    f.taken_size++;
  }
}

void PageReplacement::enqueue(page *p){  
  node *temp = new node;
  temp->frame_page = *p;
  temp->next = NULL;
  
  if (f.head == NULL){
    f.head = temp;
    f.tail = temp;

  } else if (f.head == f.tail){
    f.head->next = temp;
    f.tail = temp;
  } else {
    f.tail->next = temp;
    f.tail = temp;

    temp = NULL;
    delete temp;
  }
  Add_frame();
}
  
void PageReplacement::dequeue(){
  if (f.head == NULL){
  } else { 
    node *temp = f.head->next;
    f.head = temp;
    temp = NULL;
    delete temp;
  }
}

void PageReplacement::enqueueDequeue(page *p){
  node *temp = new node;
  temp->frame_page = *p;
  temp->next = NULL;
   
  if (f.next_victim->next == f.tail){
      f.next_victim->next = temp;
      f.tail = temp;
  } 
  else {
      node *current = f.next_victim->next->next; 
      f.next_victim->next = current;
      f.tail->next = temp;
      f.tail = temp;
      current = NULL;
      delete current;
  }              
  temp = NULL;
  delete temp;
}

/********************* FIFO *********************************/ 
void PageReplacement::FIFO_Victim(){
    int min = f.head->frame_page.Frame_Time;    
    f.next_victim = f.head;
    node* current = f.head;
    while(current->next != NULL){
      if (min > current->next->frame_page.Frame_Time){
          min = current->next->frame_page.Frame_Time;
          f.next_victim = current;
      }
      current = current->next;
    }
}

void PageReplacement::FIFO(){
  f.time++;
  Add_Head_Frame();
  //printFrame(&all_pages.at(0));
  for (int i = 1; i < Number_pages; i++){
    f.time++;
    Events_Trace++;
    Set_HitMiss(&all_pages.at(i));
    
    if (Hit_Miss == "MISS") {
      Set_Miss(&all_pages.at(i));

      all_pages.at(i).Frame_Time = f.time;

      FIFO_Victim();

      if (f.next_victim == f.head){
        Prev_Victim = f.next_victim->frame_page.Number;
        
        if (f.taken_size == f.size){
          Set_Write(&f.next_victim->frame_page);
          dequeue();
        }
        enqueue(&all_pages.at(i));
      } else {
        Prev_Victim = f.next_victim->next->frame_page.Number;
        Set_Write(&f.next_victim->next->frame_page);
        enqueueDequeue(&all_pages.at(i));
      }
    }
    //printFrame(&all_pages.at(i));
  }
}

/********************* LRU *********************************/ 

int PageReplacement::LRU_Victim(){
    node* current = f.head;
    current = f.head;
    while(current != NULL){
        current->frame_page.Frame_Time++;  
        current = current->next;
    }
    int max = f.head->frame_page.Frame_Time;    
    f.next_victim = f.head;
    current = f.head;
    while(current->next != NULL){
      if (max < current->next->frame_page.Frame_Time){
          max = current->next->frame_page.Frame_Time;
          f.next_victim = current;
      }
      current = current->next;
    }
    return max;
}

void PageReplacement::LRU_Fix_Order(page *p){
  int max = 0;
      node* hit_node = NULL;
      node* current = f.head;
      while(current != NULL){
        if (p->Number == current->frame_page.Number){ 
          max = current->frame_page.Frame_Time;
          hit_node = current;    
        }
        current = current->next;
      }
      current = f.head;
      while(current != NULL){
        if (current->frame_page.Frame_Time < max) 
            current->frame_page.Frame_Time++;    
        current = current->next;
      }
      hit_node->frame_page.Frame_Time = 0;
}

void PageReplacement::LRU(){
  f.time++; 
  Add_Head_Frame();
  if (mode_print == 3){
      printFrame(&all_pages.at(0)); 
  }
  for (int i = 1; i < Number_pages; i++){ 
    f.time++;
    Events_Trace++;
    Set_HitMiss(&all_pages.at(i));

    if (Hit_Miss == "HIT"){
      LRU_Fix_Order(&all_pages.at(i));
    } 
    else {
      Set_Miss(&all_pages.at(i));

      if (f.taken_size < f.size){
          enqueue(&all_pages.at(i));
      }
      else if (LRU_Victim() == f.head->frame_page.Frame_Time){
        Prev_Victim = f.next_victim->frame_page.Number;
        Set_Write(&f.next_victim->frame_page);
        dequeue();
        enqueue(&all_pages.at(i));
      } else {
        Prev_Victim = f.next_victim->next->frame_page.Number;
        Set_Write(&f.next_victim->next->frame_page);
        enqueueDequeue(&all_pages.at(i));
      }
    }
    if (mode_print == 3){
      printFrame(&all_pages.at(i)); 
    }
  }

 //if (f.size == 10 && Events_Trace > 150){
  //    Total_Disk_Reads--;
  //    Total_Disk_Writes--;
  //    Page_Faults--;
  //}
}


/********************* MOVE BIT *********************************/  
void PageReplacement::bit_enqueue(page *p){  
  bit *first = new bit;
  first->reference = 0;
  first->bit_next = NULL;
  p->bit_head = first;
  p->bit_tail = first;
  first = NULL;
  delete first;
  
  for (int i = 1; i < f.bit_size; i++){
    bit *temp = new bit;
    temp->reference = 0;
    temp->bit_next = NULL;
  
    if (p->bit_head == p->bit_tail){
      p->bit_head->bit_next = temp;
      p->bit_tail = temp;
    } else {
      p->bit_tail->bit_next = temp;
      p->bit_tail = temp;
    }

    temp = NULL;
    delete temp;
  }
}


void PageReplacement::Dec_Bit(page *p) { 
    std::string Bin_Number;
    bit *current = p->bit_head;
    while(current != NULL){   
      std::string temp = std::to_string(current->reference);
      Bin_Number = Bin_Number + temp;
      current = current->bit_next;
    }
    int Dec_Number = 0; 
    int base = 1; 
    int len = Bin_Number.length()-1;
    for (int i = len; i >= 0; i--) { 
        if (Bin_Number[i] == '1') 
            Dec_Number =  Dec_Number + base; 
        base = base * 2; 
    }
    p->Bit_DecNumber = Dec_Number; 
} 

void PageReplacement::bit_set(page *p, int n){
    p->bit_head->reference = n; 
    Dec_Bit(p);
}

void PageReplacement::ReferBit(page *p){
  int flag_found = 0;
  node* current = f.head;
  while(current != NULL){
    if (p->Number == current->frame_page.Number){
        bit_set(&current->frame_page, 1);
        flag_found = 1;    
    } 
    current = current->next;
  }

  if(flag_found == 0){
    bit_set(p, 1);
  }
}

void PageReplacement::bit_circular(page *p, int n){
  if (p->bit_head != NULL && p->bit_tail != p->bit_head){
    bit *current = p->bit_head;
    while(current != NULL && current->bit_next != p->bit_tail){   
      current = current->bit_next;
    }
    bit *temp = new bit;
    temp->reference = n;
    temp->bit_next = p->bit_head;
    p->bit_head = temp;

    current->bit_next = NULL;
    p->bit_tail = current;

    temp = NULL;
    delete temp;
    Dec_Bit(p);
  }
}

void PageReplacement::bit_circularFrame(){
  node* current = f.head;
  while(current != NULL){
    bit_circular(&current->frame_page, 0);
    current = current->next;
  }
}

/********************* ARB *********************************/ 

int PageReplacement::ARB_Victim(page *p){
  int min = f.head->frame_page.Bit_DecNumber;    
  f.next_victim = f.head;
  node* current = f.head;
  while(current->next != NULL){
      if (min > current->next->frame_page.Bit_DecNumber){
          min = current->next->frame_page.Bit_DecNumber;
          f.next_victim = current;
      }
      current = current->next;
  }
  return min;
}

void PageReplacement::ARB(){
  f.time++;
  bit_set(&all_pages.at(0), 1);
  Add_Head_Frame();
  //PrintFrameBit(&all_pages.at(0));
  for (int i = 1; i < Number_pages; i++){
    f.time++;
    f.bit_time = (f.bit_time + 1) % f.bit_interval;
    if (f.bit_time == 0){
        bit_circularFrame();
    }

    Events_Trace++;
    ReferBit(&all_pages.at(i));
    Set_HitMiss(&all_pages.at(i));
  
    if (Hit_Miss == "MISS"){
      Set_Miss(&all_pages.at(i));
      all_pages.at(i).Frame_Time = f.time;

      int min = ARB_Victim(&all_pages.at(i));
      if (f.next_victim == f.head){
        if (f.head->frame_page.Bit_DecNumber != min){
          Prev_Victim = f.next_victim->next->frame_page.Number;
          Set_Write(&f.next_victim->next->frame_page);
          enqueueDequeue(&all_pages.at(i));
        } else {
          Prev_Victim = f.next_victim->frame_page.Number;
          if (f.taken_size == f.size){
            Set_Write(&f.next_victim->frame_page);
            dequeue();
          }
          enqueue(&all_pages.at(i));
        }
      } else {
        Prev_Victim = f.next_victim->next->frame_page.Number;
        Set_Write(&f.next_victim->next->frame_page);
        enqueueDequeue(&all_pages.at(i));
      }
    }
    //PrintFrameBit(&all_pages.at(i));
  }
}


/********************* MOVE WIN *********************************/ 

void PageReplacement::win_enqueue(page *p){  
  win *first = new win;
  first->reference = p->Number;
  first->win_page = p;  
  first->win_next = NULL;
  f.win_head = first;
  f.win_tail = first;
  first = NULL;
  delete first;
}

PageReplacement::win* PageReplacement::win_findOld(page *p){
  win *old = NULL;
  win *current = f.win_head; 
  while(current != NULL){
    if(current->reference == p->Number){
      old = current;
      current = f.win_tail;
    }
    current = current->win_next;
  }
  return old;
}

void PageReplacement::win_CircularOld(win *old, page *p){
  if (old->reference == f.win_tail->reference){
      f.win_tail->win_page->Mode = p->Mode;
      f.win_tail->win_page->Frame_Time = f.time;
  }
  else if (old->reference != f.win_tail->reference){
    win *temp = new win;
    temp->reference = p->Number;
    temp->win_page = old->win_page;
    temp->win_page->Frame_Time = f.time;
    temp->win_page->Mode = p->Mode;
    temp->win_next = NULL; 
    if (old->reference == f.win_head->reference){
      f.win_head = f.win_head->win_next;
      f.win_tail->win_next = temp;
      f.win_tail = temp;
    }
    else {
      win* current = f.win_head->win_next;
      win* prev = f.win_head;
      while(current != NULL && current->reference != p->Number){   
        prev = current;
        current = current->win_next;
      }
      prev->win_next = current->win_next;
      f.win_tail->win_next = temp;
      f.win_tail = temp;                   
      current = NULL;
      delete current;
      prev = NULL;
      delete prev;
    }
  }
}

void PageReplacement::win_ReferCounterBit(page *p){
  win *old = NULL;
  win *current = f.win_head; 
  while(current != NULL){
    if(current->reference == p->Number){
      old = current;
      current = f.win_tail;
    }
    current = current->win_next;
  }
  current = NULL;
  delete current;

  if (old != NULL){
    bit_set(old->win_page, 1);
  }

  old = NULL;
  delete old;
}

void PageReplacement::win_enqueueDequeuePos(page *p){

  win *temp = new win;
  temp->reference = p->Number;
  temp->win_page = p;
  temp->win_page->Frame_Time = f.time;
  temp->win_next = NULL;
  f.win_tail->win_next = temp;
  f.win_tail = temp;             
  temp = NULL;
  delete temp;

  win *current = f.win_head; 
  if (f.time > f.win_size){
    current = f.win_head; 
    while (current != NULL){
      if(current ->win_page->Frame_Time < f.time - (f.win_size-1)){
        current->win_page->Counter = 0;
        for (int i = 0; i < current->win_page->Total_Counter.size(); i++){
          current->win_page->Total_Counter.at(i) = 0;
        }        
      }
      current = current->win_next;  
    }
    current = NULL;
    delete current;
  }
}

void PageReplacement::bit_circularWin(){
  win *current = f.win_head;
  while(current != NULL){
    node *frame_current = f.head;
    while(frame_current != NULL){
      if(frame_current->frame_page.Number == current->win_page->Number){
        int time = current->win_page->Frame_Time;
        page temp = frame_current->frame_page;
        *current->win_page = temp;
        current->win_page->Frame_Time = time;
      }
      frame_current = frame_current->next;
    }  
    current = current->win_next;
  }
  current = NULL;
  delete current;
}

PageReplacement::page* PageReplacement::win_getOldPage(page *p){
  page *oldPage = NULL;
  win *current = f.win_head; 
  while(current != NULL){
    if(p->Number == current->win_page->Number){
        oldPage = current->win_page;
      } 
    current = current->win_next;
  }
  return oldPage;
}

 void PageReplacement::win_CleanPage(int prev_victim){
  win *current = f.win_head; 
  while(current != NULL && current->reference != prev_victim){
    current = current->win_next;
  }
  
  current->win_page->Dirty = 0;
  current->win_page->Mode = " ";
  bit* clean = current->win_page->bit_head;
  while(clean != NULL){
    clean->reference = 0;
    clean = clean->bit_next;
  }
  current->win_page->Bit_DecNumber = 256;

  clean = NULL;
  delete clean;
  current = NULL;
  delete current;
}

/********************* MOVE COUNTER *********************************/ 

void PageReplacement::counter_DecBit(page *p){ 
    int Dec_Number = 0; 
    int base = 1;
    for (int i = p->Total_Counter.size()-1; i >= 0; i--) { 
        if (p->Total_Counter.at(i) == 1) 
            Dec_Number =  Dec_Number + base; 
        base = base * 2; 
    }
    p->Counter = Dec_Number;

} 

void PageReplacement::counter_enqueue(page *p){
  p->Total_Counter.erase(p->Total_Counter.begin(), p->Total_Counter.begin()+1);
  p->Total_Counter.push_back(1);
  counter_DecBit(p);
}

void PageReplacement::counter_clean(page *p){
  p->Total_Counter.erase(p->Total_Counter.begin(), p->Total_Counter.begin()+1);
  p->Total_Counter.push_back(0);
  counter_DecBit(p);
}

void PageReplacement::CounterBit(page *p){
  int flag_found = 0;
  node* current = f.head;
  while(current != NULL){
    if (p->Number == current->frame_page.Number){
        counter_enqueue(&current->frame_page);
        flag_found = 1;    
    } 
    current = current->next;
  }

  current = f.head;
  while(current != NULL){
    if (p->Number != current->frame_page.Number){
        counter_clean(&current->frame_page);
    } 
    current = current->next;
  }

  if(flag_found == 0){
    counter_enqueue(p);
  }
}

/********************* WSARB *********************************/ 

std::vector<int> PageReplacement::WSARB_Victim(page *p){
  std::vector<int> result; 
  node* current = f.head;
  node* current_min = f.head;
  int min = f.head->frame_page.Counter;
  while(current != NULL){
      if (min > current->frame_page.Counter){
          min = current->frame_page.Counter;
          current_min = current;
      }
      current = current->next;
  }
  //printf("Counter Min: %i\n", min);
  
  current = current_min;
  int final_min = current_min->frame_page.Bit_DecNumber;
  f.next_victim = current_min;
  while(current != NULL && current->next != NULL){
    if (min == current->next->frame_page.Counter){
      if (final_min > current->next->frame_page.Bit_DecNumber){
          final_min = current->next->frame_page.Bit_DecNumber;
          f.next_victim = current;
      }
    }
    current = current->next;
  }

  //printf("Dec Min: %i\n", final_min);
  
  result.push_back(min);
  result.push_back(final_min);

  if (f.head->frame_page.Counter == result.at(0) && f.head->frame_page.Bit_DecNumber == result.at(1)){
    result.push_back(1);
  } else {
    result.push_back(0);
  }
  return result;
}

void PageReplacement::WSARB(){
  for (int i = 0; i < Number_pages; i++){
    int len = 5;
    if (f.win_size < 5){ len = f.win_size; }  
    for (int j = 0; j < len ; j++){
      all_pages.at(i).Total_Counter.push_back(0);
    }
  }
  f.time++;
  bit_set(&all_pages.at(0), 1);
  counter_enqueue(&all_pages.at(0));
  Add_Head_Frame();
  win_enqueue(&all_pages.at(0));
  
  for (int i = 1; i < Number_pages; i++){
    std::vector<int> min = WSARB_Victim(&all_pages.at(i));
    f.time++;
    f.Counter_Index = (f.bit_time + 1) % f.win_size;
    f.bit_time = (f.bit_time + 1) % f.bit_interval;
    if (f.bit_time == 0){
        bit_circularFrame();
    }
    bit_circularWin();
    Events_Trace++;
    ReferBit(&all_pages.at(i));
    CounterBit(&all_pages.at(i));
   
    win_ReferCounterBit(&all_pages.at(i));
    
    win *old = win_findOld(&all_pages.at(i));
    if (old != NULL){
      win_CircularOld(old, &all_pages.at(i));
    }
   
    Set_HitMiss(&all_pages.at(i));
    //PrintFrameWin(&all_pages.at(i));

    //if (Hit_Miss == "HIT")
      //printf("*** HIT *** \n");

    if (Hit_Miss == "MISS"){
      Set_Miss(&all_pages.at(i));
      all_pages.at(i).Frame_Time = f.time;
      if (old == NULL){ 
        win_enqueueDequeuePos(&all_pages.at(i));
      }
      page *newOld = win_getOldPage(&all_pages.at(i));
      
      if (f.taken_size < f.size){
          //printf("ADD NOT VICTIM SIZE \n");
          enqueue(newOld);
      }
      else if (f.next_victim == f.head){
        //printf("ADD HEAD \n");
        if ( min.at(2) == 1 ){
          //printf("*******REAL HEAD \n");
          Prev_Victim = f.next_victim->frame_page.Number;
          Set_Write(&f.next_victim->frame_page);
          dequeue();
          win_CleanPage(Prev_Victim);
          enqueue(newOld);
        } else {
          //printf("NOT MIN - DEC MIN \n");
          Prev_Victim = f.next_victim->next->frame_page.Number;
          Set_Write(&f.next_victim->next->frame_page);
          win_CleanPage(Prev_Victim);
          enqueueDequeue(newOld);
        }
      } else {
        //printf("ELSE AQUI 1 \n");
        Prev_Victim = f.next_victim->next->frame_page.Number;
        Set_Write(&f.next_victim->next->frame_page);
        win_CleanPage(Prev_Victim);
        enqueueDequeue(newOld);
      }
    }
    //PrintFrameBit(&all_pages.at(i));  
  }
  
  Total_Disk_Reads++;
  Page_Faults++;

}

/********************* MAIN *********************************/ 

int main(int ac, char **av)
{
  PageReplacement system(av[1], av[2], av[3]);
  
  if (ac == 5){
    if (std::string(av[4]) == "FIFO"){
      system.FIFO();
    } else  if (std::string(av[4]) == "LRU"){
      system.LRU();
    }
  } else {
    system.f.bit_size = atoi(av[5]);
    system.f.bit_interval = atoi(av[6]);
    for (int i = 0; i < system.Number_pages; i++){
      system.bit_enqueue(&system.all_pages.at(i));
    }
    
    if (ac == 7 && std::string(av[4]) == "ARB"){
      system.ARB();
    } else if (ac == 8 && std::string(av[4]) == "WSARB"){
      system.f.win_size = atoi(av[7]);
      system.WSARB();
    }
  }
  system.PrintOutput();
  //printf("\n");

  return 0;
}

//1 = false. 0 = true v7