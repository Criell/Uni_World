#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
	Queue operators;
	operators.push('+');
	cout << operators.front() << " " << operators.size()  << endl;
	operators.push('/');
	cout << operators.front() << " " << operators.size()  << endl;
	operators.pop();
	cout << operators.front() << " " << operators.size() << endl;
	operators.~Queue();
	cout << "  " << operators.size() << endl;
	return 0;
}