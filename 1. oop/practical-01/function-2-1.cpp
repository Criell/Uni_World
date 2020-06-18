// function to ...
int minimum(int array[], int n)
{
  int min = array[0];
  
  if (n<0)
    return 0;
  
  for (int i=0; i<n; ++i)
  {
    if (array[i] < min) 
      min = array[i];
  }
  
  return min;
}
