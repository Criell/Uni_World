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
int state=0;//game menu/other states
float x;
float y;
float ssq;
int counter;
int counter1;
int limit;
int limita;
int limitb;
color back;
color bubble1;
color bubble2;
PImage img;
BgUWBub bub1;
BgUWBub bub2;
BgUWBub bub3;
BgUWBub bub4;
BgUWBub bub5;
BgUWBub bub6;
BgUWFish f1;
BgUWFish f2;
BgUWFish f3;
BgUWFish f4;
BgUWFish f5;
BgUWFish f6;
TwinklingStars ts1;
TwinklingStars ts2;
TwinklingStars ts3;
TwinklingStars ts4;
TwinklingStars ts5;
TwinklingStars ts6;
TwinklingStars ts7;
TwinklingStars ts8;
TwinklingStars ts9;
TwinklingStars ts10;
TwinklingStars ts11;

Columns c1;
Columns c2;
Columns c3;
Columns c4;
Birb b1;
Buildingone bld1;
Buildingtwo bld2;
Buildingthree bld3;

trees t1;
trees t2;
trees t3;
trees t4;
float size;
int gree_pill_x;
int gree_pill_y;
int red_pill_x;
int red_pill_y;
int[][] test= new int[][] {{1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0}, 
  {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1}, 
  {0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0}, 
  {0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1}, 
  {1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0}, 
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
  {1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1}, 
  {0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0}, 
  {0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1}, 
  {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0}, 
  {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0}, 
};
//NEW CODE: Created global variable for void draw to access and run check instead of update to run check
void setup() {
  fullScreen();
  background(255);
  frameRate(30);
  img = loadImage("flappybird_topic.png");
  if (width>height) {
    ssq=height;
  } else {
    ssq=width;
  }
  score=0;
  x=width;
  y=height;
  c1 = new Columns(x, 0, height/4, #FFCC00);
  c2 = new Columns(x, 0, height/4, #FFFFFF);
  c3 = new Columns(1.25*x, 0, height/4, #0F23A2);
  c4 = new Columns(2.4*x, 0, height/4, #FC1C1C);
  b1 = new Birb(x/2, y/2);
  bld1= new Buildingone(x*0.04, 1); //xpos
  bld2= new Buildingtwo(x*0.2, 1); //xpostwo
  bld3= new Buildingthree(x*0.6, 1); //xposthree
  back=#82C2F2;
  bubble1=#CFE9FC;
  bubble2=#AEDAFA;
  bub1 = new BgUWBub(width/2, height/2, 20);
  bub2 = new BgUWBub(width/2, height/2, 20);
  bub3 = new BgUWBub(width/2, height/2, 20);
  bub4 = new BgUWBub(width/2, height/2, 20);
  bub5 = new BgUWBub(width/2, height/2, 20);
  bub6 = new BgUWBub(width/2, height/2, 20);
  f1 = new BgUWFish(x*0.1, y*0.1, 0);
  f2 = new BgUWFish(x*0.2, y*0.2, 1);
  f3 = new BgUWFish(x*0.3, y*0.3, 2);
  f4 = new BgUWFish(x*0.4, y*0.4, 0);
  f5 = new BgUWFish(x*0.5, y*0.5, 1);
  f6 = new BgUWFish(x*0.6, y*0.6, 2);  
  ts1 = new TwinklingStars(width/10*0);
  ts2 = new TwinklingStars(width/10*1);
  ts3 = new TwinklingStars(width/10*2);
  ts4 = new TwinklingStars(width/10*3);
  ts5 = new TwinklingStars(width/10*4);
  ts6 = new TwinklingStars(width/10*5);
  ts7 = new TwinklingStars(width/10*6);
  ts8 = new TwinklingStars(width/10*7);
  ts9 = new TwinklingStars(width/10*8);
  ts10 = new TwinklingStars(width/10*9);
  ts11 = new TwinklingStars(width);
  t1=new trees(width*0.9, 10);
  t2=new trees(width*0.7, 10);
  t3=new trees(width*0.5, 10);
  t4=new trees(width*0.3, 10);
  counter=0;
  counter1=0;
  limit=10;
  limita=10;
  limitb=10;
  size=height/24;
}
//NEW CODE: Removed floats xPos, yPos and heigh to make them global variables
//NEW CODE: Changing yPos to yPos1 and xPos to xPos1 to
//then create global variable for xPos and yPos in Columns class
void ground() {
  fill(0);
  rect(0, ssq/1.2, width, height/20);
  fill(0);
  rect(0, ssq/1.154, width, width/1);
}

void draw() {
  if (state==0) {
    // stroke(0);
    fill(#89d8f0);
    rect(0, 0, width, height);
    //   fill(0,100,0);
    rect(ssq/3, height/6, ssq/3, height*2/3);
    // rect(ssq*7/15, height*16/25, width/15, height/20,7);
    bld1.update();
    bld2.update();
    bld3.update();
    ground();
    fill(0);
    //text("Flappy Birb", width/2, height/4);
    for (int i=0; i<10; i++) {
      rect(width*12/32, width*12/50+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<5; i++) {
      rect(width*12/32+(i*(width/120)), width*12/50, (width/120), (width/120));
    }
    for (int i=0; i<5; i++) {
      rect(width*12/32+(i*(width/120)), width*12/44, (width/120), (width/120));
    }

    for (int i=0; i<10; i++) {
      rect(width*12/28, width*12/50+(i*(width/120)), (width/120), (width/120));
    }

    //a 
    rect(width*12/26.5, width*12/39, (width/120), (width/120));
    rect(width*12/26.5, width*12/40, (width/120), (width/120));
    rect(width*12/26.5, width*12/41, (width/120), (width/120));

    for (int i=0; i<4; i++) {
      rect(width*12/26+(i*(width/120)), width*12/38, (width/120), (width/120));
    }
    for (int i=0; i<3; i++) {
      rect(width*12/26+(i*(width/120)), width*12/42, (width/120), (width/120));
    }
    for (int i=0; i<3; i++) {
      rect(width*12/26+(i*(width/120)), width*12/45, (width/120), (width/120));
    }
    //vertical
    for (int i=0; i<6; i++) {
      rect(width*12/25, width*12/44+(i*(width/120)), (width/120), (width/120));
    }

    //p 
    for (int i=0; i<10; i++) {
      rect(width*12/23.5, width*12/44+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/23.5+(i*(width/120)), width*12/45, (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/23.5+(i*(width/120)), width*12/38, (width/120), (width/120));
    }
    for (int i=0; i<5; i++) {
      rect(width*12/22.2, width*12/43.5+(i*(width/120)), (width/120), (width/120));
    }

    //p2
    for (int i=0; i<10; i++) {
      rect(width*12/21.5, width*12/44+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/21.5+(i*(width/120)), width*12/45, (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/21.5+(i*(width/120)), width*12/38, (width/120), (width/120));
    }
    for (int i=0; i<5; i++) {
      rect(width*12/20.4, width*12/43.5+(i*(width/120)), (width/120), (width/120));
    }

    //y 
    for (int i=0; i<6; i++) {
      rect(width*12/19.7, width*12/45+(i*(width/120)), (width/120), (width/120));
    }

    for (int i=0; i<4; i++) {
      rect(width*12/19.5+(i*(width/120)), width*12/38, (width/120), (width/120));
    }
    for (int i=0; i<10; i++) {
      rect(width*12/18.5, width*12/45+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/19.5+(i*(width/120)), width*12/35, (width/120), (width/120));
    }

    //Q
    for (int i=0; i<6; i++) {
      rect(width*12/33, width*12/30+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/32.1+(i*(width/120)), width*12/30.5, (width/120), (width/120));
    }
    for (int i=0; i<6; i++) {
      rect(width*12/29.5, width*12/30+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/32.1+(i*(width/120)), width*12/26.5, (width/120), (width/120));
    }

    for (int i=0; i<4; i++) {
      rect(width*12/31+(i*(width/120)), width*12/28+(i*(width/120)), (width/120), (width/120));
    }
    //u
    for (int i=0; i<4; i++) {
      rect(width*12/27, width*12/28.5+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<5; i++) {
      rect(width*12/27+(i*(width/120)), width*12/26.5, (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/25.1, width*12/28.5+(i*(width/120)), (width/120), (width/120));
    }
    //e
    for (int i=0; i<5; i++) {
      rect(width*12/24, width*12/28.5+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/24+(i*(width/120)), width*12/26.4, (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/24+(i*(width/120)), width*12/27.5, (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/24+(i*(width/120)), width*12/28.5, (width/120), (width/120));
    }
    //s 
    for (int i=0; i<4; i++) {
      rect(width*12/22+(i*(width/120)), width*12/28.5, (width/120), (width/120));
    }
    rect(width*12/22, width*12/28, (width/120), (width/120));
    for (int i=0; i<4; i++) {
      rect(width*12/22+(i*(width/120)), width*12/27.5, (width/120), (width/120));
    }
    rect(width*12/21, width*12/27, (width/120), (width/120));
    for (int i=0; i<4; i++) {
      rect(width*12/22+(i*(width/120)), width*12/26.5, (width/120), (width/120));
    }

    //t 
    for (int i=0; i<5; i++) {
      rect(width*12/19.8, width*12/28.5+(i*(width/120)), (width/120), (width/120));
    }
    for (int i=0; i<4; i++) {
      rect(width*12/20.2+(i*(width/120)), width*12/28.5, (width/120), (width/120));
    }
    //  text("Play", width*12/25, height*17/25);
    fill(245);
    rect(width*7/15, height*16/25, width/15, height/20, 7);
    fill(0, 200, 0);
    triangle(width*12/24.5, height*12/18.3, width*12/24.5, height*12/17.7, width*12/23.5, height*12/17.95);
  }//start menu
  else {
    if (collisioncheckmouseclickball1==1) {
      if (collisioncheckmouseclickcolumn3==1) {
        if (level<1) {
          fill(#000080);
          rect(0, 0, width, height);
          bld1.update();
          bld2.update();
          bld3.update();
          ground();
          c1.update();
        } else if (level==1) {
          fill(0, 0, 255);
          rect(0, 0, width, height);
          bub1.update();
          bub2.update();
          bub3.update();
          bub4.update();
          bub5.update();
          bub6.update();
          f1.update();
          f2.update();
          f3.update();
          f4.update();
          f5.update();
          f6.update();
          c1.update();
          c2.update();
        } else if (level==2) {
          fill(50, 200, 20);
          rect(0, 0, width, height);
          t1.update();
          t2.update();
          t3.update();
          t4.update();
          c1.update();
          c2.update();
          c3.update();
        } else if (level>2) {
          fill(0);
          rect(0, 0, width, height);
          ts1.update();
          ts2.update();
          ts3.update();
          ts4.update();
          ts5.update();
          ts6.update();
          ts7.update();
          ts8.update();
          ts9.update();
          ts10.update();
          ts11.update();
          c1.update();
          c2.update();
          c3.update();
          c4.update();
        }
        b1.update();
        red_pill();
        green_pill();
        score=score+1;
        level=floor(score/50);
        text("Score: "+score/5, 10, 10);
        text("Level: "+level, 10, 20);
        collisioncheckmouseclickball1=0;
        collisioncheckmouseclickcolumn3=0;
      }//what to do if ball passes between columns
      else {
        for (int i=0; i<11; i++) {
          for (int j=0; j<test[i].length; j++) {
            if (test[i][j]==0) {
              fill(200);
              rect((width/2)-100+(10*j), (height/2)-100+(10*i), 10, 10);
            }
            state=2;
          }//what to do if the ball does not pass between columns
        }
      }//what to do if the ball does not pass between columns
    } else {
      if (level<1) {
        fill(#000080);
        rect(0, 0, width, height);
        bld1.update();
        bld2.update();
        bld3.update();
        ground();
        c1.update();
      } else if (level==1) {
        fill(0, 0, 255);
        rect(0, 0, width, height);
        bub1.update();
        bub2.update();
        bub3.update();
        bub4.update();
        bub5.update();
        bub6.update();
        f1.update();
        f2.update();
        f3.update();
        f4.update();
        f5.update();
        f6.update();
        c1.update();
        c2.update();
      } else if (level==2) {
        fill(50, 200, 20);
        rect(0, 0, width, height);
        t1.update();
        t2.update();
        t3.update();
        t4.update();
        c1.update();
        c2.update();
        c3.update();
      } else if (level>2) {
        fill(0);
        rect(0, 0, width, height);
        ts1.update();
        ts2.update();
        ts3.update();
        ts4.update();
        ts5.update();
        ts6.update();
        ts7.update();
        ts8.update();
        ts9.update();
        ts10.update();
        ts11.update();
        c1.update();
        c2.update();
        c3.update();
        c4.update();
      }
      b1.update();
      red_pill();
      green_pill();
      text("Score: "+score/5, 10, 10);
      text("Level: "+level, 10, 20);
    }//what to do while ball is not close to columns
  }//gameplay state
}
void mouseClicked() {
  if (state==0) {
    if (mouseX<width*8/15 && mouseX>width*7/15 && mouseY<height*69/100 &&mouseY>height*16/25) {
      state=1;
      score=0;
      gree_pill_y = int(random(50, height-50));
      gree_pill_x = width;
      red_pill_y = int(random(50, height-50));
      red_pill_x = width+200;
      size = height/24;
    }
  }//start game
  else if (state==1) {
    checkmouseclick=1;
    speedcounter=0;
  }//click event which pushes ball up
  else {
    if (mouseX<width*3/4 && mouseX>width/4 && mouseY<height*3/4 && mouseY>height/4) {
      state=0;

      gree_pill_y = int(random(50, height-50));
      gree_pill_x = width;
      red_pill_y = int(random(50, height-50));
      red_pill_x = width+200;
      size = height/24;

      float[] randomiseheight = new float[5];
      float[] randomisegap = new float[5];
      for (int i=0; i<5; i++) {
        float lim=0;
        randomiseheight[i]=random(0, 500.001);
        if (randomiseheight[i]<350) {
          lim=251;
        } else {
          lim=width-randomiseheight[i];
        }
        randomisegap[i]=random(100, lim);
      }
      b1.yPos1=x/2;
      c1.xPos=x;
      c1.heigh=randomiseheight[0];
      c1.gap=randomisegap[0];
      c2.xPos=x;
      c2.heigh=randomiseheight[1];
      c2.gap=randomisegap[1];
      c3.xPos=x*1.25;
      c3.heigh=randomiseheight[2];
      c3.gap=randomisegap[2];
      c4.xPos=x*2.4;
      c4.heigh=randomiseheight[3];
      c4.gap=randomisegap[3];
      collisioncheckmouseclickcolumn3=0;
      collisioncheckmouseclickball1=0;
      score=0;
      level=0;
    }
  }//restart game after loss
}