size(800,200);
background(255);

int n =15;
int [] array = new int [n]; 
int x = 20;
int y = 20;
int size = 50;
  
for (int i = 0; i < n; i++){
      array[i] = int(random (-10,20));
      //array[i] = int(random (0,0));
} 

for (int i = 0; i < n; i++){
  if (array[i] < 0)
      fill(0);
  else if (array[i] >= 0)
      fill(255,255,array[i]*15);
  
  rect (x, y, size, size);
  fill(0);
  text (array[i], x, y +size+10);
  x = x + size;
}    