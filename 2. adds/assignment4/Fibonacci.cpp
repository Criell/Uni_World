#include "Fibonacci.h"

Fibonacci::Fibonacci(){}					

int Fibonacci::Fibo(int n){

	int prefibo;

	// Negatives numbers input = -1
	if (n < 0)
	{
		return -1;
	}

	// fib(0) = 0
	if (n == 0)
	{
		return 0;
	}
	//fib(1) = 1
	else if (n == 1)
	{
		 return 1; 
	}

	// Other parameters the function call itself.
	else 
	{ 
		prefibo = Fibo(n-2) + Fibo(n-1); 
	}

	// fib(n)
	return prefibo;
}

Fibonacci::~Fibonacci(){}
