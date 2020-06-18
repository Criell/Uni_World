#include <stdlib.h>
#include <math.h> 
#include <iostream>
#include <istream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "Grip.h"


using namespace std;

int main (int argc,char **argv){

	Grip pos;
	fstream read(argv[1]);
	read >> pos.width;
	read >> pos.height;

	for (unsigned int y = 0; y < pos.height; y++)
	{
		vector<node> row;
		for (unsigned int x = 0; x < pos.width; x++)
		{
			node n;
			n.y = y;
			n.x = x;
			n.f = 0;
			read >> n.brick;
			n.closed = false;
			row.push_back(n); 
		}
		pos.open.push_back(row);
	}

    int bx = atoi(argv[argc-4]);
    int by = atoi(argv[argc-3]);
    int ex = atoi(argv[argc-2]);
    int ey = atoi(argv[argc-1]);
    
    std::string path;
    pos.CallMove(bx, by, ex, ey);
    std::cout << path << std::endl;
}