int x;
int y;

void setup(){
  size (600,600);
  background (0);
  x=width/2;
  y=height/2;
  
  frameRate(200);
}

void draw(){
 clear(); 
 background (0);
 circle();
}
  
void circle(){
  fill(255,0,0);
  ellipse (x,y,50,50);
  if (y<=height){
    y = y-1;
  }
  else if (y==0){
    y = y+1;
  }


}
  