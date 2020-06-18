#include <iostream>
#include <string>

#include "match.h"
#include "human.h"
#include "computer.h"
#include "referee.h"

using namespace std;

referee::referee() {}
	
string referee::getMatch(human p1)
{	
	string novalid = "Not a valid input";
	int m = p1.getMatches();
	if (m == -1) {return wins;}

	computer p2;
	p2.randMoves(m);

	for (int i = 0; i < m; i=i+2){
		if (p1.getiMoves(i) == p2.getiMoves(i)){wins[i] = 'T';}

		else if ((p1.getiMoves(i) == 'P') & (p2.getiMoves(i)== 'R')) {wins[i] = 'W';}

		else if ((p1.getiMoves(i) == 'S') & (p2.getiMoves(i)== 'P')) {wins[i] = 'W';}
		
		else if ((p1.getiMoves(i) == 'R') & (p2.getiMoves(i)== 'S')) {wins[i] = 'W';}
		
		else if ((p2.getiMoves(i) == 'P') & (p1.getiMoves(i)== 'R')) {wins[i] = 'L';}
		
		else if ((p2.getiMoves(i) == 'S') & (p1.getiMoves(i)== 'P')) {wins[i] = 'L';}
		
		else if ((p2.getiMoves(i) == 'R') & (p1.getiMoves(i)== 'S')) {wins[i] = 'L';}

		cout << wins[i] << " ";
	}
	
	return wins;
}

referee::~referee(){}
