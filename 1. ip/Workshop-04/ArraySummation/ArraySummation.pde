size (300, 200);
//background(0);
fill(0);
strokeWeight (4);
int total = 0;

int[] counts = new int[10];

for (int i = 0; i < 10; i++) 

{
    counts[i] = i;    
    text(counts[i],width/10*i,height/4);
    total = total + counts[i];
    text(total,width/10*i,height/3);
    
}

text(total, width/2, height/2);