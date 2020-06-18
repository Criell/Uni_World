#include "Grip.h"

using namespace std;
	
std::string Grip::CallMove(int xst, int yst, int xen, int yen){

	x=xst;
	y=yst;
	endx=xen;
	endy=yen;
	
	start = &open.at(x).at(y);
	finish = &open.at(endx).at(endy);
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

	return mv;
 }


node* Grip::f(node* cn){
	cn->f = comeFrom.size() + abs(cn->y - finish->y) + abs(cn->x - finish->x);
	return cn;
}

node* Grip::getBestFringe(node* cn)
{
	node *min = new node;
	min->f = height*width;

	if (cn->y < height - 1 && !open.at(cn->y + 1).at(cn->x).brick && !open.at(cn->y + 1).at(cn->x).closed){
		if (f(&open.at(cn->y + 1).at(cn->x))->f < min->f){
			min = &open.at(cn->y + 1).at(cn->x);
			mv = mv + "D" + " ";
		}
	}

	if (cn->x < width - 1 && !open.at(cn->y).at(cn->x + 1).brick && !open.at(cn->y).at(cn->x + 1).closed){
		if (f(&open.at(cn->y).at(cn->x + 1))->f < min->f){
			min = &open.at(cn->y).at(cn->x + 1);
			mv = mv + "R" + " ";
		}
	}

	if (cn->x > 0 && !open.at(cn->y).at(cn->x - 1).brick && !open.at(cn->y).at(cn->x - 1).closed){
		if (f(&open.at(cn->y).at(cn->x - 1))->f < min->f){
			min = &open.at(cn->y).at(cn->x - 1);
			mv = mv + "L" + " ";
		}
	}

	if (cn->y > 0 && !open.at(cn->y - 1).at(cn->x).brick && !open.at(cn->y - 1).at(cn->x).closed){
		if (f(&open.at(cn->y - 1).at(cn->x))->f < min->f){
			min = &open.at(cn->y - 1).at(cn->x);
			mv = mv + "U" + " ";
		}
	}
	return min;
}