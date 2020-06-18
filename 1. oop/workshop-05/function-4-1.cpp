#include <iostream>
#include <stdlib.h>

using namespace std;

int *readNumbers()
{
	int length = 10;
	int *readNumbers = new int [10];
	
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

int secondSmallestSum(int *numbers,int length)
{
	if (length <1)
			return 0;

	int sum = numbers[0];
	int second = numbers[0];
	int new_sum = 0;
	

	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			for (int k = i; k <= j; k++)
			{
			  new_sum = numbers[i];
			  new_sum = new_sum + numbers[k];
			  //cout<<"I"<<i<<" "<<numbers[i];
			  //cout<<". J"<<j<<" "<<numbers[j];
			  //cout<<". K"<<k<<" - new_sum: "<<new_sum<<endl;
			}
			
			if (new_sum < sum )
			{
			  second = sum;
			  sum = new_sum;
			  
			  //cout<<"                   - second: "<<sum<<endl;
			  //cout<<"                   - sum: "<<sum<<endl;
			}
			
			
			
		}
	}
	return second;
}
