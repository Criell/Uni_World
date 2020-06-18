#ifndef _MATCH_H
#define _MATCH_H

#include <iostream>
#include <string>

using namespace std;

class match{

protected:
	int matches;
	string moves;

public:

	match(){}	

	int getMatches()
	{ 
		return matches; 
	}
	
	void setMatches(int n)
	{ 
		matches = n; 
	}

	string getMoves()
	{ 
		return moves; 
	}

	char getiMoves(int i)
	{ 
		char tmp = moves[i];
		return tmp; 
	}
	
	void setMoves(string n)
	{ 
		moves = n; 
	}

	~match(){}
};

#endif //_MATCH_H



