int[] array = new int [4];
int space;

void setup(){
 size(400,400);
 background (0);
 textSize(17);
 for (int i = 0; i < 4; i++)
 {
  fill(150,150,150);
  array[i] = int (random (1,10));
  text(array[i], space, 20);
  space = space + height/8;
 }
  
 suffle(array);
 
 for (int i = 0; i < 4; i++)
 { 
  text(array[i], space, 40);
  space = space + height/8;
 }
}

void suffle(int[]value){
   int temp;
   int pick;
   for(int i=0;i<value.length;i++){
       pick  = (int)random(value.length); 
       temp = value[i]; 
       value[i] = value[pick]; 
       value[pick]= temp; 
    }
}