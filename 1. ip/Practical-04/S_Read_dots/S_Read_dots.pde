size (500,500);

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

for (int i=0; i<6; i++)
{
  movey = radius+(65*i);
  
  for (int j=0; j<6; j++)
  {
     movex = radius+(65*j);
     ellipse (movex, movey, radius, radius);
  }
}