trees t1;
trees t2;
trees t3;
trees t4;


void setup() {
  size(600,600);
  frameRate(30);
  t1=new trees(width*0.9,1,10);
  t2=new trees(width*0.7,1,10);
  t3=new trees(width*0.5,1,10);
  t4=new trees(width*0.3,1,10);
}
class trees {
  float xPos, yPos, valx, tall;
  float[] left, right, leftrnd, rightrnd;
  trees (float xStart, int kind, int reach) {
    xPos=xStart;
    valx=width/120*-1;
    yPos=height;
    tall=reach;
    left=new float[10];
    right=new float[10];
    leftrnd=new float[10];
    rightrnd=new float[10];
    for (int i=0; i<10; i++) {
      int a=floor(random(0,2));
      int b=floor(random(0,2));
      float c=random(0,1);
      float d=random(0,1);
      left[i]=a;
      right[i]=b;
      leftrnd[i]=c;
      rightrnd[i]=d;
    }
  }
  void update() {
    xPos=xPos+valx;
    fill(255,0,0);
    stroke(255,0,0);
    rect(xPos, yPos-(height/20*tall), width/20, height/20*tall);
    fill(0,255,0);
    stroke(0,255,0);
    for (int i=0; i<tall-5; i++) {
      if (right[i]==0 && tall>5) {
        rect(xPos+width/20,yPos-(height/4)-(height/20*i)-(height/25*rightrnd[i])-height/300,width/300,height/300);
        rect(xPos+width/20+width/300,yPos-(height/4)-(height/20*i)-(height/25*rightrnd[i])-height/150,width/300,height/300);
        rect(xPos+width/20+width/150,yPos-(height/4)-(height/20*i)-(height/25*rightrnd[i])-height/75,width/60,height/150);
      }
      if (left[i]==0 && tall>5) {
        rect(xPos-width/300,yPos-(height/4)-(height/20*i)-(height/25*rightrnd[i])-height/300,width/300,height/300);
        rect(xPos-width/150,yPos-(height/4)-(height/20*i)-(height/25*rightrnd[i])-height/150,width/300,height/300);
        rect(xPos-7*width/300,yPos-(height/4)-(height/20*i)-(height/25*rightrnd[i])-height/75,width/60,height/150);
      }
    }
    for (int i=0; i<5; i++) {
      float n=tall%4;
      if (n<1) {
        n=1;
      }
      rect(xPos-width/20,yPos-(height/20*(tall+n)),width*3/20,height/20*n);
    }
    if (xPos==0-width/20) {
      xPos=width;
      tall=int(random(5,16));
      for (int i=0; i<10; i++) {
      int a=floor(random(0,2));
      int b=floor(random(0,2));
      float c=random(0,1);
      float d=random(0,1);
      left[i]=a;
      right[i]=b;
      leftrnd[i]=c;
      rightrnd[i]=d;
    }
    }
  }
}

void draw() {
  fill(50,200,20);
  stroke(255);
  rect(0,0,width,height);
  t1.update();
  t2.update();
  t3.update();
  t4.update();
}