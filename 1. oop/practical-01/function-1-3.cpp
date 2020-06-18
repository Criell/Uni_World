// function to ...


int count(int array[], int n, int num)

{
   int times = 0;
   
   if (n<0)
      return 0;
   
   for (int i=0; i<n; ++i)
   {
      if (array[i] == num)
	    times = times + 1;      
   }

   return times;
}
