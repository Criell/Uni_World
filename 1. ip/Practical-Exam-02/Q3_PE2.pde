int n;
int [] array;

int text_x;
int text_y;

int x;
int y;
int test_check;


void setup(){
  size(200,800);
  background(255);
  fill (0);
  
  n = 10;
  array = new int [n];
  
  text_x = 20;
  text_y = 20;
  
  for (int i = 0; i < n; i++){
      array[i] = int(random (-500,1500));
  } 
  
  //x = int(random (-1000,2000));
  //x = int(random (0,1000));
  //y = int(random (-1000,2000));
  //y = int(random (0,1000));
}

void draw(){
  
  for (int i = 1; i < n; i++){
    x = (array[i-1]);
    text (x, text_x, text_y);
    text_y = text_y + 20;
    
    y = (array[i]);
    text (y, text_x, text_y);
    text_y = text_y + 20;
    
    test_check = check(x, y);
    text (test_check, text_x, text_y);  
    text_y = text_y + 40;
    
    text (" ", text_x, text_y); 
   }
}

int check(int x, int y){
  if ((x >= 0) & (x<=1000) & (y >= 0) & (y <= 1000)){
    return 1;
  }
  else
    return 0; 
}