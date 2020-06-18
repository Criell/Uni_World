//Version using nodes.
//This version compile and work with easy cases, but has segmentation faul with the big one.
//The test than work present a mistake that I couldnt identify.

#include <stdlib.h>
#include <math.h> 
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>

using namespace std;


//Create the structure of the nodes with the coordinates and trying to implement Astar
// The brick are the 1 and 0, and the the closed evaluated if the node is already walk. 
struct node {
	int y;
	int x;
	int f;
	bool brick;
	bool closed;
} *start, *finish;


//Vector that store the nodes that are in the cheeking process
vector< vector<node> > open;
deque<node*> comeFrom;
std::string mv;

//Variables that define the size of the matrix
int height = 0;
int width = 0;

// Find the F using the heuristic is the Manhattan distance because the raversal i is not allow.
// The cost of the path is the size of the nodes walk.
node* f(node* cn)
{
	cn->f = comeFrom.size() + abs(cn->y - finish->y) + abs(cn->x - finish->x);
	return cn;
}

/** The If condition of right left up and down, storing in the string mv the walking
    This if statements had a mistake, they are finding the path but with additional steps.
    This conditions are cheeking if the node is in the close vector 
    trying to prevent the main mistake in the other version.*/

node* getBestFringe(node* cn)
{
	node *min = new node;
	min->f = width*height;

	//Up
	if (cn->y < height - 1 && !open.at(cn->y + 1).at(cn->x).brick && !open.at(cn->y + 1).at(cn->x).closed)
	{
		if (f(&open.at(cn->y + 1).at(cn->x))->f < min->f)
		{
			min = &open.at(cn->y + 1).at(cn->x);
			mv = mv + "D" + " ";
		}
		
	}

	//Right
	if (cn->x < width - 1 && !open.at(cn->y).at(cn->x + 1).brick && !open.at(cn->y).at(cn->x + 1).closed)
	{
		if (f(&open.at(cn->y).at(cn->x + 1))->f < min->f)
		{
			min = &open.at(cn->y).at(cn->x + 1);
			mv = mv + "R" + " ";
		}
		
	}

	//Left
	if (cn->x > 0 && !open.at(cn->y).at(cn->x - 1).brick && !open.at(cn->y).at(cn->x - 1).closed)
	{
		if (f(&open.at(cn->y).at(cn->x - 1))->f < min->f)
		{
			min = &open.at(cn->y).at(cn->x - 1);
			mv = mv + "L" + " ";
		}
		
	}

	//Down
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
	//Buffer the txt file and store width and height
	fstream read(argv[1]);

	read >> width;
	read >> height;

	//Created nodes of the matrix and store them in open vector
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

	// store in start the node that the user write as the begin
	start = &open.at(atoi(argv[3])).at(atoi(argv[2]));
	
	// store in finish the node that the user write as the gold
	finish = &open.at(atoi(argv[5])).at(atoi(argv[4]));

	//Fill the comeFrom start, because it is a close node
	comeFrom.push_back(start);

	//Find the small F and push this in the close vector comeFrom
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
	
	//Print the close nodes
	for (int i = 0; i < comeFrom.size(); i++)
	{
		cout << comeFrom.at(i)->x << " " << comeFrom.at(i)->y << endl;
	}

	cout << mv << endl;

	return 0;
}