#include "EfficientFibonacci.h"


//Store in the vector the basic cases fib(0) and fib(0)
EfficientFibonacci::EfficientFibonacci(){
	pre_number.push_back(0);
	pre_number.push_back(1);
}

// Negatives numbers input = -1
int EfficientFibonacci::Eff_Fibo(int n){

	int prefibo;
	
	// Negatives numbers input = -1	
	if (n < 0)
	{
		return -1;
	}

	// fib(0) = 0
	else if (n == 0)
	{
		return 0;
	}

	// fib(1) = 1
	else if (n == 1)
	{
		 return 1;
	}

	// When n is less than the size of the vector return the n position of the vector.
	else if (n < (int)pre_number.size())
	{
		return pre_number.at(n);
	}

	// Other parameters the function call itself.
	else
	{
		prefibo = Eff_Fibo(n-2) + Eff_Fibo(n-1);
	}

	// pre_number.at(n) = fib(n).
	pre_number.push_back(prefibo);

	// fib(n)
	return prefibo;
}

EfficientFibonacci::~EfficientFibonacci(){}
