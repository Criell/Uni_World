//Version working (Not using nodes)


#include "Grip.h"
#include "Map.h"


int main (int argc,char **argv){
	
	//Store the filename given as a argument into a variable
    const char * filename = argv[argc-5];

    //Store the start x and start y into int variables
    int bx = atoi(argv[argc-4]);
    int by = atoi(argv[argc-3]);

    //Store the end x and end y into int variables
    int ex = atoi(argv[argc-2]);
    int ey = atoi(argv[argc-1]);

    //Created a Grip element
    Grip pos(filename);

    //Call the function that return the string with the movements
    std::string path = pos.CallMove(bx, by, ex, ey);
    std::cout << path << std::endl;
}