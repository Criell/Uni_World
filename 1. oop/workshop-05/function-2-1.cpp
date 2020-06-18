#include <iostream>
#include <stdlib.h>

using namespace std;

int *readNumbers()
{
	int length = 10;
	int *readNumbers = new int [10];
	
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
	
	for (int i = 0; i < length; i++)
	{
		//cout<<i<<" "<<*(numbers+i)<<endl;
	}
}

void hexDigits(int *numbers,int length)
{
  string *hex = new string [length];
  
  for (int i = 0; i < length; i++)
  {
	  switch (numbers[i])
	  {
  	  case 0: hex[i] = "0"; break;
  	  case 1: hex[i] = "1"; break;
  	  case 2: hex[i] = "2"; break;
  	  case 3: hex[i] = "3"; break;
  	  case 4: hex[i] = "4"; break;
  	  case 5: hex[i] = "5"; break;
  	  case 6: hex[i] = "6"; break;
  	  case 7: hex[i] = "7"; break;
  	  case 8: hex[i] = "8"; break;
      case 9: hex[i] = "9"; break;
  		case 10: hex[i] = "A"; break;
  		case 11: hex[i] = "B"; break;
  		case 12: hex[i] = "C"; break;
  		case 13: hex[i] = "D"; break;
  		case 14: hex[i] = "E"; break;
  		case 15: hex[i] = "F"; break;
  		default : hex[i] = " "; break;
  	}
	}

    
  for (int i = 0; i < length; i++)
  {
    cout<<i<<" "<<*(numbers+i)<<" "<<hex[i]<<endl;
	//printNumbers(hex,length);
  }
}
