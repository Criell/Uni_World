class Columns {
  float valx, tru, xPos, yPos, heigh, gap, lim;
  color basic;
  Columns (float xStart, float yStart, float high, color base) {
    valx=-(width/120);
    xPos = xStart;
    yPos = yStart;
    heigh=high;
    basic=base;
    gap=ssq/6;
  }
  void update() {
    xPos = xPos+valx;
    noStroke();
    fill(basic);
    rect(xPos, yPos, width/20, heigh);
    rect(xPos, heigh+gap, width/20, height-heigh-gap);
    if (xPos<=-(width/20)) {
      xPos=width+width/20;
      heigh=random(0,5*height/6);
      if (heigh<=7*height/12) {
        lim=(5*height/12)+1;
      }
      else {
        lim=height-heigh;
      }
      gap=int(random(height/6,lim));
    }
    if (xPos<=width/2 && xPos>=width/2-(width/20)-size) {
      collisioncheckmouseclickball1=1;
      collisioncheckmouseclickcolumn1=heigh;
      collisioncheckmouseclickcolumn2=heigh+gap;
      if (b1.yPos1-size>collisioncheckmouseclickcolumn1 && b1.yPos1<collisioncheckmouseclickcolumn2) {
        collisioncheckmouseclickcolumn3=1;
      } else {
        collisioncheckmouseclickcolumn3=0;
      }
    }
  }
}