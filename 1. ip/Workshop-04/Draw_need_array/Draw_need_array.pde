size (600,600);

background (0);
stroke(255);
int[] radius = new int[10];
int center = 0;

int x= width/2;
int y= height /2;
int a = width/2;
int b = height /2;

fill(0,255,255);
ellipse (x,y,a,b);

for (int i = 0; i < 4; i++) 
{
    radius[i] = center;  
    center = center + 10;
    fill(0,0,255);
    ellipse (x-i*50, y, 50, 50);
    fill(0,255,0);
    ellipse (x, y-i*50, 50, 50);
    fill(255,0,0);
    ellipse (x+i*50, y, 50, 50);
    fill(255,255,0);
    ellipse (x, y+i*50, 50, 50);   
}

rotate (PI/6);

for (int i = 0; i < 4; i++) 
{
    radius[i] = center;  
    center = center + 10;
    fill(0,0,255);
    ellipse (x-i*50, y, 50, 50);
    fill(0,255,0);
    ellipse (x, y-i*50, 50, 50);
    fill(255,0,0);
    ellipse (x+i*50, y, 50, 50);
    fill(255,255,0);
    ellipse (x, y+i*50, 50, 50);   
}