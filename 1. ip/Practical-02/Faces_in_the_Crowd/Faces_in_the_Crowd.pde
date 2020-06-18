size (400,180);

background (0,150,255);
strokeWeight (2);

fill (255,255,0);
ellipse (380,0,150,150);
fill (100);
ellipse (180,150,220,240);

//Dad
fill(255);
ellipse (150,100,60,80);
fill(255,0,0);
ellipse(150,120,10,15);
fill(0);
rect (123,50,52,30);
ellipse(140,100,5,5);
ellipse(160,100,5,5);
ellipse(100,100,5,5);
ellipse(250,100,5,5);


//Mom
fill (255);
ellipse (200,100,50,70);
int n=186;
int n2=225;
for (int i=0; i<5; i++)
{
  n=n-2;
  n2=n2-2;
  line (n,80,n,180);
  line (n2,80,n2,180);
}
fill(0,0,255);
rect (180,60,40,30);
fill (0);
ellipse(200,120,5,5);
ellipse(190,100,5,5);
ellipse(210,100,5,5);

//girl

fill (165,137,70);
rect(80,140,40,40);
fill(255,0,0);
triangle (80,140,120,140,100,100); 
triangle (90,160,110,160,100,163);
line (80,145,90,145);
line (110,145,120,145);

//boy
fill (255);
ellipse (250,150,50,60);
fill (0,150,0);
triangle (220,140,280,140,250,100);
line (240,145,245,145);
line (255,145,260,145);
fill(255,0,0);
triangle (240,160,260,160,250,163);