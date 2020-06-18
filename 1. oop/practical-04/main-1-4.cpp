#include <iostream>
#include <stdlib.h>

using namespace std;

extern void cpyda(double *old_array,double *new_array,int length);

int main ()
{
	int length = 5;
	
	double old_array[5] = {1.28,2.5,-3.6,9.325,5};
	double *new_array = new double [5];
	
	//double array [3] = {1.2,2.5,3.6};
	//double *old_array = &array[0]; 
	//double  = &array[0]; 
	
	cpyda(old_array,new_array,length);
	
}