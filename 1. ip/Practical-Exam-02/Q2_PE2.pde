int n;
int [] array;

int test_sum;
int text_x;
int text_y;

int x;
int y;
int test_check;


void setup(){
  size(200,800);
  background(255);
  fill (0);
  
  n = 30;
  array = new int [n];
  
  text_x = 20;
  text_y = 20;
  
  for (int i = 0; i < n; i++){
      array[i] = int(random (-100,100));
      //array[i] = int(random (10,10));
  } 
}

void draw(){
    
  for (int i = 0; i < n; i++){
      text (array[i], text_x, text_y);
      text_y = text_y + 20;
  }
  
  text_y = text_y + 20;
  text (" ", text_x, text_y);
  
  
  test_sum = sum(array);
  text (test_sum, text_x, text_y);
  text_y = 20;
   
}

int sum(int [] array){
  int sum = 0;
  for (int i = 0; i < n; i++){
      sum = sum + array[i];
  }
  return sum;
}