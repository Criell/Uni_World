//Version working (Not using nodes)

#ifndef GRIP_H
#define GRIP_H

#include "Map.h"


//Child Class
class Grip: public Map
{
	public:
		//Constructor
		Grip(const char* file);
		
		//Pass the star and end point and return the string with the moves 
		std::string CallMove(int xc, int yc, int enx, int eny);

		/*Calculated the h, and using the current g, calculate the f
		  of the fields adjacent  to the current xy (up, down, right, left)
		  Choose the small and fill a temporal string with the movement choose*/
		std::string Choosef();

		//loop and fill the string with the movements of the walking
		std::string FindPath();

		//Increase the G value when the xy are new
		bool ComeFrom(int cx, int cy);

		//Destructor
		~Grip(){}

		//variables and vectors
		int x, y, endx, endy, min, fup, fdown, fright, fleft;
		std::string mv;
		std::vector < std::vector<int> > visit_xy;
};

#endif //GRIP_H