size (400,400);

background (0,128,0);

fill(255,0,0);
int radius = 0;
int movex = 0;
int movey = 0; 
int k = 0;

if (height < width)
  radius = height/6;
else
  radius = width/6;

for (int i=0; i<5; i++)
{
  movey = radius+(65*i);
  k=5-i;
  println(k); 
  
  for (int j=0; j<k; j++)
  {
     movex = radius+(65*j);
     ellipse (movex, movey, radius, radius);
  }
}
