class Buildingone {
  float xpos, speed;
  Buildingone(float x, float s) {
    xpos= x;
    speed= s;
  }

  void update() {
    fill(255);
    xpos-=speed;
    if (xpos<=-(width/6)) {
      xpos= width;
    }
    //wall 
    rect(xpos, ssq/2, ssq/40, ssq/3);
    rect(xpos+ssq/7, ssq/2, ssq/40, ssq/3);

    //roof
    noStroke();
    float sum=0;
    for (int k=0; k<7; k++) {
      rect(xpos+sum, ssq/2-sum, ssq/40, ssq/40);
      rect((xpos+ssq/7)-sum, ssq/2-sum, ssq/40, ssq/40);
      sum = sum+ssq/70;
    }

    //roof top
    rect(xpos+(ssq/18), ssq/2.4, ssq/20, ssq/20);

    //windows
    fill(#ffff00); // windows 
    float window=0;
    for (int j=0; j<4; j++) {
      rect(xpos+(ssq/20), ssq/1.80+window, ssq/60, ssq/30);
      rect(xpos+(ssq/10), ssq/1.80+window, ssq/60, ssq/30);
      window = window+ssq/20;
    }
  }
}

class Buildingtwo {
  float xpostwo, speed;
  Buildingtwo(float x, float s) {
    xpostwo= x;
    speed= s;
  }

  void update() {
    fill(255);
    xpostwo-=speed;
    if (xpostwo<=-(width/6)) {
      xpostwo= width;
    }
    //wall 
    rect(xpostwo+ssq/7, ssq/2, ssq/40, ssq/3);
    rect(xpostwo+ssq/3, ssq/2, ssq/40, ssq/3);
    //roof
    rect(xpostwo+ssq/6, ssq/2, ssq/6, ssq/60);
    //window 
    fill(#ffff00);
    float window=0;
    for (int j=0; j<4; j++) {
      rect(xpostwo+(ssq/5.55), ssq/1.80+window, ssq/30, ssq/30);
      rect(xpostwo+(ssq/3.57), ssq/1.80+window, ssq/30, ssq/30);
      window = window+ssq/20;
    }
  }
}

class Buildingthree {
  float xposthree, speed;
  Buildingthree(float x, float s) {
    xposthree= x;
    speed= s;
  }

  void update() {
    fill(255); 
    xposthree-=speed;
    if (xposthree<=-(width/6)) {
      xposthree= width;
    }
    //wall 
    rect(xposthree+ssq/7, ssq/2.3, ssq/40, ssq/2.5);
    rect(xposthree+ssq/3, ssq/2.3, ssq/40, ssq/2.5);

    fill(#ffff00); // windows 
    float window=0;
    for (int j=0; j<6; j++) {
      rect(xposthree+ssq/5.5, ssq/2.1+window, ssq/30, ssq/60);
      rect(xposthree+ssq/3.5, ssq/2.1+window, ssq/30, ssq/60);
      window = window+ssq/20;
    }
    fill(255);
    noStroke();
    //roof
    float sum=0;
    for (int k=0; k<10; k++) {
      rect(xposthree+ssq/7+sum, ssq/2.3-sum, ssq/40, ssq/40);
      rect(xposthree+ssq/3-sum, ssq/2.3-sum, ssq/40, ssq/40);
      sum = sum+ssq/70;
    }
    rect(xposthree+ssq/4.5, ssq/1.30, ssq/20, ssq/15);
  }
}