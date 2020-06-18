#include <iostream>
#include <string>

#include "match.h"
#include "human.h"
#include "computer.h"
#include "referee.h"

using namespace std;

int main (){

	human p1;
	p1.getInput();

	referee r1;
	string results;

	results = r1.getMatch(p1);

	cout << results << endl;

	return 0;
}