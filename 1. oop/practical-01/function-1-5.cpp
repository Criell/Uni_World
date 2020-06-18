// function to ...
int count_even(int number)
{
  int sum = 0;
  int array[number];
  
  if (number<0)
    return 0;
  
  for (int i=0; i<number; ++i)
  
  {
    array[i] = i+1;  
    
    if (i % 2 == 0) 
      sum = sum+1;
  }
  
  return sum;
}