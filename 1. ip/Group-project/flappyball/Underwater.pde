class BgUWBub {
  float valx, valy, xPos, yPos, size;
  //Valx and y's are classwide speeds for void, xpos for each object,
  //colswitches hold fish colour choice, varspeedx and y are for scaling
  //speed as a percentage of a variable width and height
  BgUWBub (float xStart, float yStart, float sized) {
    valx=(2)*-1;
    valy=(2)*-1;
    xPos=xStart;
    yPos=yStart;
    size=sized;
  }
  //^variable speed, xpos and ypos for update
  void update() {
    counter++;
    if (counter>=limit) {
      valx=-valx;
      counter=0;
      limit=int(random(31));
    }
    xPos=xPos+valx;
    yPos=yPos+valy;
    noStroke();
    fill(bubble1);
    ellipse(xPos,yPos,ssq/size,ssq/size);
    fill(bubble2);
    ellipse(xPos,yPos,(9*ssq)/(size*10),(9*ssq)/(size*10));
    if (xPos<=0 || yPos<=0 || xPos>=width) {
      xPos=random(width/size,width-5);
      yPos=random(height/size,height-5);
    }
  }
}

class BgUWFish {
  float xPos1, yPos1, colswitcha, colswitchb, varspeedx, varspeedy, 
  valx1, valy, size, kin;
   BgUWFish (float xStart, float yStart, float kind) {
    valx1=(-(width/300));
    valy=(-(width/300));
    xPos1=xStart;
    yPos1=yStart;
    kin=kind;
  }
void update() {
    counter1++;
    if (counter1>=limita) {
      valy=-valy;
      counter1=0;
      limita=int(random(61));
    }
    xPos1=xPos1+valx1;
    yPos1=yPos1+valy;
    if (kin==0) {
    fill(#FF7400);
    stroke(#FF7400);
    rect(xPos1,yPos1,ssq/120,ssq/120);
    rect(xPos1+ssq/120,yPos1,ssq/120,ssq/60);
    rect(xPos1+(9*ssq/120),yPos1-ssq/120,ssq/120,ssq/40);
    rect(xPos1+(11*ssq/120),yPos1-ssq/120,ssq/120,ssq/40);
    rect(xPos1+ssq/10,yPos1-ssq/60,ssq/120,ssq/24);
    fill(0);
    rect(xPos1+ssq/120,yPos1-ssq/120,ssq/120,ssq/120);
    fill(255);
    stroke(255);
    rect(xPos1+ssq/12,yPos1,ssq/120,ssq/120);
    for (int i=0; i<7; i++) {
      color a;
      if (i%2==0) {
        a=#FFFFFF;
      }
      else {
        a=#FF7400;
      }
      fill(a);
      stroke(a);
      rect(xPos1+ssq/60+(i*ssq/120),yPos1-ssq/60,ssq/120,ssq/24);
    }
    fill(#FF7400);
    stroke(#FF7400);
    rect(xPos1+ssq/30,yPos1,ssq/120,ssq/60);
    }
    else if (kin==1) {
      fill(#FFF41C);
      stroke(#FFF41C);
      rect(xPos1,yPos1,2*ssq/15,ssq/120);
      rect(xPos1+ssq/120,yPos1-ssq/120,ssq*13/120,ssq/40);
      rect(xPos1+ssq/60,yPos1-ssq/60,ssq/10,ssq/120);
      rect(xPos1+ssq/40,yPos1+ssq/60,ssq/12,ssq/120);
      color a;
      for (int i=0; i<5; i++) {
          a=#2F3FEB;
        fill(a);
        stroke(a);
        rect(xPos1+ssq/30+(i*ssq/60),yPos1-ssq/60,ssq/120,ssq/24);
        if (i<3) {
          fill(#FFF41C);
          stroke(#FFF41C);
          rect(xPos1+(7*ssq/60)+(i*ssq/120),yPos1-ssq/120-(i*ssq/120),ssq/60,ssq/60);
          rect(xPos1+(7*ssq/60)+(i*ssq/120),yPos1-ssq/120+(i*ssq/120),ssq/60,ssq/60);
        }
      }
      fill(#FFF41C);
      stroke(#FFF41C);
      rect(xPos1+ssq/15,yPos1-ssq/120,ssq/120,ssq/60);
      fill(0);
      stroke(0);
      rect(xPos1+ssq/60,yPos1-ssq/120,ssq/120,ssq/120);
    }
    else {
      fill(255);
      stroke(255);
      rect(xPos1,yPos1,ssq/120,ssq/60);
      rect(xPos1+ssq/120,yPos1-ssq/120,ssq/60,ssq/30);
      rect(xPos1+ssq/24,yPos1-ssq/60,ssq/60,ssq/20);
      rect(xPos1+ssq/12,yPos1-ssq/60,ssq/120,7*ssq/120);
      fill(#FFFF88);
      stroke(#FFFF88);
      rect(xPos1+(7*ssq/120),yPos1-ssq/60,ssq/120,ssq/20);
      fill(0);
      stroke(0);
      rect(xPos1+ssq/40,yPos1-ssq/60,ssq/60,ssq/20);
      rect(xPos1+ssq/15,yPos1-ssq/60,ssq/60,ssq/15);
      rect(xPos1+(11*ssq/120),yPos1,ssq/120,ssq/60);
      rect(xPos1+ssq/10,yPos1-ssq/120,ssq/120,ssq/30);
      rect(xPos1+ssq/120,yPos1,ssq/120,ssq/120);
      rect(xPos1+(13*ssq/120),yPos1-ssq/60,ssq/120,ssq/120);
      rect(xPos1+(13*ssq/120),yPos1+ssq/40,ssq/120,ssq/120);
      rect(xPos1+(3*ssq/40),yPos1+ssq/20,ssq/120,ssq/120);
    }
    if (xPos1<=-(13*width/120)) {
      xPos1=width*65/64;
      yPos1=random(0,height-5);
      kin=int(random(0,3));
    }
    if (yPos1<=0) {
      yPos1=height;
    }
    else if (yPos1>=height) {
      yPos1=0;
    }
  }
}