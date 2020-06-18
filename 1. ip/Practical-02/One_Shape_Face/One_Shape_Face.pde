size(500,500);

int x= width/2;
int y= height /2;

int a = width/2;
int a_2 = a/2;
int a_3 = a/3;
int a_4 = a/4;
int a_5 = a/5;

int b = height/2;
int b_2 = b/2;
int b_3 = b/3;
int b_4 = b/4;

//hears
fill(0);
ellipse (x+a_2+-20,y-a_2+30,a_2,b-80);
ellipse (x-a_2+20,y-a_2+30,a_2,b-80);

fill(255);

//face
strokeWeight(6);
ellipse (x,y,a,b);

fill(0);
stroke(0);
strokeWeight(1);
//eyes
ellipse (x+a_4,y-20,a_4-10,b_3-10);
ellipse (x-a_4,y-20,a_4-10,b_3-10);

//seconds eyes
fill(255);
noStroke();
ellipse (x+a_4,y+a_5-40,a_4-10,b_3-10);
ellipse (x-a_4,y+a_5-40,a_4-10,b_3-10);

//nose
fill(255);
stroke(0);
strokeWeight(6);
ellipse (x,y+a_3,a_2+40,b_2+40);

//mouth
noFill();
stroke(10);
strokeWeight (3);
ellipse (x,y+a_2-40,a_2-10,b_2-10);

fill(255);
noStroke();
ellipse (x,y+a_2-60,a_2-5,b_2-10);

//holes nose
fill(255,0,0);
ellipse (x+a_4-25,y+a_5,a_5-20,b_4-10);
ellipse (x-a_4+25,y+a_5,a_5-20,b_4-10);