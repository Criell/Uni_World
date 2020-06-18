size (400,400);

background (0,128,0);

fill(255,0,0);
int radius = 0;
int movex = 0;
int movey = 0; 
int k = 0;
int n = 5;

if (height < width)
  radius = height/6;
else
  radius = width/6;

for (int i=0; i<n; i++)
{
  movex = radius+(65*i);
  k=n-i;

  
  
  for (int j=0; j<k; j++)
  {
     movey = i*25 + radius+(65*j);    
     if (k==1)
     fill (150,0,150);
     ellipse (movex, movey, radius, radius);
     
     
  }
}