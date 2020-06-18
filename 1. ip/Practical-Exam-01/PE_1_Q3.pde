size (300,600);
background (0);

fill(255);

int[] half = {1, 2, 3, 4};
int[] full = new int [8];
int j = 4;

for (int i = 0; i < full.length; i++)
{
  if (i<4)
  {
    full[i] = half[i];
  }
  
  if (i>=4)
  {
    full[i] = half[i-4];
  }
    
  text (i, 10, 20+i*20);
  text (full[i], 50, 20+i*20);
}`