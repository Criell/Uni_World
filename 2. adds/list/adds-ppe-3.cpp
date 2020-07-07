#include<iostream>
using namespace std;

/* General instructions: Please modify this file and submit the modified one
   via websubmission (under the entry "Practice Practical Exam - PR03"). 
   No design documents or header files are needed. You only need to submit
   one file, which is this one.

   Please note, you should use recursion in answering both questions.
*/


/* Task 1: Implement the following function for calculating the value of
           the function f = n!/(c^n).
*/

int recurN(int n) {

	if (n < 0)
	{
		return -1;
	}

	else if (n == 0)
	{
		return 1;
	}
	
	else if (n == 1)
	{
		return 1;
	}

	else
	{
		return n * recurN(n-1);
	}
  
}

int expC(int c, int r, int n) {

	if (n <= 1)
	{
		return 1;
	}

	else
	{	
		r = r * c;
		expC(c, r, n-1);
	}

	return r;
}


float func(int n, int c) {

	if ((n < 0) || (c < 0))
	{
		return -1;
	}

	else
	{	
		float p = recurN(n) / expC(c, 1, n);
		return p;
	}
  
}


/* Task 2: Implement the following function for calculating the number of
    different k-permutations from n.
*/

int numPerm(int n, int k) {

	if (n < k)
	{
		return 0;
	}

	else if ((n <= 1) || (k <= 1) )
	{
		return 1;
	}

	else
	{
		return n * numPerm(n, k-1);
	}
  
}

// You are not supposed to change the main function
int main() {
	int test;
	cin >> test;
	// Below are the test cases. If you pass x cases, then your mark is x/6.
	// A manual check for recurence will be conducted after the exam.
	// The numbers commented are the expected output
	switch (test) {
		case 1: cout << func(4, 2); break; // 1.5
		case 2: cout << func(5, 1); break; // 120
	        case 3: cout << func(10, 3); break; // 61.454
		case 4: cout << numPerm(5, 3); break; // 60
		case 5: cout << numPerm(10, 2); break; // 90
	        case 6: cout << numPerm(8, 6); break; // 20160
	}
}
