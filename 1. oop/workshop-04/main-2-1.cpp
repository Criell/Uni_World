#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

using namespace std;

extern float add_op(float left, float right); 
extern float subtract_op(float left, float right);
extern float arithmetic_ops(float left, float right, std::string op);

int main()

{
	float left = 12.2;
	float right = 5.2;
	string op;
	
	cout<<"Please write the operation (+ or -)"<<endl;
	cin>>op;  
	
	//while (op!="+" || op!="-") 
	//{
	  //cout<<"Only write the operation (+ or -)"<<endl;
	  //cin>>op;  
	//} 
	
	cout<<arithmetic_ops(left, right, op)<<endl;
	 
}