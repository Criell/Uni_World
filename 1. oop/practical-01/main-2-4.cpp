// program 2-4

#include <iostream>

// definition of sum/min/max functions
extern int sum_min_and_max(int integers[], int length) ;
extern int max_integer(int integers[], int length) ;
extern int min_integer(int integers[], int length) ;

// main program to test the sum/min/max functions - ignore args
int main()
{
	// example numbers to test - min is -12, max is 11, sum is -1
	int numbers[6] = {1,8,3,11,-12,2} ;

	// test min, then max, the sum_min_and_max
	std::cout << min_integer(numbers,6) << std::endl ;
	std::cout << max_integer(numbers,6) << std::endl ;
	std::cout << sum_min_and_max(numbers,6) << std::endl ;

	// return 0 to indicate nothing went wrong
	return 0 ;
}
