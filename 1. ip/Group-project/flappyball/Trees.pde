class trees {
  float xPos, yPos, valx, tall;
  float[] left, right, leftrnd, rightrnd;
  trees (float xStart, int reach) {
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
    rect(xPos, yPos-(ssq/20*tall), ssq/20, ssq/20*tall);
    fill(0,255,0);
    stroke(0,255,0);
    for (int i=0; i<tall-5; i++) {
      if (right[i]==0 && tall>5) {
        rect(xPos+ssq/20,yPos-(ssq/4)-(ssq/20*i)-(ssq/25*rightrnd[i])-ssq/300,ssq/300,ssq/300);
        rect(xPos+ssq/20+ssq/300,yPos-(ssq/4)-(ssq/20*i)-(ssq/25*rightrnd[i])-ssq/150,ssq/300,ssq/300);
        rect(xPos+ssq/20+ssq/150,yPos-(ssq/4)-(ssq/20*i)-(ssq/25*rightrnd[i])-ssq/75,ssq/60,ssq/150);
      }
      if (left[i]==0 && tall>5) {
        rect(xPos-ssq/300,yPos-(ssq/4)-(ssq/20*i)-(ssq/25*rightrnd[i])-ssq/300,ssq/300,ssq/300);
        rect(xPos-ssq/150,yPos-(ssq/4)-(ssq/20*i)-(ssq/25*rightrnd[i])-ssq/150,ssq/300,ssq/300);
        rect(xPos-7*ssq/300,yPos-(ssq/4)-(ssq/20*i)-(ssq/25*rightrnd[i])-ssq/75,ssq/60,ssq/150);
      }
    }
    for (int i=0; i<5; i++) {
      float n=tall%4;
      if (n<1) {
        n=1;
      }
      rect(xPos-ssq/20,yPos-(ssq/20*(tall+n)),ssq*3/20,ssq/20*n);
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