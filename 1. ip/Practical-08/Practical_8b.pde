int [] array_x;
int [] array_y;
int [] array_size;
int [] rand_shape;
int n;
int red;
int yel;
int blu;
int counter=0;

void setup (){
  size (400,400);
  background (255);
  n = 10;
  array_x = new int [n];
  array_y = new int [n];
  array_size = new int [n];
  rand_shape = new int [n];
  red = int (random (0, 255));
  yel = int (random (0, 255));
  blu = int (random (0, 255));
  
  for (int i = 0; i < n; i++)
  {
    array_x[i] = int (random (100, width-100));
    array_y[i] = int (random (100, height-100));
    array_size[i] = int (random (10, 100));
    rand_shape[i] = int (random (1, 4));  
  }
}

void draw (){
 background (255);
 print(n, array_size, rand_shape, array_x, array_y, red, yel, blu);
}

void shape(int random_size, int random_shape, int x, int y, int red, int yellow, int blue)
{
  fill(red,yellow,blue);
  if (random_shape == 1)
    rect(x,y,random_size,random_size);
  else if (random_shape == 2)
    rect(x,y,random_size,random_size/2);
  else if (random_shape == 3)
    ellipse(x,y,random_size,random_size);
  else if (random_shape == 4)
    ellipse(x,y,random_size,random_size/2);
}

void print(int n, int [] array_size, int []rand_shape, int [] array_x, int [] array_y, int red, int yel, int blu){
  for (int i = 0; i < n; i++)
  {
      shape(array_size[i], rand_shape[i], array_x[i], array_y[i], red, yel, blu); 
  }
}

void mouseMoved(){
    red = int (random (0, 255));
    yel = int (random (0, 255));
    blu = int (random (0, 255));
    print(n, array_size, rand_shape, array_x, array_y, red, yel, blu);   
}

void mousePressed(){
  if (counter < n){
    array_x[counter] = -100;
    array_y[counter] = -100;
    array_size[counter] = -100;
    counter++;
  }
}