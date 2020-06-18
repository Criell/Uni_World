size (300,600);
background (0);

fill(255);

int[] threes = new int[26];
int a = 1;

for (int i = 0; i < threes.length; i++)
{
  threes[i] = i*3;
  text (i, 10, 10+i*20);
  text (threes[i], 50, 10+i*20);
}

int sum = 0;

for (int i = 0; i < threes.length; i++)
{
  sum = sum + threes[i];
  text (sum, 80, 10+i*20);
}

int div = sum / 3;


rect (140, 160, 50, 50);
fill(0,0,255);
text ("Total sum divide by 3", 120, 150);
text (div, 150, 200);