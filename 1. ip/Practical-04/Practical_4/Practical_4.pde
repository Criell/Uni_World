size (400,400);

background (0);
stroke(255);
strokeWeight(4);

int[] numbers=new int [10];
float mean = 0.00;


for (int i=0; i<10;++i)
{
  numbers[i] = int(random(1,10));
  println(numbers);
  mean = mean + numbers[i]; 
 
}

mean = mean/10;

int min_index; 

for (int i=0; i<10;++i)
{
  min_index = i;
  
  for (int j=0; j<10;++j)
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

//int median = round ((numbers[5]+numbers[6])/2);
noFill();
stroke(255);
strokeWeight(4);

text("The twelve numbers: ", 20, 60);

fill (255,0,0);
text("The mean: ", 20, 20);
text(mean,width/2,20);

/**
fill (255,255,0);
text("The median: ", 20, 40);
text(median,width/2,40);
*/

for (int i=0; i<10; i++)
{
   stroke (0,numbers[i]*40,numbers[i]*140);
   strokeWeight(3);
   fill(0,numbers[i]*50,numbers[i]*190);
   rect( 40 +(i*width/25),90,width/80,numbers[i]*height/12);
   fill(255);
   text(numbers[i], 30+(i*width/25)+10, 80);
}

for (int i=0; i<10; i++)
{
    if (numbers[i]<=mean)
    {
        stroke (255,0,0);
        line (33+(i*width/25),90,33+(i*width/25),numbers[i]*height/6);
        i=13;
    }
}

/**
for (int i=0; i<10; i++)
{
    if (numbers[i]<=median)
    {
        stroke (255,255,0);
        line (36+(i*width/25),90,36+(i*width/25),numbers[i]*height/6); 
        i=13;
    }

}
*/