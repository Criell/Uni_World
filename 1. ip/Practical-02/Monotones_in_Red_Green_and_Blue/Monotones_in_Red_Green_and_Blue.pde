size(400,400);

background(0,200,230);

noFill();
strokeWeight(20);
stroke(0,105,255);
rect(0,0,width,height);

stroke(0,205,255);
line(0,100,0,300);
line(400,30,400,150);
line(250,0,370,0);


strokeWeight(2);
stroke(0,0,255);

fill(0,105,255);
ellipse(300,280,180,180);
strokeWeight(1);
fill(0,0,250);
triangle(200,200,100,10,90,350);
strokeWeight(10);
fill(0,0,205);
rect (30,260,150,90);
point(60,230);
rect(60,240,1,10);
rect(50,240,20,0);

strokeWeight(3); 
for (int i=0; i<600;i=i+100)
{
    fill(0,160,255);
    ellipse(0+i,60,150,80);
        
        if (i<300)
        {
          fill(0,170,255);
          ellipse(100+i,100,150,80);
        }
}

noStroke();

for (int i=0; i<600; i=i+100)
{
    fill(0,100,255);
    ellipse(i,400,200,200);
    fill(0,150,255);
    ellipse(i-50,450,200,200);
}