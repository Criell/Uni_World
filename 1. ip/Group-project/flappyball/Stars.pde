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
        rect(xPos+((displacex[i]+1.5)*ssq/100),i*ssq/10+((displacey[i]+1.5)*ssq/100),ssq/50,ssq/50);
        fill(255);
        rect(xPos+(ssq/50)+(displacex[i]*ssq/100),(i*ssq/10)+(ssq/50)+(displacey[i]*ssq/100),ssq/100,ssq/100);
      }
      else {//no star
      }
    }
  }
}