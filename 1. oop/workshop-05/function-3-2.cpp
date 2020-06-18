#include <iostream>
#include <stdlib.h>

using namespace std;

int *readNumbers( )
{
	int length = 10;
	int *readNumbers = new int [length];
	
	for (int i = 0; i < length; i++)
	{
		//cout<<"Please write the number "<<i<<":";
		cin>>*(readNumbers+i);
	}
	
	return readNumbers;
}

void printNumbers(int *numbers,int length)
{	
	for (int i = 0; i < length; i++)
		{
			cout<<i<<" "<<*(numbers+i)<<endl;
		}
}

int *reverseArray(int *numbers1,int length)
{
	int *reverseArray = new int [length];
	int n = length;
	
	if (length < 1)
		{
			//cout<<equalsArray<<endl;
			return 0;
		}

	for (int i = 0; i < length; i++)
	{
		n = n - 1;
		*(reverseArray+n) = *(numbers1+i);
	}
	
	return reverseArray;
}

bool equalsArray(int *numbers1,int *numbers2,int length)
{
	bool equalsArray = 0;
	int counter = 0;
	
	if (length < 1)
	{
		//cout<<equalsArray<<endl;
		return equalsArray;
	}
	
	for (int i = 0; i < length; i++)
	{
		if (*(numbers1+i)==*(numbers2+i))
			counter = counter+1;
	}
	
	if (counter == length)
	{
		equalsArray = 1;
		//cout<<equalsArray<<endl;
		return equalsArray;	
	}
	else
	{
		//cout<<equalsArray<<endl;
		return equalsArray;
	}
	
}