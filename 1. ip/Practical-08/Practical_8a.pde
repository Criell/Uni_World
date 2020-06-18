int [] array_one;
int [] array_two;
int [] array_three;
int n;
int text_mean;
int text_median; 
int text_check_values;
int text_check_greater;

void setup (){
  size (700,400);
  background (0);
  n = 7;
  array_one = new int [n];
  array_two = new int [n];
  array_three = new int [n];

  for (int i = 0; i < n; i++)
  {
    array_one[i] = int (random (1, 9));  
    array_two[i] = 2*i;
    array_three[i] = 2;
    
  }
  
  text_mean = mean (array_one, n);
  text_median = median (array_one, n);
  text_check_values = check_values (array_one, n);
  text_check_greater = check_greater(array_one, n, text_mean);
  print_array(array_one, n, 20, 20, text_mean, text_median, text_check_values, text_check_greater);
  
  text_mean = mean (array_two, n);
  text_median = median (array_two, n);
  text_check_values = check_values (array_two, n);
  text_check_greater = check_greater(array_two, n, text_mean);
  print_array(array_two, n, 220, 20,text_mean, text_median, text_check_values, text_check_greater);
  
  text_mean = mean (array_three, n);
  text_median = median (array_three, n);
  text_check_values = check_values (array_three, n);
  text_check_greater = check_greater(array_three, n, text_mean);
  print_array(array_three, n, 420, 20,text_mean, text_median, text_check_values, text_check_greater);
}

int check_greater (int []array, int n, int mean){
  int counter = 0;
  for (int i = 0; i < n; i++){
     if (array[i] > mean){
          counter++; 
     }
  }
  return counter;
}

int mean (int []array, int n) {
  int sum = 0;
  
  for (int i = 0; i < n; i++)
  {
    sum = sum + array[i];
  }

  int mean = sum/n;  
  return mean;
}

int median (int []array, int n){

  int median = 0;
  int j;
  
  for (int i = 1; i < n; i++){
    j = i;
    
    while ((j>0) && (array[j-1] > array[j])){ 
        int temp = array [j];
        array [j] = array[j-1];
        array[j-1] = temp;   
        j = j-1;
    }
  } 
  
  median = array[n/2];
  return median;
}

int check_values (int []array, int n){ 
  int j;
  for (int i = 0; i < n; i++){
    j = i;
    while((j>0) && (array[j-1] == array[j]))
      return 0;
   }
  return 1;
}

void print_array(int []array, int n, int x, int y, int mean, int median, int check_values, int check_greater){
  int y1 = y;
  text ("Mean: ", x, y1);
  y1 = y + 20;
  text ("Greater/Mean: ", x, y1);
  y1 = y1 + 20;
  text ("Median: ", x, y1);
  y1 = y1 + 20;
  text ("Unique Values: ", x, y1);
  y1 = y;
  
  int x2 = x + 90;
  text (mean, x2, y1);
  y1 = y1 + 20;
  text (check_greater, x2, y1);
  y1 = y1 + 20;
  text (median, x2, y1);
  y1 = y1 + 20;
  text (check_values, x2, y1);
  
  y1 = y1 + 40;
  
  for (int i = 0; i < n; i++)
  {
    text (array[i], x, y1);
    x = x + 20;
  }
}