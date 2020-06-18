void green_pill(){
  if (level > 0){
    if (gree_pill_x <= -width*2){
       gree_pill_x = width + 200;
       gree_pill_y = int(random(50,height-50));
    }
      
   gree_pill_x = gree_pill_x - width/80; 
    
    fill(255);
    ellipse(gree_pill_x,gree_pill_y,ssq/60,ssq/60);
    if((abs(b1.xPos1 - gree_pill_x) < 20) && (abs(b1.yPos1 - gree_pill_y) < 20)){
       gree_pill_y = -20;
       size = ssq/36;    
    }
  }
}


void red_pill(){
  if (level > 0){
    if (red_pill_x <= -width*2){
       red_pill_x = width;
       red_pill_y = int(random(50,height-50));
    }
    
    if (red_pill_x <= -300){
       size = ssq/24;
    }
      
    red_pill_x = red_pill_x - width/80; 
    
    fill(255);
    ellipse(red_pill_x,red_pill_y,ssq/60,ssq/60);
    if(((abs(b1.xPos1-height/48 - red_pill_x) < height/48) && (abs(b1.yPos1-height/48 - red_pill_y) < height/48))) {
        red_pill_y = -20;
      }
     
    if (red_pill_y == -20){
      fill(255,0,0);
        rect(0, height-height/20, width,height/20);    
        if(b1.yPos1 >= height-height/20){
    collisioncheckmouseclickball1=1;
    collisioncheckmouseclickcolumn3=0;
        }
    }    
  }
}