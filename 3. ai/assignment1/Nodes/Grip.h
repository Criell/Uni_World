#ifndef GRIP_H
#define GRIP_H

#include <stdlib.h>
#include <math.h> 
#include <iostream>
#include <istream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>

struct node {
	int y;
	int x;
	int f;
	bool brick;
	bool closed;
};


class Grip{
	public:
		std::string mv;
		std::vector< std::vector<node> > open;
		std::deque<node*> comeFrom;
		node *start;
		node *finish;
		int height;
		int width;
		int x,y,endx,endy;

		Grip(){}
		~Grip(){}
		std::string CallMove(int xst, int yst, int xen, int yen);
		node* f(node* cn);
		node* getBestFringe(node* cn);

};

#endif //GRIP_H