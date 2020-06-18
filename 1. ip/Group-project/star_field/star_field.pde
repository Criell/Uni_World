int starcount;
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
void setup() {
  size(800,800);
  frameRate(30);
  starcount=0;
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
}
class TwinklingStars {
  float xPos, valx, tspd;
  float[] toggle, displacex, displacey, tnkspd, tnk;
  TwinklingStars (float Start) {
    xPos=Start;
    valx=-width/120;
    tspd=1;
    toggle= new float[0];
    displacex=new float[0];
    displacey=new float[0];
    tnkspd=new float[0];
    tnk=new float[10];
    for (int i=0; i<10; i++) {
      float a=floor(random(0,2));
      float b=floor(random(0,6));
      float c=floor(random(0,6));
      float d=floor(random(5,16));
      toggle=append(toggle,a);
      displacex=append(displacex,b);
      displacey=append(displacey,c);
      tnkspd=append(tnkspd,d);
      tnk=append(tnk,0);
    }
  }
  void update() {
    xPos=xPos+valx;
    if (xPos<(width/10)*-1) {
      xPos=width;
      for (int i=0; i<10; i++) {
      float a=floor(random(0,2));
      float b=floor(random(0,6));
      float c=floor(random(0,6));
      float d=floor(random(5,16));
      toggle[i]=a;
      displacex[i]=b;
      displacey[i]=c;
      tnkspd[i]=d;
      tnk=append(tnk,0);
      println(displacex);
    }
    }
    for (int i=0; i<10; i++) {
      if (toggle[i]==0) {
        tnk[i]=tnk[i]+tnkspd[i];
        if (tnk[i]>255) {
          tnk[i]=255;
          tnkspd[i]=tnkspd[i]*-1;
        }
        else if (tnk[i]<0) {
          tnk[i]=0;
          tnkspd[i]=tnkspd[i]*-1;
        }
        noStroke();
        fill(tnk[i]);
        rect(xPos+((displacex[i]+1.5)*width/100),i*height/10+((displacey[i]+1.5)*height/100),width/50,height/50);
        fill(255);
        rect(xPos+(width/50)+(displacex[i]*width/100),(i*height/10)+(height/50)+(displacey[i]*height/100),width/100,height/100);
      }
      else {//no star
      }
    }
  }
}

void draw() {
  fill(0);
  rect(0,0,width,height);
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
  fill(255,0,0);
}