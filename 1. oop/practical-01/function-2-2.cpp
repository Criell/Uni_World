// function to ...
int maximum(int array[], int n)
{
  int max = 0;
  
  if (n<0)
    return 0;
  
  for (int i=0; i<n; ++i)
  {
    if (array[i] > max) 
      max = array[i];
  }
  
  return max;
}
