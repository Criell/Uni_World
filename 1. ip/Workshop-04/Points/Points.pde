size(300,300);
background (0);
stroke (255);

float[] xs = new float[1000];
float[] ys = new float[1000];

int[] roll = new int[1000];
float[] frequency = new float[18];
for (int i = 0; i < 1000; i++) 
{
       
    xs[i] = 0.0;
    ys[i] = 0.0;
    
    // for (int j=0; j<10; j++) {
     xs[i] = xs[i] + int (random(1,10));
     ys[i] = ys[i] + int (random(1,10));
     roll[i] = round(xs[i]) + round(ys[i]);
     switch (roll[i])
     {
       case 2:
       frequency[0]++;
       case 3:
       frequency[1]++;
       case 4:
       frequency[2]++;
       case 5:
       frequency[3]++;
       case 6:
       frequency[4]++;
       case 7:
       frequency[5]++;
       case 8:
       frequency[6]++;
       case 9:
       frequency[7]++;
       case 10:
       frequency[8]++;
       case 11:
       frequency[9]++;
       case 12:
       frequency[10]++;
       case 13:
       frequency[11]++;
       case 14:
       frequency[12]++;
       case 15:
       frequency[13]++;
       case 16:
       frequency[14]++;
       case 17:
       frequency[15]++;
       case 18:
       frequency[16]++;
       case 19:
       frequency[17]++;
       case 20:
       frequency[18]++;
     }
     
     
    //println(xs[i]);
//}
}

for (int i=0; i<100; i++)

{
  //strokeWeight(int (random(0,10)));  
  strokeWeight(4);
  point(xs[i],ys[i]);
}