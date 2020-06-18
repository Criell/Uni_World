size (400,400);
background (0);

int [] array;
int n = 20;
array = new int [n];

for (int i = 0; i < n; i++)
{
  array[i] = int (random (1, 9));  
}

int min = array[0];
int max = 0;
int sum = 0;
int [] counter = {0,0,0,0,0,0,0,0,0};

for (int i = 0; i < n; i++)
{
  if (min > array[i])
    min = array[i];
  if (max < array[i])
    max = array[i];
  
  sum = sum + array[i];
  
  switch(array[i]){
    case 1:counter[0]++; break;
    case 2:counter[1]++; break;
    case 3:counter[2]++; break;
    case 4:counter[3]++; break;
    case 5:counter[4]++; break;
    case 6:counter[5]++; break;
    case 7:counter[6]++; break;
    case 8:counter[7]++; break;
    case 9:counter[8]++; break;
  }
}

int mean = sum /n;
int number = counter[0];
int mode = 1;

for (int i = 1; i < 8; i++)
{
  if (number < counter[i])
  {
    number = counter[i];
    mode = mode + i;
  }
}

 text ("minimum:", 20, 20);
 text ("maximum:", 20, 40);
 text ("mean:", 20, 60);
 text ( "mode:", 20, 80);
 
 text (min, 90, 20);
 text (max, 90, 40);
 text (mean, 90, 60);
 text (mode, 90, 80);


int [] difference;
difference = new int[n];

for (int i = 0; i < n; i++)
{
  difference[i] = (mean - array[i]);
} 

int space = 10;

for (int i = 0; i < n; i++)
{
   if (difference[i] < 0) {
      fill(0,200,200);
    }
  
    else if (difference[i] > 0) {
      fill(255,0,0); 
    }
    rect (space, 250, width/50, difference[i]*30);
    text (difference[i], space, height-20);
    
    space = space + height/20;
  
  }