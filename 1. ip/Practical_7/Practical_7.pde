int[][] theColours = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}} ;
int y;
int r = int (random (0,255));
int ye = int (random (0,255));
int b = int (random (0,255));

void setup(){
 size(400,400);
 y = 0;
}

void draw(){
 int n = 60;
 background (0);
 colouredGrid(theColours, n); //Call our function.
 colouredGrid(theColours, n); 
 colouredGrid(theColours, n); 
 colouredGrid(theColours, n); 
 text(mouseX, mouseX - 30, mouseY - 10);
 text(mouseY, mouseX, mouseY - 10);
}

void colouredGrid(int[][] colours, int size){
  
  
  for (int i = 0; i < 4; i++){ 
    y = size *2; 
    for (int j = 0; j < 4; j++){
       if (colours[i][j] == 1) {
          fill(255); 
       } 
       else if (colours[i][j] == 0){
         fill(r,ye,b);
       }
       rect((i * size), (height / (size/10)+y), size, size);
       y = y - size;
       }
  }
}

void mousePressed(){
  if (mouseX < 60) {
    if (mouseY <= 69)
      theColours[0][3] = 0;
     else if (mouseY < 129)
      theColours[0][2] = 0;
     else if (mouseY < 189)
      theColours[0][1] = 0;
      else if (mouseY < 249)
      theColours[0][0] = 0;
  }
  
  else if (mouseX < 120){
    if (mouseY < 69)
      theColours[1][3] = 0;
     else if (mouseY < 129)
      theColours[1][2] = 0;
     else if (mouseY < 189)
      theColours[1][1] = 0;
      else if (mouseY < 249)
      theColours[1][0] = 0;
}
  
  else if (mouseX < 180){
    if (mouseY < 69)
      theColours[2][3] = 0;
     else if (mouseY < 129)
      theColours[2][2] = 0;
     else if (mouseY < 189)
      theColours[2][1] = 0;
      else if (mouseY < 249)
      theColours[2][0] = 0;
}
  
  else if (mouseX < 240){
    if (mouseY < 69)
      theColours[3][3] = 0;
     else if (mouseY < 129)
      theColours[3][2] = 0;
     else if (mouseY < 189)
      theColours[3][1] = 0;
      else if (mouseY < 249)
      theColours[3][0] = 0;
     }
}