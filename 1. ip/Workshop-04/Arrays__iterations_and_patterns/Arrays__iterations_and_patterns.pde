size (600,600);

background (0);
stroke(255);
int[] radius = new int[10];
int center = 0;
noFill();

for (int i = 0; i < 10; i++) 

{
    radius[i] = center;  
    center = center + 50;
    strokeWeight(1);
    ellipse (width/2, height/2, radius[i],radius[i]);
    strokeWeight(10);
    text(radius[i], width/2, height/2 + radius[i]/2);
    
}