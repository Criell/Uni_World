#include <iostream>
#include <stdlib.h>

using namespace std;

int *readNumbers( )
{
	int length = 10;
	int *readNumbers = new int [length];
	
	if (length <1)
				return 0;

	for (int i = 0; i < length; i++)
	{
		//cout<<"Please write the number "<<i<<":";
		cin>>*(readNumbers+i);
	}
	
	return readNumbers;
}

void printNumbers(int *numbers,int length)
{
  if (length>0)
  {
  	for (int i = 0; i < length; i++)
  		{
  			cout<<i<<" "<<*(numbers+i)<<endl;
  		}
  }
}
