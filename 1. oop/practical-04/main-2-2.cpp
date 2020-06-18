#include <iostream>
#include <stdlib.h>

using namespace std;

extern int maximum_sum(int *nums,int length);

int main ()
{
	int length = 10;
	int nums [10]= {7,-14,5,65,10,95,6,-10,2,100};
	
	// *********************************** Negative array  
	//int nums [10]= {-7,-14,-5,-65,-10,-95,-6,-10,-2,-100};
	
	maximum_sum(nums, length);
	
}