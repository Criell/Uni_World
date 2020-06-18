size (960,750);
background (0);
strokeWeight(10);

int n = 30;
int [] array;
array = new int [n];

int day = 1;
String [] days = {"Tue", "Wed", "Thu", "Fri", "Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun","Mon", "Tue", "Wed"};
int space = 5;
float [] Adelaide_temp = {20.2,14,15.8,14.1,18.1,16.8,15.1,16.5,15.2,20.2,24.8,27.1,29.1,19.9,17.1,19.2,17.4,17.2,21.1,25.3,16.4,16,16.2,16.1,20,22.4,24.7,19.6,18,22.4};
int [] Singapore_temp = {32,33,32,32,32,33,33,32,32,31,33,32,32,32,29,29,32,32,34,33,33,32,33,33,32,32,32,32,32,32};
int [] Helsinki_temp = {18,16,16,17,17,16,14,16,16,18,16,16,16,16,16,15,17,17,16,16,14,15,15,16,16,16,14,13,13,15};

for (int i = 0; i < n; i++)
{
  fill(150,150,150);
  array[i] = day;
  day = day + 1;
  text(array[i], space, height-40);
  
  String Ade_t = nf(Adelaide_temp[i],2,1);
  text(Ade_t, space, 40);
  text(Singapore_temp[i], space, 280);
  text(Helsinki_temp[i], space, 540);
  text(days[i], space, height-60);
  
  if (Adelaide_temp[i] < 19) {
    fill(0,200,200);
  }

  else if (Adelaide_temp[i] >= 19) {
    fill(255,0,0); 
  }
  rect (space, 50, width/50, Adelaide_temp[i] * height/115);
  
  if (Singapore_temp[i] < 32.1) {
    fill(0,200,200);
  }

  else if (Singapore_temp[i] >= 32.1) {
    fill(255,0,0); 
  }
  
  rect (space, 290, width/50, Singapore_temp[i] * height/115);
  
  if (Helsinki_temp[i] < 15.7) {
    fill(0,200,200);
  }

  else if (Helsinki_temp[i] >= 15.7) {
    fill(255,0,0); 
  }
  rect (space, 550, width/50, Helsinki_temp[i] * height/115);
  
  space = space + height/23;
}

fill(255);
textSize (17);
text("ADELAIDE,  TEMPERATURE CALENDAR", 20, 20);
text("HELSINKI,  TEMPERATURE CALENDAR", 20, 520);
text("SINGAPORE, TEMPERATURE CALENDAR", 20, 260);
int d = day();
int m = month();
int y = year(); 
text(d, width-90, 20);
text("/", width-70, 20);
text(m, width-62, 20);
text("/", width-52, 20);
text(y, width-45, 20);

textSize (20);
text("SEPTEMBER, 2015", width/2-60, height-10);