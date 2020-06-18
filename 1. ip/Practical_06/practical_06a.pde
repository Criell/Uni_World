size (800,600);
background (0);
strokeWeight(10);

//This is ...
String [] StudentName = {"Lina", "Diana", "Aurora", "Nestor", "Jorge", "Myriam", "Celso", "Berta", "Miguel", "Mauro", "Carol", "Alejo", "Lilia","Monica", "Yolan", "Amalia", "Danilo", "Luis", "Mario", "Arman"};
String [] StudentGender = {"F", "F", "F", "M", "M", "F", "M", "F", "M","M","F","M","F","F","F","F","M","M","M","M"};

int Num_Students = StudentName.length;

//This is  ..
float [] StudentHeight;
StudentHeight = new float [Num_Students];
float SumHeight = 0;

int [] StudentAge;
StudentAge = new int [Num_Students];
int SumAge = 0;

for (int i = 0; i < Num_Students; i++)
{
  StudentAge[i] = int(random(16,35));
  
  if (StudentGender[i] == "F")
    SumAge = SumAge + StudentAge[i];
    
  if (StudentGender[i] == "F"){
    StudentHeight[i] = random(1.5,1.7);
    SumHeight = SumHeight + StudentHeight[i];
  }
    
  else if (StudentGender[i] == "M"){
    StudentHeight[i] = random(1.6,1.9);
  }

}

int AverageAge = SumAge/(Num_Students/2);
float AverageHeight = SumHeight/(Num_Students/2);
float Max_Height = 0;
int Min_Age = StudentAge[0];

int height_below = 0;
int height_between = 0;
int height_greater = 0;

for (int i = 0; i < Num_Students; i++)
{
    if ((StudentGender[i] == "F") && StudentAge[i] < Min_Age)
      Min_Age = StudentAge[i];
     
    if ((StudentGender[i] == "F") && StudentHeight[i] > Max_Height);
      Max_Height = StudentHeight[i];
    
    if ((StudentGender[i] == "M") && (StudentHeight[i] <= 1.7))
      height_below = height_below + 1;
      
    if ((StudentGender[i] == "M") && (StudentHeight[i] > 1.7) && (StudentHeight[i] <= 1.8))
      height_between = height_between + 1;

    if ((StudentGender[i] == "M") && (StudentHeight[i] > 1.8))
      height_greater = height_greater + 1;     
}

 textSize (17);
 text ("Minimum Age:", 20, 20);
 text ("Average Age:", 20, 40);
 text ("Maximum Height:", 20, 60);
 text ("Average Height:", 20, 80);
 
 text (Min_Age, 180, 20);
 text (AverageAge, 180, 40);
 text (Max_Height, 175, 60);
 text (AverageHeight, 175, 80);
 int space = 20;

 fill(0,200,100);
 text (height_below, space, 120);
 rect (space, 150, width/40, height_below * height/10);
 space = space + height/10;
 
 fill(0,100,200);
 text (height_between, space, 120);
 rect (space, 150, width/40, height_between * height/10);
 space = space + height/10;
 
 fill(200,0,200);
  text (height_greater, space, 120);
 rect (space, 150, width/40, height_greater * height/10);
 space = space + height/10;
 
 int newspace=10;
 textSize (11);
for (int i = 0; i < Num_Students; i++)
{ 
  text(StudentName[i], newspace, height-80);
  text(StudentGender[i], newspace, height-60);
  text(StudentAge[i], newspace, height-40);
  text(StudentHeight[i], newspace, height-20);
  newspace = newspace + height/15;
}