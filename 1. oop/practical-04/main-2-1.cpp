#include <iostream>
#include <stdlib.h>

using namespace std;

extern void print_sevens(int *nums, int length);

int main ()
{
	int length = 7;
  int nums[7] = {21, 56, 25, 7, 5, 14, 236};
  
	print_sevens(nums, length);
}
