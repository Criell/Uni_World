//Version working (Not using nodes)

#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <math.h> 
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include <sstream>


//Parent class that created the map
class Map
{
	public:

		//Constructor that take the file as parameter
		Map(const char* filename){
		    file = filename;
		    ReadFile();
		}
		
		// Read the file ans store in int variables the height and the wight
		int ReadFile(){
		    std::ifstream env(file);
		    if(!env) { return 1;}
		    
		    std::string temp;
		    getline(env, temp);
		    std::istringstream int_temp(temp);
		    int_temp >> map_x>> map_y;

		    //created a vector of vectors and fill it with the matrix of 0 and 1
		   	vec_map.resize(map_x, std::vector<int>(map_y, 1));

			for (int i = 0; i < map_y; i++){
				getline(env, temp);
		    	std::istringstream coord(temp);
				for (int j = 0; j < map_x; j++){
					coord >> vec_map[i][j];
				}
			}
		    return 0;
		}
		
		//Destructor
		~Map(){}
		
		//variables and vectors
		const char * file;
		int map_x;
		int map_y;
		std::vector < std::vector<int> > vec_map;
};	

#endif //MAP_H