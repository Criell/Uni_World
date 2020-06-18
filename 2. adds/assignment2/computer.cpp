#include <iostream>
#include <string>

#include "match.h"
#include "computer.h"

using namespace std;

computer::computer(){}
	
void computer::randMoves(int m){

	if (m != -1)
	{
		for (int i = 0; i < m; i++)
		{
			if ((i%2) == 0) { moves[i] = 'R'; }
			else {moves[i] = ' ';}
		}
	}
}
	
computer::~computer(){}