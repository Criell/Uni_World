#include <stdlib.h>
#include <math.h> 
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>

using namespace std;


//Create the 
struct node {
	int y;
	int x;
	int f;
	bool brick;
	bool closed;
} *start, *finish;

vector< vector<node> > open;
deque<node*> comeFrom;
std::string mv;

//Variables that
int height = 0;
int width = 0;

node* f(node* cn)
{
	cn->f = comeFrom.size() + abs(cn->y - finish->y) + abs(cn->x - finish->x);
	return cn;
}

node* getBestFringe(node* cn)
{
	node *min = new node;
	min->f = width*height;

	if (cn->y < height - 1 && !open.at(cn->y + 1).at(cn->x).brick && !open.at(cn->y + 1).at(cn->x).closed)
	{
		if (f(&open.at(cn->y + 1).at(cn->x))->f < min->f)
		{
			min = &open.at(cn->y + 1).at(cn->x);
			mv = mv + "D" + " ";
		}
		
	}

	if (cn->x < width - 1 && !open.at(cn->y).at(cn->x + 1).brick && !open.at(cn->y).at(cn->x + 1).closed)
	{
		if (f(&open.at(cn->y).at(cn->x + 1))->f < min->f)
		{
			min = &open.at(cn->y).at(cn->x + 1);
			mv = mv + "R" + " ";
		}
		
	}

	if (cn->x > 0 && !open.at(cn->y).at(cn->x - 1).brick && !open.at(cn->y).at(cn->x - 1).closed)
	{
		if (f(&open.at(cn->y).at(cn->x - 1))->f < min->f)
		{
			min = &open.at(cn->y).at(cn->x - 1);
			mv = mv + "L" + " ";
		}
		
	}

	if (cn->y > 0 && !open.at(cn->y - 1).at(cn->x).brick && !open.at(cn->y - 1).at(cn->x).closed)
	{
		if (f(&open.at(cn->y - 1).at(cn->x))->f < min->f)
		{
			min = &open.at(cn->y - 1).at(cn->x);
			mv = mv + "U" + " ";
		}
		
	}

	return min;
}

int main(int argc, char const *argv[])
{
	fstream read(argv[1]);

	read >> width;
	read >> height;

	for (unsigned int y = 0; y < height; y++)
	{
		vector<node> row;
		for (unsigned int x = 0; x < width; x++)
		{
			node n;
			n.y = y;
			n.x = x;
			n.f = 0;
			read >> n.brick;
			n.closed = false;
			row.push_back(n); 
		}
		open.push_back(row);
	}

	start = &open.at(atoi(argv[3])).at(atoi(argv[2]));
	finish = &open.at(atoi(argv[5])).at(atoi(argv[4]));
	comeFrom.push_back(start);

	while (comeFrom.back() != finish && !comeFrom.empty())
	{
		node* bestFringe = getBestFringe(comeFrom.back());
		if (bestFringe->f == width*height)
		{
			comeFrom.back()->closed = true;
			comeFrom.pop_back();
		} else
		{
			comeFrom.push_back(bestFringe);	
		}
	}
	for (int i = 0; i < comeFrom.size(); i++)
	{
		cout << comeFrom.at(i)->x << " " << comeFrom.at(i)->y << endl;
	}

	cout << mv << endl;

	return 0;
}