size(700,400);

// This is aggregate initialisation. A useful
// way to initialise arrays!

int [] treeHeight = {50,100,70,80,30,150,60,200,90,60,50,100,70,80,70,150,40,250,90,60};
int [] treeWidth = {20,15,10,22,12,16,22,13,12,30,20,15,10,22,12,16,22,13,15,30};

// Set the fill colour
fill(165,42,42); //Brown

//Set up the variables

int xStart=width/10; // X position to start at
int xInterval; // We'll use below
int xCurrent = xStart; 
int xNext; // Track where to draw rect x

int baseline=150; // y line to draw trees from
int yInterval; // We'll use below
int yCurrent = baseline; // Use this to vary rect y
int yNext; // Track where to draw rect y

int max = Integer.MIN_VALUE;
int min = Integer.MAX_VALUE;

// Draw the trunks
// Remember that the first two rect parameters are
// considered the top left.
// I have to calculate yCurrent by thinking about what
// size rectangle needs to be drawn to hit baseline.

for (int i=0; i<treeHeight.length; i++) {
 if (treeHeight[i]>max){
  max=treeHeight[i];
}
if (treeHeight[i]<min){
  min=treeHeight[i];
}
}

for (int i=0; i<treeHeight.length; i++) {
 xInterval = treeWidth[i] + 10;
 xNext = xCurrent + xInterval;
 
 yInterval = int (random(1,3));
 
 //yCurrent = baseline - treeHeight[i];
 yNext = yCurrent + yInterval;
 rect(xCurrent, yCurrent, treeWidth[i], treeHeight[i]);

 // We can have loops within loops
 // Now draw some 'leaves' on top of the tree trunk



 //fill(100+(10*i), 255-(10*i), 0);

 
 fill(0,255,0);
 if (treeHeight[i]==min){
   fill(255,0,0);
    for (int j = 2; j >= 0; j--) {
             int myx= xCurrent + (treeWidth[i]/2);
 triangle(myx, yCurrent-(40+3*j),
     myx - 40, yCurrent+(4*j),
     myx + 40, yCurrent+(4*j));
    }
 }else if (treeHeight[i]==max){
   fill(0,0,255);
   int myx= xCurrent + (treeWidth[i]/2);
   triangle(myx, yCurrent-(40+3),
     myx - 40, yCurrent+4,
     myx + 40, yCurrent+4);
     fill(255,0,0);
    ellipse(myx, yCurrent-(40+3),10,10);
 }else{
   fill(0,255,0);
    for (int j = 5; j >= 0; j--) {
       int myx= xCurrent + (treeWidth[i]/2);
 triangle(myx, yCurrent-(40+3*j),
     myx - 40, yCurrent+(4*j),
     myx + 40, yCurrent+(4*j));
    }
 }
 
 
 fill(165,42,42); //Brown
 xCurrent=xNext;
 yCurrent=yNext;
}