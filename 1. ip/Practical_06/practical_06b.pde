int[]theColours;
int[]BlueColours;
int[]PurpleColours;
int[]YellowColours;
int[]EqualColours = {10,11,12,9,10,8,10,11,12,9,10,8,7,10,11,10}; 

void setup(){
 size(400,400);
 theColours = new int[16]; //Initialise and populate the array
 BlueColours = new int[16];
 PurpleColours = new int[16];
 YellowColours = new int[16];
   
 for (int i = 0; i < theColours.length; i++)
 {
   BlueColours[i] = int(random(1,11));
   PurpleColours[i] = int(random(10,11));
   YellowColours[i] = int(random(11,20));
   EqualColours[i] = int(random(9,12));
 }
 
 for (int i = 0; i < theColours.length; i++)
 {
     //theColours[i] = BlueColours[i];
     //theColours[i] = PurpleColours[i];
     //theColours[i] = YellowColours[i];
     theColours[i] = EqualColours[i];
 }
 
 noLoop(); //This prevents draw() from running more than once.
}

void draw(){
 int n = 60;
 colouredGrid(theColours,height / (n/10)+n*2, n); //Call our function.
 colouredGrid(theColours,height / (n/10)+n, n); 
 colouredGrid(theColours,height / (n/10), n); 
 colouredGrid(theColours,height / (n/10)-n, n); 
}

void colouredGrid(int[] colours, float y, int size){
  
  if (size < colours.length)
  {
  text("The size is diferente than the length of the colors", 10, 80);
  }
  else
  {
  for (int i = 0; i < 4; i++){ 
   if (colours[i] < 10) {
      fill(0,0,255);
     
   } 
   else if (colours[i] == 10){
      fill(127,0,255);
   }
   else if (colours[i] > 10){
      fill(255,255,0);
   }
   rect((i * size), y, size, size);
   }
 }

}