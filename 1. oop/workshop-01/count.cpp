// counts the number of even numbers in an array with n elements
int count(int array[], int n)

{
   
        int number = 0;

        for (int i = 0; i<n; ++i)

        {
           if (array[i] % 2 == 0)

           	   ++number;
        }


        return number;
}
