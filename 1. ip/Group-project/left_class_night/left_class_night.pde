int x;
Buildingone b1;
Buildingtwo b2;
Buildingthree b3;

//ground g1= new ground();
void setup(){
size(300,300);
x= width;
println(x);
 b1= new Buildingone(x*0.04,1); //xpos
 b2= new Buildingtwo(x*0.2,1); //xpostwo
 b3= new Buildingthree(x*0.6,1); //xposthree

}

class Buildingone{
  float xpos, speed;
  Buildingone(float x, float s){
  xpos= x;
speed= s;
  }
  
  void update(){
    fill(255);
  xpos-=speed;
  if(xpos<=-100){
  xpos= width;
  }
  //wall 
  rect(xpos,height/2,height/40,width/3);
  rect(xpos+height/7,height/2,height/40,width/3);
  
  //roof
  noStroke();
  int sum=0;
  for(int k=0;k<7;k++){
  rect(xpos+sum,height/2-sum,width/40,height/40);
  rect((xpos+width/7)-sum,height/2-sum,width/40,height/40);
  sum = sum+width/70;
}

//roof top
  rect(xpos+(width/18),height/2.4,width/20,height/20);
  
//windows
fill(#ffff00); // windows 
  int window=0;
  for (int j=0; j<4; j++) {
    rect(xpos+(width/20), height/1.80+window, width/60, width/30);
    rect(xpos+(width/10),height/1.80+window,width/60,width/30);
window = window+width/20;
  }
  }
}

class Buildingtwo{
float xpostwo, speed;
  Buildingtwo(float x, float s){
  xpostwo= x;
  speed= s;
  }
  
  void update(){
    fill(255);
   xpostwo-=speed;
   if(xpostwo<=-100){
  xpostwo= width;
  }
  //wall 
  rect(xpostwo+height/7,height/2,height/40,width/3);
  rect(xpostwo+height/3,height/2,height/40,width/3);
  //roof
  rect(xpostwo+height/6,height/2,width/6,height/60);
  //window 
  fill(#ffff00);
int window=0;
  for (int j=0; j<4; j++) {
    rect(xpostwo+(width/5.55), height/1.80+window, width/30, width/30);
    rect(xpostwo+(width/3.57),height/1.80+window,width/30,width/30);
window = window+width/20;
  } 
  }

}

class Buildingthree{
float xposthree, speed;
  Buildingthree(float x, float s){
  xposthree= x;
  speed= s;
  }
  
  void update(){
    fill(255); 
  xposthree-=speed;
  if(xposthree<=-100){
  xposthree= width;
  }
  //wall 
  rect(xposthree+height/7,height/2.3,width/40,height/2.5);
  rect(xposthree+height/3,height/2.3,width/40,height/2.5);
 
 fill(#ffff00); // windows 
  int window=0;
  for (int j=0; j<6; j++) {
    rect(xposthree+height/5.5, height/2.1+window, width/30, width/60);
   rect(xposthree+height/3.5,height/2.1+window,width/30,width/60);
window = window+width/20;
  }
  fill(255);
noStroke();
//roof
int sum=0;
for(int k=0;k<10;k++){
rect(xposthree+height/7+sum,height/2.3-sum,width/40,height/40);
rect(xposthree+height/3-sum,height/2.3-sum,width/40,height/40);
sum = sum+width/70;
}
 rect(xposthree+height/4.5, height/1.30, width/20, width/15);
}



}
void ground(){
fill(0);
  rect(0, width/1.2, width, height/20);
  fill(0);
  rect(0, width/1.154, width, width/1);

}


void draw(){
  background(#000080);
b3.update();
b1.update();
b2.update();
ground();

}