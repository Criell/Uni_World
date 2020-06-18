int checkmouseclick=0;//mouse click for jump up
int checkmouseclick2=0;//ensures jump lasts a certain number of frames
float speedcounter;//counts frames for speed calculation
float speed;//frames divided by 6 for speed
float collisioncheckmouseclickball1=0;//checks if columns are close enough to hit ball
float collisioncheckmouseclickcolumn1;//checks end of top 'column'
float collisioncheckmouseclickcolumn2;//checks end of bottom 'column'
int collisioncheckmouseclickcolumn3=1;//checks whether ball is safely between 'columns'
int score;//starting score
int level;
int state=1;//game menu/other states
float x;
float y;
float screensquare;


Columns c1;
Columns c2;
Columns c3;
Columns c4;

//NEW CODE: Created global variable for void draw to access and run check instead of update to run check
void setup() {
  size(600,600);
  background(255);
  frameRate(30);
  if (width>height) {
    screensquare=height;
  }
  else {
    screensquare=width;
  }
  score=0;
  x=width;
  y=height;
  c1 = new Columns(x, 0, height/3, #FFCC00);
  c2 = new Columns(x, 0, height/3, #FFFFFF);
  c3 = new Columns(x*13/10, 0, height/3, #0F23A2);
  c4 = new Columns(x*17/10, 0, height/3, #FFFFFF);
}
//NEW CODE: Removed floats xPos, yPos and heigh to make them global variables
class Columns {
  float valx, tru, xPos, yPos, heigh, gap, lim;
  color basic;
  Columns (float xStart, float yStart, float high, color base) {
    valx=-5;
    xPos = xStart;
    yPos = yStart;
    heigh=high;
    basic=base;
    gap=width/6;
  }
  void update() {
    xPos = xPos+valx;
    noStroke();
    fill(basic);
    rect(xPos, yPos, width/20, heigh);
    rect(xPos, heigh+gap, width/20, width-heigh-gap);
    if (xPos==-(width/20)) {
      xPos=width+20;
      heigh=random(0,height*(5/6)+0.001);
      if (heigh<=7*width/12) {
        lim=251;
      }
      else {
        lim=width-heigh;
      }
      gap=random(100,lim);
    }
      
      }
    }
  



void draw() {

    if (collisioncheckmouseclickball1==1) {
      if (collisioncheckmouseclickcolumn3==1) {
        if (level<1) {
          fill(#000080);
          rect(0, 0, width, height);
          c1.update();
        }
        else if (level==1) {
          fill(0,0,255);
          rect(0, 0, width, height);
          
          c1.update();
          c2.update();
        }
        else if (level==2) {
          fill(50,200,20);
          rect(0,0,width,height);
          
          c1.update();
          c2.update();
          c3.update();
        }
        else if (level>2) {
          fill(0);
          rect(0,0,width,height);
          
          c1.update();
          c2.update();
          c3.update();
          c4.update();
          
        }
       
        text(checkmouseclick, width/2, height/2);
        text(speedcounter, width/2, height/2+10);
        text(speed, width/2, height/2+20);
        //text(valy,width/2,height/2+30);
        text(collisioncheckmouseclickcolumn1, width/2, height/2+40);
        text(collisioncheckmouseclickcolumn2, width/2, height/2+50);
        text(collisioncheckmouseclickcolumn3, width/2, height/2+60);
        text(collisioncheckmouseclickball1, width/2, height/2+70);
        text(x, width/2, height/2+80);
        text(y, width/2, height/2+90);
        score=score+10;
        level=floor(score/60);
        text("Score: "+score/6, 10, 10);
        text("Level: "+level, 10, 20);
        collisioncheckmouseclickball1=0;
        collisioncheckmouseclickcolumn3=0;
      }//what to do if ball passes between columns
      //what to do if the ball does not pass between columns
    } else {
      if (level<1) {
              fill(#000080);
      rect(0, 0, width, height);
          
          c1.update();
        }
      else if (level==1) {
        fill(0,0,255);
          rect(0, 0, width, height);
          
          c1.update();
          c2.update();
      }
      else if (level==2) {
          fill(50,200,20);
          rect(0,0,width,height);
          
          c1.update();
          c2.update();
          c3.update();
        }
        else if (level>2) {
          fill(0);
          rect(0,0,width,height);
          
          c1.update();
          c2.update();
          c3.update();
          c4.update();
        }
      
      text(checkmouseclick, width/2, height/2);
      text(speedcounter, width/2, height/2+10);
      text(speed, width/2, height/2+20);
      //text(valy,width/2,height/2+30);
      text(collisioncheckmouseclickcolumn1, width/2, height/2+40);
      text(collisioncheckmouseclickcolumn2, width/2, height/2+50);
      text(collisioncheckmouseclickcolumn3, width/2, height/2+60);
      text(collisioncheckmouseclickball1, width/2, height/2+70);
      text(x, width/2, height/2+80);
      text(y, width/2, height/2+90);
      text("Score: "+score/6, 10, 10);
      text("Level: "+level, 10, 20);
    }//what to do while ball is not close to columns
  }//gameplay state