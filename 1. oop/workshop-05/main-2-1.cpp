#include <iostream>
#include <stdlib.h>

using namespace std;

extern int *readNumbers() ;
extern void printNumbers(int *numbers,int length) ;
extern void hexDigits(int *numbers,int length) ;

int main ()
{
	int length = 10;
	int *numbers;
	
	numbers = readNumbers();
	
	hexDigits(numbers, length);
	
	//printNumbers(numbers, length);
	
	delete[] numbers;
	
	return 0;
}
