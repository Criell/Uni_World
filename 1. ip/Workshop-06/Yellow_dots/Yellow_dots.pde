size (500,500);

background (255);

fill(255,255,0);
int radius = 0;
int movex = 0;
int movey = 0; 
int k = 0;
int n = 6;

radius = height/7 -5;

for (int i=0; i<n; i++)
{
  movex = radius+(60*i);
  k=n-i;
  
  for (int j=0; j<k; j++)
  {
      
    
       if (i == 1 && (j==1 ||j==3))
           fill (255,0,0);
       else if (i == 1 && j == 2)
           fill (0,128,255);
       else if (i == 2 && (j == 1 || j == 2)) 
           fill (0,128,255);
       else if (i == 3 && j == 1) 
           fill (255,0,0);
       else
            fill(255,255,0);
   
     
    movey = i*33 + radius+(70*j); 
    ellipse (movex, movey, radius, radius);
    
  }
  fill(255,255,0);
}