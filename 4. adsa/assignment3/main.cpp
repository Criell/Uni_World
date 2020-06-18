#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

struct key {
  std::string word;
  std::string state;
  key *next;
};  

struct h_key {
  std::string ll;
  std::string state;
  key *head;
  key *tail;
  int length;
}; 


/********************* PRINT *********************************/  

void PrintWords(key* p){
  if (p->state != "tombstone")
    printf("%s ", p->word.c_str());
  //printf("%s\n", p->state.c_str());
}

void print_Hash(h_key *q) {
  
  if(q != NULL) {
      std::cout << "Hash: ";
      printf("%s\n", q->ll.c_str());
      printf("%s\n", q->state.c_str());
  }
}

void printH_key(h_key *q) {
  
  key* printhead = q->head;
  while(printhead != NULL) {
    PrintWords(printhead);
    printhead = printhead->next;
  }

  /**
  key* printtail = q->tail;
  if(printtail != NULL) {
    std::cout << "TAIL" << std::endl;
    PrintWords(printtail);
  }
  **/
  
}

void print_table(h_key q[]) {
  for (int i = 0; i < 26; i++){
    printH_key(&q[i]);  
  }
  std::cout << std::endl;
}

/********************* h_key *********************************/  
h_key* start_Key(h_key* q, std::string l) {
  q->ll = l;
  q->state = "never used";
  q->head = NULL;
  q->tail = NULL;
  q->length = 0;

  //print_Hash(q);
  return q;
}

int empty(h_key q){
  if (q.head == NULL){
    return 1;
  } else {
    return 0;
  }
}

int find_hash(h_key q[], std::string l){
  int i = 0;
  while (i < 26){  
    if (l == q[i].ll){
      return i;
    } 
    i++;
  }
  return -1;
}

void add_hash(h_key q[], std::string l){
  if (find_hash(q, l) == -1){
    int i = 0;
    while (i != 26){ 
      if (q[i].state == "never used"){
        q[i].ll = l;
        q[i].state = "occupied";
        break;
      }   
      i++;
    }
  }
}

int find_key(h_key* q, std::string w){
  key* temp = q->head;
  while(temp != NULL && w != temp->word){   
    temp = temp->next;
  }

  if (temp != NULL && temp->state != "tombstone"){
    return 0;
  } else {
    return 1;
  }
}

void insert_key(h_key* q, std::string w){
  if (find_key(q, w)){
    key* temp = q->head;
    while(temp != NULL && temp->state != "occupied"){   
      temp = temp->next;
    }
    if (temp != NULL){
      temp-> word = w;
      temp-> state = "occupied";
    }
    else {
      temp = new key;
      temp -> word = w;
      temp -> state = "never used";
      temp -> next = NULL;
    
      if (q->head == NULL){
        q->head = temp;
        q->tail = temp;
      } else{
        q->tail->next = temp;
        q->tail = temp;
      }
      q->length ++;
      
    }
    temp = NULL;
    delete temp;
  } 
}

void delete_key(h_key* q, std::string w){
  if (q->head == NULL){
 
  } else {

    key* temp = q->head;
    while(temp != NULL && w != temp->word){   
      temp = temp->next;
    }

    if (temp == NULL){

    } else {
      temp -> state = "tombstone";
    }
  }
}


/********************* INPUT *********************************/  

std::vector<std::string> ProcessInput(std::string temp) {
    std::istringstream iss(temp);
    std::vector<std::string> input((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
    return input;
}

int main()
{
    std::string temp;
    std::vector<std::string> input;

    h_key hash_table[26];
    for (int i = 0; i < 26; i++){
      int ascii = 97+i;
      char letter = static_cast<char>(ascii);
      std::string s; 
      s.push_back(letter);
      start_Key(&hash_table[i], s);
    }

    //while(true){
        //std::cout << ">> ";
        std::getline(std::cin, temp);
        input = ProcessInput(temp);   
        for (int i = 0; (unsigned)i < input.size(); i++){
            if (input[i][0] == 'A'){
                std::string Svalue = input[i];
                Svalue.erase (Svalue.begin(),Svalue.begin()+1);
                std::string hash = Svalue;
                hash.erase (hash.begin(),hash.end()-1); 
                add_hash(hash_table, hash);
                int index = find_hash (hash_table, hash);
                insert_key (&hash_table[index], Svalue);
            } else if (input[i][0] == 'D'){
                std::string Svalue = input[i];
                Svalue.erase (Svalue.begin(),Svalue.begin()+1); 
                std::string hash = Svalue;
                hash.erase (hash.begin(),hash.end()-1);
                
                if (find_hash (hash_table, hash) > -1){
                  int index = find_hash (hash_table, hash);
                  delete_key (&hash_table[index], Svalue);
                }
              
            } else if (input[i] == "Z") {
                exit(0);
            }
        }
        print_table(hash_table);
    //}

    
    
    return 0;
}