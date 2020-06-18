//int [] nums = {7,1,23,56,-8,20,-2,0,13};

int [] nums = new int [9];
int length = nums.length;
int move;

void setup(){
  size (600,600);
  background (0);
  textSize(14);
  move =0;
    
  for (int i = 0; i < length; i++){
    nums[i] = int (random(-50,50));
  }
  
  printArray(nums, length);
   
  for (int i = 0; i < length; i++){
    int min = minIndex(nums,i,length);
      if (min != i){
        SwapNumbers(nums, min, i);  
    }
  }
  
  printArray(nums, length);
}
  
  

int minIndex(int [] a, int start, int end) {
    int min = start;
    for (int j = start + 1; j < end; j++){
        if (a[j] < a[min]){
            min = j;
        }
    }
    return min;
}

int SwapNumbers(int [] a, int min, int i) {
    int tmp = a[min];
    a[min] = a[i];
    a[i] = tmp;        
     
    return a[i];
}

boolean checkOrder(int[] a, int length){
  boolean check = false;
  
  for (int i = 1; i < length; i++){
    if (a[i-1] < a[i])
      check = true;
    else
      return check;
  }
  check = true;
  return check;
} 

void printArray(int [] a, int length){
  
  for (int i = 0; i < length; i++){
    text(nums[i], 50 + (i * 40), 50 + (move * 40));
  }
  
  if (checkOrder(nums, length) == true){
     text("It is check", 50, 100, 50 + (move * 40));
  }
  else {
     text("Do not work", 50, 100, 50 + (move * 40));
  }
  
  move++;
}