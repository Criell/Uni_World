#include <iostream>
#include <stdlib.h>

using namespace std;

extern int *readNumbers() ;
extern void printNumbers(int *numbers,int length) ;

int main ()
{
	int length = 10;
	int *numbers = new int [length];
	
	numbers = readNumbers();
	
	printNumbers(numbers, length);
	
	delete [] numbers;
	
	return 0;
}