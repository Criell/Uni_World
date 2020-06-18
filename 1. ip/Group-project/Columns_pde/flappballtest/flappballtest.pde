float collisioncheckmouseclickball1=0;//checks if columns are close enough to hit ball
float collisioncheckmouseclickcolumn1;//checks end of top 'column'
float collisioncheckmouseclickcolumn2;//checks end of bottom 'column'
int collisioncheckmouseclickcolumn3=1;//checks whether ball is safely between 'columns'

int checkmouseclick=0;//mouse click for jump up
int checkmouseclick2=0;//ensures jump lasts a certain number of frames
float speedcounter;//counts frames for speed calculation
float speed;//frames divided by 6 for speed

int score;//starting score
int level;
int state=0;//game menu/other states

float startingbirbx;
float startingbirby;

Columns c1;
Columns c2;
Columns c3;
Columns c4;
Birb b1;

int size;
int gree_pill_x;
int gree_pill_y;
int red_pill_x;
int red_pill_y;

//NEW CODE: Created global variable for void draw to access and run check instead of update to run check
void setup() {
  size(600, 600);
  background(255);
  frameRate(30);
  
  score=0;
  startingbirbx=width;
  startingbirby=height;
  
  c1 = new Columns(startingbirbx/3, 0, 600, #FFCC00, 0);
  c2 = new Columns(startingbirbx/3, 0, 600, #FFFFFF, 1);
  c3 = new Columns(startingbirbx*13/12, 0, 600, #0F23A2, 0);
  c4 = new Columns(startingbirbx*13/12, 0, 200, #FFFFFF, 1);
  b1 = new Birb(startingbirbx/2, startingbirby/2);
}


//NEW CODE: Removed floats xPos, yPos and heigh to make them global variables
class Columns {
  float valx, tru, xPos, yPos, heigh;
  color basic;
  Columns (float xStart, float yStart, float high, color base, int truth) {
    valx = -5;
    xPos = xStart;
    yPos = yStart;
    heigh=high;
    tru=truth;
    basic=base;
  }
  
void update() {
    xPos = xPos+valx;
    noStroke();
    fill(basic);
      rect(xPos, yPos, 30, heigh);
      
      if (xPos==-15) {
        xPos=width+20;
        if (tru==1) {
          heigh=random(100, 251);
          yPos=random(0, startingbirby-heigh);
        }
      }
      
      if (xPos<=width/2+25 && xPos>=width/2-30) {
        collisioncheckmouseclickball1=1;
        collisioncheckmouseclickcolumn1=yPos;
        collisioncheckmouseclickcolumn2=yPos+heigh;
        
        if (b1.yPos1-25>collisioncheckmouseclickcolumn1 && b1.yPos1+25<collisioncheckmouseclickcolumn2){
          collisioncheckmouseclickcolumn3=1;
        } 
        else {
          collisioncheckmouseclickcolumn3=0;
        }
      } 
    }
  }
  
  
  //NEW CODE: Changing yPos to yPos1 and xPos to xPos1 to
  //then create global variable for xPos and yPos in Columns class
  
  class Birb {
    float xPos1, yPos1, valy, valx;
    
    Birb (float xStart, float yStart) {
      valx=0;
      valy=speed;
      xPos1 = xStart;
      yPos1 = yStart;
    }
  
    void update() {
      
      if (checkmouseclick==1 && checkmouseclick2!=5) {
        speedcounter=-33;
        checkmouseclick2++;
        
        if (checkmouseclick2==5) {
          checkmouseclick=0;
          checkmouseclick2=0;
          valy=speed;
        }
      }
      
      speedcounter=speedcounter+3;
      speed=speedcounter/6;
     
      if (speed>20) {
        speed=20.0;
      }
      
      valy=speed;
      xPos1 = xPos1+valx;
      yPos1 = yPos1+valy;
      
      if (yPos1>575) {
        yPos1=575;
      }
      
      if (yPos1<25) {
        yPos1=25;
      }
      
      fill(255, 0, 0);
      ellipse(xPos1, yPos1, size, size);
    }
   
  }
  
  
  
  void draw() {  
    //start menu
    if (state==0) {
      stroke(0);
      fill(255);
      rect(0, 0, width, height);
      rect(width/3, height/6, width/3, height*2/3);
      rect(width*7/15, height*16/25, width/15, height/20);
      fill(0);
      text("Flappy Birb", width/2, height/4);
      text("Play", width*12/25, height*17/25);
    }
   
    //gameplay state
    else {       
      
      if (collisioncheckmouseclickball1==1) {
        
        //what to do if ball passes between columns
        if (collisioncheckmouseclickcolumn3==1) {
          
          fill(255);
          rect(0, 0, width, height);
          c1.update();
          c2.update();
          
          if (level>=1) {
            c3.update();
            c4.update();
          }
          
          b1.update();
          
          red_pill();
          green_pill();
          
          score=score+1;
          level=floor(score/6);
          text("Score: "+score/6, 10, 10);
          text("Level: "+level+1, 10, 20);
          collisioncheckmouseclickball1=0;
          collisioncheckmouseclickcolumn3=0;
        }
        
        //what to do if the ball does not pass between columns
        else {
          fill(255);
          rect(width/4, height/4, width/2, height/2);
          fill(0);
          text("Lol game over fam nice try", width/2-50, height/2);
          state=2;
        }
      } 
      
      //what to do while ball is not close to columns
      else {
        fill(255);
        rect(0, 0, width, height);
        c1.update();
        c2.update();
        if (level>=1) {
          c3.update();
          c4.update();
        }
        b1.update();
        
        red_pill();
        green_pill();
        
        }
      }    
    } 


void green_pill(){
  if (level > 0){
    if (gree_pill_x <= -width*2){
       gree_pill_x = width + 200;
       gree_pill_y = int(random(50,height-50));
    }
      
    gree_pill_x = gree_pill_x - 7; 
    
    fill(0,150,0);
    ellipse(gree_pill_x,gree_pill_y,10,10);
    if((abs(b1.xPos1 - gree_pill_x) < 20) && (abs(b1.yPos1 - gree_pill_y) < 20)){
       gree_pill_y = -20;
       size = 20;    
    }
  }
}


void red_pill(){
  if (level > 0){
    if (red_pill_x <= -width*2){
       red_pill_x = width;
       red_pill_y = int(random(50,height-50));
    }
    
    if (red_pill_x <= -300){
       size = 50;
    }
      
    red_pill_x = red_pill_x - 10; 
    
    fill(150,0,0);
    rect(red_pill_x,red_pill_y,10,10);
    if((abs(b1.xPos1 - red_pill_x) < 20) && (abs(b1.yPos1 - red_pill_y) < 20)){
        red_pill_y = -20;
      }
     
    if (red_pill_y == -20){
        rect(0, height-10, width,10);
        println(b1.yPos1,height-5);    
        if(b1.yPos1 >= height-30){      
          fill(255);
          rect(width/4, height/4, width/2, height/2);
          fill(0);
          text("Lol game over fam nice try", width/2-50, height/2);
          state=2;
        }
    }
    
    
  }
}
  
  
  void mouseClicked() {
    
    //start game
    if (state==0) {
      if (mouseX<width*8/15 && mouseX>width*7/15 && mouseY<height*69/100 &&mouseY>height*16/25) {
        state=1;
        score=0;
        
        gree_pill_y = int(random(50,height-50));
        gree_pill_x = width;
        red_pill_y = int(random(50,height-50));
        red_pill_x = width+200;
        size = 50;
      }
    }
   
    //click event which pushes ball up
    else if (state==1) {
      checkmouseclick=1;
      speedcounter=0;
    }
    
    //restart game after loss
    else {
      if (mouseX<width*3/4 && mouseX>width/4 && mouseY<height*3/4 && mouseY>height/4) {
        state=0;
        b1.yPos1=300;
        c1.xPos=620;
        c2.xPos=620;
        c3.xPos=650;
        c4.xPos=650;
        collisioncheckmouseclickcolumn3=0;
        collisioncheckmouseclickball1=0;
        score=0;
        level=0;
        
        gree_pill_y = int(random(50,height-50));
        gree_pill_x = width;
        red_pill_y = int(random(50,height-50));
        red_pill_x = width+200;
        size = 50;
 
      }
    }
  }