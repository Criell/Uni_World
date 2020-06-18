//Version working (Not using nodes)


#include "Map.h"
#include "Grip.h"

Grip::Grip(const char* file) 
	: Map(file) {
}
			
		
std::string Grip::CallMove(int xc, int yc, int enx, int eny){
	
	/* Print the matrix 		
	for (int i = 0; i < map_y; i++){
		for (int j = 0; j < map_x; j++){
			std::cout <<vec_map[i][j] <<" ";
		}
		std::cout << std::endl;
	}
	*/

	// Fill xy of the start point and the gold point
	x = xc;
	y = yc;
	endx = enx, 
	endy = eny;

	//Return the string with the moves of the path that is print in the main
	std::string next; 
	next = FindPath();
    return next;
}

// 		
std::string Grip::Choosef(){
	int G = 0, H = 0;
	int rx=0, ry=0, dx=0, dy=0, lx=0, ly=0, ux=0, uy=0;
	int min = (map_x * map_y), fright = min, fdown = min, fup = min, fleft = min;

	//Calculated the find of the right field adjacent to the current xy
	//and store the new coordenates 
	if ((x < map_x-1) && (vec_map[y][x+1] == 0)){ 
		H = (abs((x+1)-endx)+abs(y-endy));
		G = (visit_xy.size());
		fright = H + G;
		rx = x+1; 
		ry = y;
		//std::cout << " HR" << H << " G"<< G << " xy: " << rx << ry << std::endl;
	}
	
	//Calculated the find of the down field adjacent to the current xy
	//and store the new coordenates				
	if ((y < map_y-1) && (vec_map[y+1][x] == 0)){
		H = (abs(x-endx)+abs((y-1)-endy));
		G = (visit_xy.size()); 
		fdown = H + G;
		dx = x;
		dy = y+1;
		//std::cout << " HD"<< H << " G"<< G << " xy: " << dx << dy << std::endl;
	}
	
	//Calculated the find of the up field adjacent to the current xy
	//and store the new coordenates		
	if ((y > 0) && (vec_map[y-1][x] == 0)){
		H = (abs(x-endx)+abs((y-1)-endy));
		G = (visit_xy.size());
		fup = H + G;
		ux = x;
		uy = y-1;
		//std::cout << " HU"<< H << " G"<< G << " xy: " << ux << uy << std::endl; 
	}
	
	//Calculated the find of the left field adjacent to the current xy
	//and store the new coordenates		
	if ((x > 0) && (vec_map[y][x-1] == 0)){
		H = (abs((x-1)-endx)+abs(y-endy));
		G = (visit_xy.size());
		fleft = H + G;
		lx = x-1;
		ly = y; 
		//std::cout << " HL"<< H << " G"<< G << " xy: " << lx << ly << std::endl;
	}
			
	std::string temp_mv;


	//Choose the small, call the inclusion of the xy select to the comeFrom vector 
	//incrementing the G and return a temporal string with the movement choose
	if (min > fright){ 
		min = fright; 
		temp_mv = "R";
		x = rx;
		y = ry;
		//std::cout << " Choose R: " << x << y<< std::endl; 
		bool old=ComeFrom(x,y);
	} 

	if (min > fdown){ 
		min = fdown; 
		temp_mv = "D";
		x = dx;
		y = dy;
		//std::cout << " Choose D: " << x << y<< std::endl;  
		bool old=ComeFrom(x,y);
	}
				
	if (min > fup){ 
		min = fup; 
		temp_mv = "U";
		x = ux;
		y = uy;
		//std::cout << " Choose U: " << x << y<< std::endl; 
		bool old=ComeFrom(x,y);
	}
				
	if (min > fleft ){ 
		min = fleft; 
		temp_mv = "L";
		x = lx;
		y = ly;
		//std::cout << " Choose L: " << x << y<< std::endl; 
		bool old=ComeFrom(x,y);
	} 
	
	return temp_mv;
}

bool Grip::ComeFrom(int currx, int curry){

	//Verify if the coordenates exists in the comeFrom vector
	//If it is true return
	for (int i = 0; i < visit_xy.size(); i++){ 
		if (visit_xy[i][0] == currx){ 
			if (visit_xy[i][1] == currx){ 
				return true;
			}
		}
	}	

	//Add to the comeFrom vector, and increase the G
	std::vector<int> temp;
	temp.push_back(x);
	temp.push_back(y);
	visit_xy.push_back(temp);
	//std::cout << "***ADD TO G "<<x<<y<<std::endl;
	return false;
}
		
std::string Grip::FindPath(){

	//return in start and and point are the same  
	if ((y == endy) && (x == endx)){ return "Same Begin and End";}

	//Check if the the start point dont have posible moves
	mv = ".";
	mv = Choosef();
	if (mv == "."){
		return "No path";
	}
	else{ mv = mv + " ";}

	
	//Tried to implement the while loop using the comparison
	//between the coordinates of start and end, but the program loop forever
	//couldn't determinate why.

	//while (x!=endx && y!= endy){

	//End using a for, and ending the looping when the conditions were meeet
	int n = map_x * map_y;
	for (int i=0; i < n; i++){
		if ((y == endy) && (x+1 == endx)){ return mv = mv + "R";}
		if ((y == endy) && (x-1 == endx)){ return mv = mv + "L";}
		if ((y+1 == endy) && (x == endx)){ return mv = mv + "D";}
		if ((y-1 == endy) && (x == endx)){ return mv = mv + "U";}
		if ((y == endy) && (x == endx)){ return mv;}
		
		// fill the string with the movements of the path
		std::string temp_mv = mv;
		mv = mv + Choosef() +" ";
	}	
	return mv;
}