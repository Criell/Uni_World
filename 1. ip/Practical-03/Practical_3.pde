size (200,200);

background (0);
stroke(255);
strokeWeight(4);

int[] numbers=new int [12];
float mean = 0.00;


for (int i=0; i<12;++i)
{
  numbers[i] = int(random(0,9));
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
strokeWeight(4);

text("The twelve numbers: ", 20, 60);

fill (255,0,0);
text("The mean: ", 20, 20);
text(mean,width/2,20);


fill (255,255,0);
text("The median: ", 20, 40);
text(median,width/2,40);

for (int i=0; i<12; i++)
{
   stroke (0,numbers[i]*40,numbers[i]*140);
   strokeWeight(3);
   fill(0,numbers[i]*50,numbers[i]*190);
   rect( 40, 80+(i*width/25),numbers[i]*width/9.9,height/80);
   fill(255);
   text(numbers[i], 20, 80+(i*width/25)+10);
}

for (int i=0; i<12; i++)
{
    if (numbers[i]<=mean)
    {
        stroke (255,0,0);
        line (40,95+(i*13),numbers[0]*width/9.9,95+(i*13));
        i=13;
    }
}

for (int i=0; i<12; i++)
{
    if (numbers[i]<=median)
    {
        stroke (255,255,0);
        line (40,90+(i*13),numbers[0]*width/9.9,90+(i*13));
        i=13;
    }
}