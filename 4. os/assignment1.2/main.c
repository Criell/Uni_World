#include	<stdio.h>
#include  <stdlib.h>
#include	<unistd.h>
#include	<string.h>

typedef struct Bits{
  int bit; 
  struct Bits *next;  
} bits; 

typedef struct Event {
  char access; 
  char address[9];
  int resident;
  int chance;
  struct Event *next;
  bits *bitHead; 
  bits *bitTail;
} event; 

typedef struct Frames {
  int read;
  int write;
  event *pages;
  event *victim;
  event *tail;
} frame; 


/********************* PRINT *********************************/  

void printBits(event p) {
  bits *current = p.bitHead;
  while(current != NULL) {
    printf("|%i", current->bit);
    current = current->next;
  }
  printf("|");
}

void PrintEvent(event p){
  printf("%c ", p.access);
  printf("%s ", p.address);
  printf("%i ", p.resident);
  //printf("%i ", p.chance);
  //printBits(p);
  printf("\n");
}

void printDisk(event q[], int s) {
  for (int i = 0; i < s; i++){
      PrintEvent(q[i]);
  }
}

void printFrame(frame q, int s) {
  printf("address access resident bits\n");
  for (int i = 0; i < s; i++){
      PrintEvent(q.pages[i]);
  }
}

void PrintOutput(long s, int r, int w){  
  printf("events in trace:    %li\n", s);
  printf("total disk reads:   %i\n", r);
  printf("total disk writes:  %i\n", w);
}

/********************* REFERENCE BIT *********************************/   

void addBit(event *p){
  bits *temp = malloc(sizeof(bits));
  temp->bit = 0;
  temp->next = NULL;
  if (p->bitHead == NULL){
    p->bitHead = temp;
    p->bitTail = temp;
  } else{ 
    p->bitTail->next = temp;
    p->bitTail = temp;
  }
  temp = NULL;
  free(temp);
}

void circularBit(event *q){
  if (q->bitHead == NULL) {
  } else if (q->bitHead == q->bitTail) {
  } else { 
    bits *newtail = malloc(sizeof(bits));
    newtail->bit = q->bitHead->bit;
    newtail->next = NULL;
    
    q->bitTail->next = newtail;
    q->bitTail = newtail;
    newtail = NULL;
    free(newtail);

    bits *temp = q->bitHead->next;
    q->bitHead = temp;
    temp = NULL;
    free(temp);
  }
}


/********************* ADD Event *********************************/  

void addEvent(event *p, frame* f){
  if (f->pages == NULL){  
    f->pages = p;
    f->tail = f->pages;
    f->victim = f->pages;
  } else {
    f->tail->next = p;
    f->tail = p;
  }
}

/********************* Frame *********************************/  
void startframe(frame *q, int s) {
  q->read = 0;
  q->write = 0;
  q->pages = NULL;
}

int page_zise(int bits){
  int size = 1;
  while (bits > 16){
    size++;
    bits = bits/16;
  }
  return size;
}

/********************* INPUT *********************************/  

long SizeInput(char* filename){
  char *nlines = NULL;
  size_t l = 0;
  long counter = 0;
  FILE *inputfp = fopen (filename , "r");
  
  while( getline(&nlines, &l, inputfp) != EOF ){ 
    while (nlines[0] == '#'){
      getline(&nlines, &l, inputfp);
      if (nlines != '\0') {
        break;
      }
    }
    if (counter > 255){
        break;
    }

    counter++;
  }

  fclose(inputfp);
  return counter;
}

void ReadInput(event temp[], long size, char * filename, int flag){
  char *lines[size];
  size_t l = 0;
  FILE *inputfp = fopen (filename,"r");
  char *reg;
  int b = 8 - flag;
  char buf[b];
  
  int i;
  for (i = 0; i < size; i++){
    lines[i] = NULL;
    getline(&lines[i], &l, inputfp);
    
    while (lines[i][0] == '#'){
      getline(&lines[i], &l, inputfp);
    }

    reg = strtok (lines[i], " ");
    temp[i].access = lines[i][0];

    for (int j = 0; j < b; j++){
      buf[j] = lines[i][j+2];
    }
    buf[b] = '\0';
    strcpy(temp[i].address, buf);
    temp[i].resident = 0;
    temp[i].chance = 0;
    temp[i].next = NULL;
  }
}

int findValue(event d, frame *f){
  event *temp = f->pages; 
  while (temp != NULL){
    if (strcmp (d.address, temp->address ) == 0){
      temp->resident = 1;
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int checkRef(event *d){
  //printf("Checking: ");
  //PrintEvent(*d);
  if (d->resident == 1){
    return 1; 
  }
  return 0;
}


void findNexttail(event *victim, frame *f){
  event * temp = victim;
  int flag = 0;
  temp = temp->next;
  while (temp != NULL){
    //PrintEvent(*temp);
    if (temp->resident == 1){
      temp->resident = 0;
    } else {
      f->victim = temp;
      flag = 1;
    }
    temp = temp->next;
  }

  if (flag == 0){
    findNexttail(f->pages, f);
  }
    
}

void Replace(event *d, event *victim){
  strcpy(victim->address, d->address);
  victim->resident = 1;
}

void SCmethod(event d[], long sd, frame *f, int sf){
  int miss = 0;
  int hit = 0;

  for (int i = 0; i < sf; i++){
      addEvent(&d[i], f);
      miss++;
  } 

  //printFrame(*f, sf);

  long diff = sd - sf;

  for (int i = sf; i < sd; i++){
    if(findValue(d[i], f) == 1){
      hit++;
    } else {
        if (checkRef(f->victim) == 0){
          Replace(&d[i], f->victim);
        } else {
          findNexttail(f->victim, f);
          Replace(&d[i], f->victim);
        }
        //printFrame(*f, sf);
        miss++;
    }
    
  }
    
  //printFrame(*f, sf);
  f->read = miss;
  f->write = hit;
}
    
void ESCmethod(event d[], long sd, frame *f, int sf){
  int miss = 0;
  int hit = 0;
  
  for (int i = 0; i < sf; i++){
    addEvent(&d[i], f);
    miss++;
  }
  //printFrame(*f, sf);
  
  f->read = miss;
  f->write = hit;
 
}

void ARBmethod(event d[], long sd, frame *f, int sf, int shift){
  int miss = 0;
  int hit = 0;
  
  for (int i = 0; i < sf; i++){
    addEvent(&d[i], f);
    addBit(&f->pages[i]);
    addBit(&f->pages[i]);
    addBit(&f->pages[i]);
    f->pages[i].bitHead->bit = 1;
    miss++;
  }
  circularBit (&f->pages[0]);
  //printFrame(*f, sf);
  
  f->read = miss;
  f->write = hit;
 
}

void EARBmethod(event d[], long sd, frame *f, int sf, int shift){
  int miss = 0;
  int hit = 0;
  for (int i = 0; i < sf; i++){
    addEvent(&d[i], f);
    addBit(&f->pages[i]);
    addBit(&f->pages[i]);
    addBit(&f->pages[i]);
    f->pages[i].bitHead->bit = 1;
    miss++;
  }

  circularBit (&f->pages[0]);
  //printFrame(*f, sf);

  f->read = miss;
  f->write = hit;
}

/*************************** MAIN *********************************/

int main(int ac, char **av)
{
  long numEvents = 0;
  numEvents = SizeInput(av[1]);
	event disk[numEvents];
  int flag = page_zise(atoi(av[2]));
  
  ReadInput (disk, numEvents, av[1], flag);
  //printDisk (disk, numEvents);

  int sizeFrame = atoi(av[3]); 
  frame Frame; 
  startframe(&Frame, sizeFrame); 
  char method[5];
  strcpy(method, av[4]);  
  if (strcmp(method,"SC") == 0){
    SCmethod(disk, numEvents, &Frame, sizeFrame);
  } else if (strcmp(method,"ESC") == 0){ 
    ESCmethod(disk, numEvents, &Frame, sizeFrame);        
  } else if (strcmp(method, "ARB") == 0){ 
    ARBmethod(disk, numEvents, &Frame, sizeFrame, atoi(av[5]));       
  } else if (strcmp(method, "EARB") == 0) {
    EARBmethod(disk, numEvents, &Frame, sizeFrame, atoi(av[5]));             
  }
  
	PrintOutput(numEvents, Frame.read, Frame.write);
	return 0;
}