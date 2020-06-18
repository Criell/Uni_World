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
      speedcounter=-(height/15 + height/200);
      checkmouseclick2++;
      if (checkmouseclick2==5) {
        checkmouseclick=0;
        checkmouseclick2=0;
        valy=speed;
      }
    }
    speedcounter=speedcounter+(height/200);
    speed=speedcounter/6;
    if (speed>20) {
      speed=20.0;
    }
    valy=speed;
    xPos1 = xPos1+valx;
    yPos1 = mouseY;//yPos1+valy;
    if (yPos1>=height) {
      yPos1=height;
    }
    if (yPos1<height/24) {
      yPos1=height/24;
    }
    imageMode(CORNER);
    image(img,xPos1-size, yPos1-size, size, size);
  }
}