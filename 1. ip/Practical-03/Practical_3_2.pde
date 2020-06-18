size (600,600);

background (0);
stroke(255);
strokeWeight(4);

int[] numbers=new int [12];
float mean = 0.00;


for (int i=0; i<12;++i)
{
  numbers[i] = int(random(1,9));
  println(numbers);
  mean = mean + numbers[i]; 
 
}

mean = mean/12;

int min_index; 

for (int i=0; i<12;++i)
{
  min_index = i;
  
  for (int j=0; j<12;++j)
  {
    if (numbers[min_index]>numbers[j])
    {
         min_index = j;
        
    }
        
    int temp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = temp;
    println(numbers);
     
  }
    
}

int median = round ((numbers[5]+numbers[6])/2);
noFill();
stroke(255);

text("The twelve numbers: ", 20, 60);
for (int i=0; i<12; i++)
    text(numbers[i], width/2+(i*20), 60);
    
fill (255,0,0);
text("The mean: ", 20, 20);
text(mean,width/2,20);

fill (255,255,0);
text("The median: ", 20, 40);
text(median,width/2,40);

int radius, lr;

strokeWeight(2);
for (int i=2; i<14; i++)
{
   radius = ((numbers[i-2]*20)+height/3);
   lr = radius+i*40;
   stroke (0,numbers[i-2]*40,numbers[i-2]*140);
   noFill();
   ellipse(width/2, height/2, lr-(i*50), lr-(i*30));
}

for (int i=0; i<12; i++)
{   
   if (numbers[i]<=mean)
    {
        stroke (255,0,0);
        noFill();
        radius = (round(mean*20)+height/3);
        lr = radius+round(mean*40);
        ellipse (width/2, height/2, lr-100, lr);
        i=13;
    }
}

for (int i=0; i<12; i++)
{
   
    if (numbers[i]<=median)
    {
        radius = ((median*20)+height/3);
        lr = radius+median*40;  
        stroke (255,255,0);
        noFill();
        ellipse (width/2, height/2, lr, lr-100);
        i=13;
    }
}