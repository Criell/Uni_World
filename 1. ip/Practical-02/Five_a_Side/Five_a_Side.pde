size(200,300);

background (90,255,120);

stroke(255);
noFill();
strokeWeight(2);

ellipse(width/2,35,50,50);
ellipse(width/2,265,50,50);
arc(10,10,10,10,0,HALF_PI);
arc(190,10,10,10,HALF_PI,PI);
arc(10,290,10,10,PI+HALF_PI,TWO_PI);
arc(190,290,10,10,PI,PI+HALF_PI);

noStroke();
fill(90,255,120);
rect(30,10,130,40);
rect(30,250,130,40);

noFill();
stroke(255);
strokeWeight(2);
rect (10,10,width-20,height-20);
ellipse(width/2,height/2, 70, 70);
line(0,height/2,width,height/2);

rect (50,10,100,40);
rect (75,10,50,15);
rect (50,250,100,40);
rect (75,275,50,15);
rect (90,2,20,8);
rect (90,290,20,8);

strokeWeight(6);
point(width/2,height/2);

strokeWeight(13);
int ejex; 
int ejey; 

stroke (255,0,0);
point(width/2,17);
stroke (0,0,255);
point(width/2,282);
stroke(255);
strokeWeight(11);
point(width/2+10,282-10);
strokeWeight(13);

for (int i=0; i<4;i=i+1) 
{
  ejex = int(random(40,width-20));
  ejey = int(random(60,height-40));
  stroke (255,0,0);    
  point (ejex,ejey);
  stroke (0,0,255);    
  point (ejex-30,ejey-30);
}