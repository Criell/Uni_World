#include <iostream>
#include <stdlib.h>

using namespace std;

extern void cpyia(int old_array[],int new_array[],int length);

int main ()
{
	int length = 5;
	
	int old_array[5] = {5,2,9,8,1};  
	int *new_array = new int [5];
	

	cpyia(old_array,new_array,length);
}